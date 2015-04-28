import sys, shelve
def storePerson(db):
    pid = raw_input("Enter unique ID number")
    person = {}
    person['name'] = raw_input("Enter the name")
    person['age'] = raw_input("Enter the age")
    person['phone'] = raw_input("Enter the phoneNumber")

    db[pid] = person

def lookupPerson(db):
    pid = raw_input("Enter ID number to search")
    field = raw_input("What would you like to know ?[name, age, phonenumber] ")
    field = field.strip().lower()
    print field.capitalize() + ' : ', db[pid][field]

def printHelp():
    print "The available command are"
    print "store : Store Information"
    print "search : Look up a person from ID "
    print "quit : and Save the change"
    print "? Print this message"

def enterCommend():
    cmd = raw_input("Enter command : ")
    cmd = cmd.strip().lower()
    return cmd

def main():
    database = shelve.open("data.dat")
    try:
        while True:
            cmd = enterCommend()
            if cmd == 'store':
                storePerson(database)
            elif cmd == 'search':
                lookupPerson(database)
            elif cmd == "?":
                printHelp()
            elif cmd == 'quit':
                return
    finally:
        database.close()
if __name__ == '__main__':main()

