x = 0
y = 0
for _ in range(3):
    x_, y_ = map(int, input().split())
    x ^= x_
    y ^= y_ 
print(x, y)

