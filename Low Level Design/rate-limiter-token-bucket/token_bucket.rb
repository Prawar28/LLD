require 'date'

class TokenBucket
    def initialize(refresh_rate, token_capacity)
        @token_capacity = token_capacity
        @refresh_rate = refresh_rate # in seconds
        @last_access_time = nil
        @tokens_available = token_capacity
    end

    def grant_access
        curr_time = Time.now

        if !@last_access_time
            @tokens_available -= 1
            @last_access_time = curr_time
            return true
        end

        elapsed_time = curr_time - @last_access_time
        refill_tokens = (elapsed_time * @refresh_rate).to_i
        @tokens_available = [ @token_capacity, refill_tokens + @tokens_available].min
        
        if @tokens_available > 0
            @tokens_available -= 1
            @last_access_time = curr_time
            return true 
        end
        @last_access_time = curr_time
        false
    end
end