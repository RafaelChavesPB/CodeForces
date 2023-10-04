for _ in range(int(input())):
    n = int(input())
    pos = [int(x) for x in input().split()]
    for i  in range(n):
        a, moves = input().split()
        for move in moves:
            if move == 'D':
                pos[i] = (pos[i] + 1)%10
            else:
                pos[i] = (pos[i] - 1)%10
    print(*pos)
