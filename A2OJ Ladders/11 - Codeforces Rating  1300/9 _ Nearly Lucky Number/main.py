def main():
    s = input()
    if s.count('4') + s.count('7') in [4, 7]:
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    main()
