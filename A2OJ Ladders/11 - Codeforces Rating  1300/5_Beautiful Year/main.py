def main():
    n = int(input())
    while True:
        n += 1
        for i in str(n):
            if str(n).count(i) > 1:
                break
        else:
            print(n)
            break


if __name__ == "__main__":
    main()
