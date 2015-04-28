def describlePerson(person):
    print "Description of ", person['name']
    print "Age", person['age']
    try:
        print 'occupation ' + person['occupation'] 
    except:
        pass
person = {'name':'chenfan', 'age':23, 'occupation':'Student'}
describlePerson(person)

person2 = {'name':'chenfan2', 'age':223}
describlePerson(person2)
