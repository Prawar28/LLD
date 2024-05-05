require './database.rb'
db = Database.new

column_names = [{'name' => 'first_name'}, {'name' => 'age', 'default_value' => nil}]
db.create_table('user', column_names)

insert_values = { 'first_name' => 'prawar', 'age'  => '23'}
db.insert_row('user', insert_values)
db.find_row('user', 1)

db.update_row('user', {"first_name" => "prawar narang"})

column_names = [{'name' => 'name'}, {'name' => 'roll_number'}, {'name' => 'address'}]
db.create_table('student_data', column_names)

insert_values = { 'name' => "Gaurang", 'roll_number' => '123', 'address' => 'bangalore, whitefield'}

insert_values = { 'name' => "Prawar", 'roll_number' => '456', 'address' => 'indiranagar'}

column_names = [{'name' => 'company_name'}, {'name' => 'founded_in', 'default_value' => nil}]

db.create_table('company', column_names)