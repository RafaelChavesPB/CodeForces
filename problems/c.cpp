#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    long long fib[46] = {1, 1};
    for (int i = 2; i < 46; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    while (t--)
    {
        int n;
        long long x, y;
        bool flag = true;
        cin >> n >> x >> y;
        do{
            if(y + fib[n] <= fib[n+1]);
            else if (y > fib[n]){
                y -= fib[n];
            }else{
                flag = false;
                break;
            }
            swap(x, y);
        }while(--n);
        cout << (flag?"YES":"NO") << endl;
    }
}