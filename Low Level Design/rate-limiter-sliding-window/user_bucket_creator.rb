require './sliding_window'

class UserBucketCreator < SlidingWindow
    # we can use user_id, ip-adress, name to identify uniq address
    def initialize
        @users_bucket = {}
    end

    def add_user_to_bucket(user_id)
        @users_bucket[user_id] = SlidingWindow.new(60, 5) unless @users_bucket[user_id]
    end

    def can_access(user_id)
        @users_bucket[user_id].grant_access
    end
end