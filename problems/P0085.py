h = int(input())
mod = 7907
a = h * (h + 1)
b = h * (h - 1) // 2 
print((a + b) % mod)
