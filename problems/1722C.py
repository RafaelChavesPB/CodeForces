def pont(i):
    if i == 1:
        return 3
    if i == 2:
        return 1
    return 0

for _ in range(int(input())):
    n = int(input())
    p = [0, 0, 0]
    words = {}
    for i in range(3):
        for w in input().split():
            if w in words:
                words[w].append(i)
            else:
                words[w] = [i]
    for w in words:
        wp = pont(len(words[w]))
        for person in words[w]:
            p[person] += wp
    print(*p)
