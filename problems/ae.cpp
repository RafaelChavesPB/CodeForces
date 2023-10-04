#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        if ((n&1 and !(k&1)) or (n&1 and n < k)){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }
}