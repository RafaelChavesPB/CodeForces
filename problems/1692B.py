for _ in range(int(input())):
    n = int(input())
    arr = [int(x) for x in input().split()]
    mem = set()
    duplicates = 0
    for i in arr:
        if i in mem:
            duplicates += 1
        else:
            mem.add(i)
    print(len(arr)-duplicates-(duplicates % 2))
