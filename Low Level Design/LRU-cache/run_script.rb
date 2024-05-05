require './cache.rb'
cache = Cache.new(1)
cache.set_key(1,2)
cache.get_key(1)
cache.get_key(2)
cache.set_key(5, 'abc')
cache.get_key(2)
cache.get_key(5)