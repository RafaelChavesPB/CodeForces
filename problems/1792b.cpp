#include <bits/stdc++.h>
using namespace std;
void solve()
{
    bool coin = false;
    int a, b, c, d, e, ans = 0;
    cin >> a >> b >> c >> d;
    if (a == 0){
        cout << 1 << endl;
        return;
    }
    ans += a + 2*min(b, c);
    e = abs(b - c);
    ans += min(a, e);
    if (a > e){
        a -= e;
        ans += min(a + 1, d);
    }else if (a < e){
        ans++;
    }
    else{
        ans += (d > 0);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}