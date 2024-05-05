require './application.rb'
app = Application.new
user1 = app.create_user('prawar')
user1.create_document('test1', 'my first test')
user1.fetch_all_doc
user1.update_notes('test1', 'update my first test')
user1.fetch_all_doc
user2 = app.create_user('mukati')
user2.fetch_all_doc
user1.grant_access('test1', user2, 'read')
