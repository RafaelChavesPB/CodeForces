for _ in range(int(input())):
    arr = [int(x) for x in input().split()]
    value = 0
    for i in arr:
        value^=i
    print(value)
