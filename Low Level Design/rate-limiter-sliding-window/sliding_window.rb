require 'thread'

class SlidingWindow

    def initialize(window_frame, window_token_capacity)
        @window_frame = window_frame # in seconds
        @window_token_capacity = window_token_capacity
        @request_queue = []
    end

    def grant_access
        current_time = Time.now
        if @request_queue.size < @window_token_capacity
            @request_queue.unshift(current_time)
            return true
        end
        window_start_time = current_time - @window_frame
        while @request_queue.size > 0
            time = @request_queue[-1]
            if time > window_start_time
                break
            end
            @request_queue.pop
        end

        if @request_queue.size < @window_token_capacity
            @request_queue.unshift(current_time)
            return true
        end
        return false
    end
end