for _ in range(int(input())):
    n = int(input())
    l = 1;
    r = 10**10;
    aux = 10**10
    while(l <= r):
        m = (l+r)//2
        if (m*(m-1))//2 >= n:
            aux = m
            r = m - 1
        else:
            l = m + 1
    if( (aux * (aux - 1)) // 2 > n):
        diff = n - ((aux-1)*(aux-2))//2
        print(aux-1+diff)
    else: 
        print(aux)

