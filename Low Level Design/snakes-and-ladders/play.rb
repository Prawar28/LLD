require './game.rb'

class Play
    def initialize
        @game = Game.new
    end

    def start_game
        @game.play_game
    end
end