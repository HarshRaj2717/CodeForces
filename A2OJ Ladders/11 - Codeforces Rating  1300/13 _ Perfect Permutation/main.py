n = int(input())

if n%2 != 0:
    print(-1)
    quit()

for i in range(1, n+1, 2):
    print(i+1, i, end = " ")