require 'thread'

class LeakyBucket
    def initialize(capacity)
        @capacity = capacity
        @requests = SizedQueue.new(capacity) # thread-safe, blocking queues
    end

    def grant_access
        if @requests.size < @capacity
            @requests << 1
            return true
        end
        return false
    end

    def process_requests_at_fixed_rate
        loop do
            @requests.pop
            sleep(10)
        end
    end
end




# A sized queue is the same as a regular queue but with a size limit.
# When the queue is full, the push (same as <<) operation will suspend the current thread until an item is taken off the queue.
