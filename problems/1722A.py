t = int(input())
c = sorted([*"Timur"])
for _ in range(t):
    a = input()
    b = sorted(list([*input()]))
    if c == b:
        print("YES")
    else:
        print("NO")