x, y, z = 0, 0, 0
n=int(input())

for i in range(n):
    m=input()
    l=(m.split(' '))
    x+=int(l[0])
    y+=int(l[1])
    z+=int(l[2])

if x == 0 and y == 0 and z == 0 :
    print('YES')
else:
    print('NO')
