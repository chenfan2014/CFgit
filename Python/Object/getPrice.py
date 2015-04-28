def getPrice(object):
    if isinstance(object, tuple):
        return object[1]
    elif isinstance(object, dict):
        return int(object[1])
    else:
        return "Last one"

print object.getPrice()
