def main():
    s = input()
    upper = 0
    lower = 0

    for i in s:
        if i.islower():
            lower += 1
        else:
            upper += 1

    if upper > lower:
        print(s.upper())
    else:
        print(s.lower())


if __name__ == "__main__":
    main()
