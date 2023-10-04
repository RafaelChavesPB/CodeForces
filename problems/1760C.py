for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    b = sorted(a)
    for i in a:
        if i < b[-1]:
            print(i - b[-1], end=' ')
        else:
            print(i - b[-2], end=' ')
    print()