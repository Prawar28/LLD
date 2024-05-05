class Index

    attr_accessor :indexed_table
    def initialize(column_name)
        @column_name = column_name
        @indexed_table = {}
    end

    def add_row(row)
        return unless row.find_by_column(@column_name)

        if @indexed_table[row.find_by_column(@column_name)]
            @indexed_table[row.find_by_column(@column_name)] << row
        else
            @indexed_table[row.find_by_column(@column_name)] = [row]
        end
    end
end