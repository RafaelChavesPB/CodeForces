T = int(input())
for t in range(T):
    n = int(input())
    arr = [int(x) for x in input().split()]
    total = sum(arr)
    maior = (0, 0)
    for it in range(len(arr)):
        maior = max((arr[it], it), maior)
    if (maior[0] > (total - maior[0])):
        print(maior[1] + 1)
    else:
        print(1)
