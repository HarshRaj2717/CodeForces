n = int(input())
s = input()
sum = 0

for i in range(n-1):
    if s[i] == s[i+1]:
        sum += 1

print(sum)