require 'csv'

class MySelectQuery
    @csv_string = []  
    def initialize(csv) 
        @csv_string = csv 
    end

    def where(column_name, criteria)
        new_array = Array.new
        lines = @csv_string.split("\n")
        headers = lines[0].split(',')

        column_name_index = headers.index(column_name)
        for line in lines do 
            a = line.parse_csv[column_name_index]

            if (a == criteria)
                new_array.push(line)
            end
        end
        return new_array
    end
end