x = input().split()
n = int(x[0])
t = int(x[1])
xx = input()
s = []
for i in xx:
    s += i
ss = s.copy()
for i in range(t):
    s = ss.copy()
    for j in range(n-1):
        if s[j] == 'B' and s[j + 1] == 'G':
            ss[j], ss[j + 1] = s[j + 1], s[j]

ss = ''.join(ss)

print(ss)
