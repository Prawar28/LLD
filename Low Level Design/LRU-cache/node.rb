class Node

    attr_accessor :key, :value, :next, :prev

    def initialize(key, value)
        @key = key
        @value = value
        @next = nil
        @prev = nil
    end

    def update_next(nextNode)
        @next = nextNode
    end

    def update_prev(prevNode)
        @prev = prevNode
    end
end