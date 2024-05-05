require './rate_limiter'

class Application < RateLimiter
    def initialize
        @users_buckets = UserBucketCreator.new
    end

    def try_access(id)
        @users_buckets.add_user_to_bucket(id)
        if @users_buckets.can_access(id)
            puts "Access success #{id}"
        else
            puts "Too Many Requests"
        end
    end
end