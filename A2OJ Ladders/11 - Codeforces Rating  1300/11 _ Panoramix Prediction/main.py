def isprime(x:int):
    for i in range(2, x):
        if x % i == 0:
            return False
    
    return True


def main():
    l = input().split(" ")
    n = int(l[0]) + 1
    m = int(l[1])
    
    if not isprime(m):
        return "NO"
    
    for i in range(n, m):
        if isprime(i):
            return "NO"
    
    return "YES"


print(main())
