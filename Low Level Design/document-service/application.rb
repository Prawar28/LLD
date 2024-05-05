require './user.rb'

# name could be documentService
# remember:
# 1. no need to make relation since, there is no DB
# 2. use maps instead of array for order 1 access
# 3. store occurences of objects in a map or array
class Application
    def initialize
        @user_list = {}
    end

    def create_user(user_name)
        if @user_list[user_name]
            puts "user_name already exists"
            return
        end

        user = User.new(user_name)
        @user_list[user_name] = user
    end

    def find_user(user_name)
        unless @user_list[user_name]
            puts "User does not exist"
            return
        end

        return @user_list[user_name]
    end
end