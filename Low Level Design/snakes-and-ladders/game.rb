require './game_board.rb'
require './player.rb'

class Game

    def initialize
        puts "Enter Number Of Player:"
        n = gets.chomp.to_i
        @players = Array.new(n) { Player.new }

        puts "Board Size:"
        @size = gets.chomp.to_i

        puts "Number of Dice:"
        @dices = gets.chomp.to_i

        puts "Enter Number of Snakes:"
        snakes_number = gets.chomp.to_i
        snakes = []
        snakes_number.times do
            puts "Snake Start Position:"
            s = gets.chomp.to_i
            puts "Snake End Position:"
            e = gets.chomp.to_i
            snakes << [s, e]
        end

        puts "Enter Number of ladders:"
        ladders_number = gets.chomp.to_i
        ladders = []
        ladders_number.times do
            puts "ladder Start Position:"
            s = gets.chomp.to_i
            puts "ladder End Position:"
            e = gets.chomp.to_i
            ladders << [s, e]
        end

        @game_board = GameBoard.new(@size, snakes, ladders)
        @game_over = false
    end

    def roll_dice
        random_numbers = (1..@dices).map { rand(1..6) }
        random_numbers.sum
    end

    def take_chance(player_i)
        
        total_jumps = roll_dice

        current_player = @players[player_i]
        new_pos = @game_board.move(current_player.position, total_jumps)

        puts "Player #{player_i + 1} moved from #{current_player.position} to #{new_pos}"
        current_player.update_position(new_pos)

        return game_won(player_i, new_pos)
    end

    def game_won(player_i, pos)
        if pos >= @size
            puts "Game Won By: #{player_i + 1}"
            @game_over = true
            return true
        end
        false
    end

    def play_game
        turn = 0
        while !@game_over
            puts "Player #{turn + 1} chance: press enter to continue"
            gets.chomp
            take_chance(turn)
            turn = (turn + 1) % @players.size
        end

        puts "Game Over"
    end
end