def sum_digits(num):
    return sum(map(int, str(num)))

mem = [0 for i in range(10)]
for k in range(0, 1000):
    value = sum_digits(k)
    if value < 10:
        mem[value] += 1
for _ in range(int(input())):
    answer = 1
    for digit in map(int, input()):
        answer *= mem[digit]
    print(answer)

