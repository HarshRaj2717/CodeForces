n = int(input())
l = list(input().split())

for i in range(n):
    l[i] = int(l[i])

m = l.index(max(l))
count = 0

for i in range(m, 0, -1):
    l[i], l[i-1] = l[i-1], l[i]
    count += 1

l.reverse()
m = l.index(min(l))


for i in range(m):
    l[i], l[i-1] = l[i-1], l[i]
    count += 1

print(count)