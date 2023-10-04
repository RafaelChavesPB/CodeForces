#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n, q;
    ll h, w, uh, uw, lh, lw;
    cin >> n >> q;
    vector<vector<ll>> p(1001, vector<ll>(1001, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> h >> w;
        p[h][w] += h * w;
    }
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
        }
    }
    while (q--)
    {
        cin >> lh >> lw >> uh >> uw;
        uh--, uw--;
        cout << p[uh][uw] - p[lh][uw] - p[uh][lw] + p[lh][lw] << '\n';
    }
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