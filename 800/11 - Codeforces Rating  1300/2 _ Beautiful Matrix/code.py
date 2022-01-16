r1 = input().split(" ")
r2 = input().split(" ")
r3 = input().split(" ")
r4 = input().split(" ")
r5 = input().split(" ")
x = 0
y = 0
for i in [r1, r2, r3, r4, r5]:
    y += 1

    if '1' in i:
        for i in [r1, r2, r3, r4, r5][y-1]:
            x += 1
            if i == '1':
                if x < 3:
                    x = 3-x
                else:
                    x = x-3

                if y < 3:
                    y = 3-y
                else:
                    y = y-3

                print(x+y)