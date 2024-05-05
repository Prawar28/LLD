require './lru_cache.rb'

class Cache

    attr_accessor :lru_cache

    def initialize(length)
        @lru_cache = LruCache.new(length)
    end

    def get_key(key)
        puts "value: #{lru_cache.get_key(key)}"
    end

    def set_key(key, value)
        lru_cache.set_key(key, value)
    end
end