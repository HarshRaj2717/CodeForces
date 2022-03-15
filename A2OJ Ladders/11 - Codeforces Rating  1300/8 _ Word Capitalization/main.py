def main():
    s = input()
    for i in range(len(s)):
        if i == 0:
            print(s[i].upper(), end='')
        else:
            print(s[i], end='')


if __name__ == "__main__":
    main()
