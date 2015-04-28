city = list('Beijing')
city [1:1] = 'Shanghai'
print city
print city [1:5]
print city [3]
city [3] = 'I'
print city
del city[1]
print city

city [1:8] =[]
print city

city.append(' shanghai')
print city

print city.count('i')

city [7:] = list('shanghai')
print city
city [7:] = []

country = list("haidian")

city.extend(country)
print city

cityS = city[:]
cityS.sort(reverse = True)
cityS.reverse()
print cityS
cityST = sorted(city)
print cityST

print city

citys = ['beijing', 'shanghai', 'xiann', 'nancha']
citys.sort(key = len)
print citys

