require './doubly_linked_list.rb'

class LruCache
    
    attr_accessor :max_length, :curr_length, :cache_store, :dll

    def initialize(length)
        @max_length = length
        @curr_length = 0
        @cache_store = {}
        @dll = DoublyLinkedList.new
    end

    def get_key(key)
        unless cache_store[key]
            puts "key does not exists"
            return
        end

        dll.update_recently_used_key(cache_store[key])
        return cache_store[key].value
    end

    def set_key(key, value)
        if curr_length >= max_length
            tail_key = dll.remove_tail
            @cache_store.delete(tail_key) if tail_key
            node = dll.add_new_node(key, value)
            @cache_store[key] = node
        elsif
            node = dll.add_new_node(key, value)
            @curr_length += 1
            @cache_store[key] = node
        end
    end
end