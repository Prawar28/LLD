class Document
    attr_accessor :owner, :name, :content

    def initialize(name, content, user)
        @name = name
        @content = content
        @owner = user
        @readers = {}
        @editors = {}
    end

    def grant_access(user, access, action_user)
        unless action_user == owner
            puts "you don't have access to update permission for this doc"
            return
        end

        case access
        when 'read'
            @readers[user] = true
        when 'edit'
            @editors[user] = true
        else
            puts "Invalid access type"
        end
    end

    def revoke_access(user, access)
        case access
        when 'read'
            @readers.delete(user)
        when 'edit'
            @editors.delete(user)
        else
            puts "Invalid access type"
        end
    end

    # ruby does not have inbuild delete function, we could make refrence to it nil or we could delete the content
    def delete(user)
        return unless owner == user

        name = 'doc deleted'
        content = 'content deleted'
    end

    def update(new_name, new_content, user)
        unless user == owner || @editors[user]
            puts "You don't have Edit access"
            return
        end

        @name = new_name
        @content = new_content
    end
end