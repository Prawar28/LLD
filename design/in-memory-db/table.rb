require './index.rb'
require './row.rb'

class Table
    
    attr_accessor :columns, :rows, :row_counter, :indexes
    def initialize(table_name, columns) 
        @row_counter = 0
        @table_name = table_name
        @columns = columns
        @rows = []
        @indexes = { 'id' => Index.new('id') , 'name' => Index.new('name') }
    end

    # column_name => value
    def insert_row(column_value_mapping)
        @row_counter += 1

        row_values = {}
        # to:do column validation (extra | incorrect columns in input)
        columns.each do |column|
            row_values[column['name']] = column_value_mapping[column['name']] || column['default_value']
        end

        row_values['id'] = @row_counter
    
        row = Row.new(row_values)

        # to:do add to indexed tables if their exists - DONE
        @indexes.each do |_column, indexed_table|
            indexed_table.add_row(row)
        end

        @rows << row
        row
    end

    def update_row(row_id, updated_column_value_mapping)
        index_by_id = indexes['id']

        row = index_by_id.indexed_table[row_id].first

        row.update(updated_column_value_mapping)
    end

    def delete_row(row_id)
        row_to_be_deleted = nil
        @rows.each do |row|
            if row.find_by_column('id') == row_id
                @rows.delete(row)
                row_to_be_deleted = row
            end
        end

        @indexes.each do |column, indexed_table|
            indexed_table.indexed_table[row_to_be_deleted.find_by_column(column)].delete(row_to_be_deleted)
        end
    end

    def find_row_by_id(row_id)
        index_by_id = indexes['id']

        row = index_by_id.indexed_table[row_id].first
        row
    end

    def create_index(index_column)
        # TO:DO validate column too
        new_index = Index.new(index_column)
        @indexes[index_column] = new_index

        # populating index
        @rows.each do |row|
            new_index.add_row(row)
        end
    end
end