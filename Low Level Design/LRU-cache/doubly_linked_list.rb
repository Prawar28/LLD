require './node.rb'

class DoublyLinkedList
    attr_accessor :head, :tail, :length

    def initialize
        @head = nil
        @tail = nil
        @length = 0
    end

    def add_to_front(node)
        node.next = head
        node.prev = nil
        @head = node
    end

    def remove_tail
        tail_key = @tail.key if @tail

        @tail = @tail.prev
        @tail.next = nil if @tail

        tail_key
    end

    def update_recently_used_key(node)
        return if node == head

        prevNode = node.prev
        nextNode = node.next
        prevNode.next = nextNode
        nextNode.prev = prevNode
        add_to_front(node)
    end

    def add_new_node(key, value)
        node = Node.new(key, value)
        add_to_front(node)
        if !head || !tail
            @head = node
            @tail = node
        end
        node
    end
end