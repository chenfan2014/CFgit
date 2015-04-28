def hello(name):
    return 'Hello ' + name + '!'

print hello("Beijing")
print hello("Shanghai")


def flbs(num):
    result = [0, 1]
    for i in range(num - 2):
        result.append(result[-2] + result[-1])
    return result

print flbs(10)
print flbs(20)
