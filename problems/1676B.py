for _ in range(int(input())):
    n = int(input())
    arr = [int(x) for x in input().split()]
    print(sum(arr)-n*min(arr))