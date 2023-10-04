def xor_total(arr):
    xor = 0
    for i in arr:
        xor ^= i
    return xor
n, = [int(x) for x in input().split()]
arr = [int(x) for x in input().split()]
sum_total = 0
for i in range(0, n):
    for j in range(i, n):
        new_arr = arr[i:j+1]
        sum_total += xor_total(new_arr)
mod = 998244353
print(sum_total % mod)

