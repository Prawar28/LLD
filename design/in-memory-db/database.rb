require './table.rb'

class Database

    attr_accessor :tables
    def initialize
        # table_name => table
        @tables = {}
    end

    def create_table(table_name, column_names)
        if @tables[table_name]
            puts "table already exists"
            return
        end

        table = Table.new(table_name, column_names)
        @tables[table_name] = table
    end

    def delete_table(table_name)
        if tables[table_name]
            tables.delete(table_name)
            puts "#{table_name} successfullly deleted"
        else
            puts "table does not exist"
        end
    end

    def insert_row(table_name, column_value_mapping)
        table = @tables[table_name]

        unless table
            puts "table does not exist"
            return
        end

        table.insert_row(column_value_mapping)
    end

    # to: do implment
    def find_schema_for_table(table_name)
        table = @tables[table_name]

        unless table
            puts "table does not exist"
            return
        end

        table.columns
    end

    def delete_row(table_name, row_id)
        table = @tables[table_name]

        unless table
            puts "table does not exist"
            return
        end

        table.delete_row(row_id)
    end

    def find_row(table_name, row_id)
        table = @tables[table_name]

        unless table
            puts "table does not exist"
            return
        end

        table.find_row_by_id(row_id)
    end

    def update_row(table_name, row_id, update_column_values)
        table = @tables[table_name]

        unless table
            puts "table does not exist"
            return
        end

        table.update_row(row_id, update_column_values)
    end

    def create_index(table_name, column_name)
        table = @tables[table_name]

        unless table
            puts "table does not exist"
            return
        end

        table.create_index(column_name)
    end
end