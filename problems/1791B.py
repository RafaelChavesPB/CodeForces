for _ in range(int(input())):
    n = int(input())
    s = input()
    x = 0
    y = 0
    mem = {}
    for c in s:
        if c == 'U':
            x += 1
        if c == 'D':
            x -= 1
        if c == 'L':
            y -= 1
        if c == 'R':
            y += 1
        mem[(x, y)] = 1
    print("YES" if (1,1) in mem else "NO")