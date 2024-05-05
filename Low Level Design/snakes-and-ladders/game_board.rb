class GameBoard

    def initialize(size, snakes, ladders)
        @size = size
        @snakes = {}
        snakes.each do |pos|
            @snakes[pos[0]] = pos[1]
        end
        @ladders = {}
        ladders.each do |pos|
            @ladders[pos[0]] = pos[1]
        end
    end

    def move(current_pos, jumps)
        new_pos = current_pos + jumps
        if @snakes[new_pos]
            puts "Ate by Snake on #{new_pos}"
            return @snakes[new_pos] 
        end
        if @ladders[new_pos]
            puts "Found ladder on #{new_pos}"
            return @ladders[new_pos] 
        end
        new_pos
    end
end