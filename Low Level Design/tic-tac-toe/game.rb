require './player.rb'
require './tic_tac_toe.rb' 

class Game
    def initialize(n)
        @tic_tac_toe = TicTacToe.new(n)
        @players = [Player.new('x'), Player.new('0')]
        puts "Player 1 is x"
        puts "Player 2 is 0"
    end

    def start_game

        turn = 0
        while !@tic_tac_toe.game_over
            moves = get_user_move()
            if @tic_tac_toe.mark_move(moves[0], moves[1], @players[turn].player_symbol)
                puts "Player #{turn + 1} won"
                break 
            end
            @tic_tac_toe.print_board
            turn = (turn + 1) % 2
        end
    end

    def get_user_move
        puts "Enter x for the move:"
        x = gets.chomp.to_i
        puts "Enter y for the move:"
        y = gets.chomp.to_i

        return x,y
    end
end