def main():
    ss = input()
    s = []
    for i in ss:
        s += i

    n = []
    pointer = 0
    while pointer < len(s):
        if s[pointer] == ".":
            n.append(0)
            pointer += 1
        elif s[pointer] == "-":
            pointer += 1
            if s[pointer] == ".":
                n.append(1)
                pointer += 1
            elif s[pointer] == "-":
                n.append(2)
                pointer += 1

    for i in n:
        print(i, end="")


if __name__ == "__main__":
    main()
