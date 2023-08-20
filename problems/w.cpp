#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int lim = 1e7;
    vector<int> crivo(lim, -1);
    for (int i = 2; i < lim; i++)
        if (crivo[i] == -1)
            for (int j = 2*i; j < lim; j += i)
                crivo[j] = i;
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (__gcd(a, b) > 1)
        {
            cout << 0 << '\n';
            continue;
        }

        if (a & 1 and b & 1)
        {
            cout << 1 << '\n';
            continue;
        }

        if (a + 1 == b or a - 1 == b)
        {
            cout << -1 << '\n';
            continue;
        }
        int x = max(a,b), y = min(a,b);
        int h = x - y;
        int ans = h;
        while (crivo[h] != -1){
            ans = min(ans, h - a % crivo[h]);
            h /= crivo[h];
        }
        if(h > 1)
            ans = min(ans, h - a %h);
        cout << ans << '\n';
    }
}