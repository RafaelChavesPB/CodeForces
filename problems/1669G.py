for _ in range(int(input())):
    R, C = [int(x) for x in input().split()]
    grid = [ list(input()) for x in range(R)]
    for c in range(C):
        stones = 0
        last = 0
        for r in range(R):
            if grid[r][c] == 'o':
                for i in range(r-stones, r):
                    grid[i][c] = '*'
                last = r
                stones = 0
            else:
                stones += (grid[r][c] == '*')
                grid[r][c] = '.'
        for i in range(R-stones, R):
            grid[i][c] = '*'
    for r in grid:
        print(*r,sep='')
