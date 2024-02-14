class TicTacToe

    def initialize(n)
        @size = n
        @board = Array.new(n) { Array.new(n, -1) }
        @total_moves = 0
    end

    def mark_move(x, y, player_symbol)
        @board[x][y] = player_symbol
        @total_moves += 1
        is_win_move(x, y, player_symbol)
    end

    def is_win_move(x, y, symbol)

        vertical_flag = true
        horizontal_flag = true

        (0..(@size - 1)).each do |i|
            if @board[x][i] != symbol
                vertical_flag = false
            end
            if @board[i][y] != symbol
                horizontal_flag = false
            end
        end

        return true if vertical_flag || horizontal_flag

        left_diagonal = true
        right_diagonal = true
        if x == y || (x + y = (@size - 1))
            (0..(@size - 1)).each do |i|
                if @board[i][i] != symbol
                    left_diagonal = false
                end
                if @board[i][@size - 1 - i] != symbol
                    right_diagonal = false
                end
            end
        end

        return true if left_diagonal || right_diagonal
        return false
    end

    def print_board
        (0..(@size - 1)).each do |i|
            (0..(@size - 1)).each do |j|
                if j != (@size - 1)
                    print "#{@board[i][j]}"
                else
                    puts @board[i][j]
                end
            end
        end
    end

    def game_over
        @total_moves == @size * @size
    end
end