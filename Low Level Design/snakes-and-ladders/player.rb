class Player 
    attr_reader :position

    def initialize
        @position = 0
    end

    def update_position(new_pos)
        @position = new_pos
    end
end