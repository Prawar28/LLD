require './document.rb'

class User
    
    attr_accessor :all_docs

    def initialize(user_name)
        @user_name = user_name
        @all_docs = {}
    end

    def create_document(name, content)
        doc = Document.new(name, content, self)
        all_docs[name] = doc
        doc
    end
    
    def grant_access(doc_name, user2, access)
        doc =  all_docs[doc_name]
        return unless doc

        doc.grant_access(user2, access, self)
        user2.all_docs[doc_name] = doc
    end

    def revoke_access(doc_name, user2, access)
        doc =  all_docs[doc_name]
        return unless doc

        doc.revoke_access(user2, access)
        user2.all_docs[doc_name] = nil
    end

    def fetch_all_doc
        all_docs
    end

    def delete_doc(doc_name)
        doc = all_docs[doc_name]
        doc.delete(self)
    end

    def update_notes(doc_name, content, new_name = nil)
        doc = all_docs[doc_name]
        doc.update(new_name || doc_name, content, self)
        if new_name
            all_docs[doc_name] = nil
            all_docs[new_name] = doc
            return
        end

        all_docs[doc_name] = doc
    end
end