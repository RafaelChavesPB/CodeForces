for _ in range(int(input())):
    n = int(input())
    arr = [int(x) for x in input().split()]
    even = sum([x for x in arr if x % 2 == 0])
    odd = sum([x for x in arr if x % 2])
    print("YES" if even > odd else "NO")
