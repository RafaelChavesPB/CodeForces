t = int(input())
for T in range(t):
    n = int(input())
    xora = 0
    xorb = 0
    ans = [2*i for i in range(n-2)]
    ans[0] = 1
    for i in range(n-2):
        if i & 1:
            xorb ^= ans[i]
        else:
            xora ^= ans[i]
    ans += [xora + (1 << 29), xorb + (1 << 29)]
    print(*ans)    
        
    
             
    