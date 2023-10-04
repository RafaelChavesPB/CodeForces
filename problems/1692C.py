def inGrid(i, j):
    return  0 <= i and i < 8 and  0 <= j and j < 8

def solve():
    input()
    grid = [input() for x in range(8)]
    for i in range(8):
        for j in range(8):
            if grid[i][j] == '#':
                for d in [-1,1]:
                    a = i + d
                    b = j - 1
                    c = j + 1
                    if inGrid(a, b) and inGrid(a, c):
                        if grid[a][b] =='#' and grid[a][c] == '#':
                            print(i+1, j+1)
                            return
                    a = i + 1
                    b = i - 1
                    c = j + d
                    if inGrid(a, c) and inGrid(b, c):
                        if grid[a][c] =='#' and grid[b][c] == '#':
                            print(i+1, j+1)
                            return

for _ in range(int(input())):
    solve()
