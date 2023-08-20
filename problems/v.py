T = int(input())
for t in range(T):
    a = input()
    b = input()
    if a == b:
        print("YES")
        print(a)
    elif a[0] == b[0]:
        print("YES")
        print(a[0]+'*')
    elif a[-1] == b[-1]:
        print("YES")
        print('*'+a[-1])
    else:
        flag = False
        for i in range(0, len(a)-1):
            pair = a[i:i+2]
            if pair in b:
                flag = True
                print("YES")
                print('*'+pair+'*')
                break
        if not flag:
            print("NO")
