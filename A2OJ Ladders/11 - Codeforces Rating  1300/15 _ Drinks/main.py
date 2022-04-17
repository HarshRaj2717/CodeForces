n = int(input())
l = list(map(int, input().split(" ")))
x = 0

for i in l:
    x += i

print(x / n)
