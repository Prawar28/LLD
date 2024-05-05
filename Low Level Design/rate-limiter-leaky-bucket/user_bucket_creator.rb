require './leaky_bucket'

class UserBucketCreator < LeakyBucket
    # we can use user_id, ip-adress, name to identify uniq address
    def initialize
        @users_bucket = {}
    end

    def add_user_to_bucket(user_id)
        @users_bucket[user_id] = LeakyBucket.new(2) unless @users_bucket[user_id]
    end

    def can_access(user_id)
        @users_bucket[user_id].grant_access
    end
end