def switch(initial, times):
    if int(times) % 2 != 0:
        if initial == '1':
            return '0'
        else:
            return '1'

    return initial


def main():
    list1 = list(['0']*5 for _ in range(5))
    list2 = list(['1']*5 for _ in range(5))
    for i in range(1, 4):
        input_text = list(input().split())
        list1[i] = ['0'] + input_text + ['0']

    for i in range(1, 4):
        for j in range(1, 4):
            for (c,d) in (1, 0), (0, 1), (-1, 0), (0, -1), (0, 0):
                list2[i+c][j+d] = switch(list2[i+c][j+d], list1[i][j])

    for i in list2[1:4]:
        for j in i[1:4]:
            print(j, end='')
        print()


if __name__ == "__main__":
    main()
