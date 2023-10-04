t = int(input())
for _ in range(t):
    arr = [int(x) for x in input()]
    if sum(arr[:3]) == sum(arr[3:]):
        print("YES")
    else:
        print("NO")
