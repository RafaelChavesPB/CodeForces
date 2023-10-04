#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
long long ans, k, c;

int dfs(int u, int dad, int rd)
{
    int a = rd, b = -1;
    for (auto v : adj[u])
    {
        if (v != dad)
        {
            int vd = dfs(v, u, rd + 1);
            if (vd > a)
            {
                b = a;
                a = vd;
            }
            else if (vd > b)
            {
                b = vd;
            }
        }
    }

    ans = max(k * a, ans);
    if (b != -1)
    {
        int d1 = max(a - rd, b - rd);
        int d2 = min(a - rd, b - rd);
        long long curr = k * (d1 + d2) - (d2 + rd) * c;
        ans = max(ans, curr);
    }

    return a;
}

void solve()
{
    int n;
    ans = 0;
    cin >> n >> k >> c;
    adj.assign(n + 1, vector<int>());
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);
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