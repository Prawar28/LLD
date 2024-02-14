load './application.rb'

application = Application.new

(1..5).each do |i|
    application.try_access(1)
end