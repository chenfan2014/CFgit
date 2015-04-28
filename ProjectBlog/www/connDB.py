from transwarp import db
db.create_engine(user = 'root', password = '128128', database = 'test', host = '127.0.0.1', port = 3306)

users = db.select ('select * from user')

n = db.update('insert into user(id, name) values (?, ?)', 3, 'jack')

update(sql, *args)


