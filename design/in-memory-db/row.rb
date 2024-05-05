class Row
    def initialize(column_value)
        @values = column_value
    end

    def find_by_column(column_name)
        return @values[column_name]
    end

    def update(column_values)
        column_values.each do |key, value|
            @values[key] = value
        end
    end
end