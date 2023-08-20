from math import gcd
a, b = map(int, input().split())
count = 0
while(gcd(a,b) == 1):
    a += 1
    b += 1
    count += 1
print(a, b, count, gcd(a, b))