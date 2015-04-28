width = input("Please input a width : ")

price_width = 10
item_width = width - price_width

header_formate = '%-*s%*s'
formate = '%-*s%*d'

print '=' * width

print header_formate % (item_width, 'Item', price_width, 'Price')

print '-' * width

print formate % (item_width, 'Apple', price_width, 1)
print formate % (item_width, 'Orange', price_width, 2)
print formate % (item_width, 'Dried', price_width, 3)
print formate % (item_width, 'Banana', price_width, 4)
print formate % (item_width, 'Milk', price_width, 5)

print '=' * width
