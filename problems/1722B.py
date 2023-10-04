for _ in range(int(input())):
    n = int(input())
    s1 = input()
    s2 = input()
    print("YES "if s1.replace('G', 'B', len(s1)) == s2.replace('G', 'B', len(s2)) else "NO")