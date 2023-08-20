for _ in range(int(input())):
    count = 0
    input()
    for i in range(8):
        s = input()
        if 'R' in s:
            if 'B' not in s:
                count += 1
    print("R" if count else "B")
