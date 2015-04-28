dic = {'x':1, 'y':2, 'z':3}
for key in dic:
    print key, "The value is", dic[key]

for keys, value in dic.items():
    print keys ," ",value



names = ['chenfan', 'lilin', 'zhangsan', 'lisi']
ages = [12, 23, 34, 56]
for i in range(len(names)):
    print names[i], ages[i]



stringsOne = ['beijing', 'shanghai', 'guangzhou', 'shenzhen']
for strOne in stringsOne:
    if 'an' in strOne:
        index = stringsOne.index(strOne)
        print index
        stringsOne[index] = "Change"
for strOne in stringsOne:
    print strOne


i = 0
for strTwo in stringsOne:
    if 'an' in strTwo:
        stringsOne[i] = "changeAgain"
    i += 1
for strTwo in stringsOne:
    print strTwo
