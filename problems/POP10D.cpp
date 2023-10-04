#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<ll>> pd;

ll rec(int num, int mask, int faces, int s)
{
    if (num == s)
        return faces == mask;

    if (num > s)
        return 0;

    if (pd[num][mask] != -1)
        return pd[num][mask];

    pd[num][mask] = 0;
    for (int i = 1; i <= 6; i++)
        if (faces & (1 << i))
            pd[num][mask] += rec(num + i, mask | (1 << i), faces, s);
    pd[num][mask] = min(ll(1e10), pd[num][mask]);
    return pd[num][mask];
}

void solve()
{
    int n, s, faces = 0;
    cin >> n >> s;
    pd.assign(s + 1, vector<ll>((1 << 7), -1));
    for (int i = 0, aux; i < n; i++)
    {
        cin >> aux;
        faces |= (1 << aux);
    }
    ll ans = rec(0, 0, faces, s);
    if (ans >= 1e9)
        cout << "INF\n";
    else
        cout << ans << '\n';
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