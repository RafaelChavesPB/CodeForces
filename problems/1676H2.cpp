#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> seg(1e6);

void build(int node, int l, int r)
{
    seg[node] = 0;
    if (l == r)
        return;
    int m = (l + r) / 2;
    build(2 * node, l, m);
    build(2 * node + 1, m + 1, r);
}

void update(int node, int l, int r, int value)
{
    if (value < l or r < value)
        return;
    seg[node]++;
    if (l == r)
        return;
    int m = (l + r) / 2;
    if (value <= m)
        update(2 * node, l, m, value);
    else
        update(2 * node + 1, m + 1, r, value);
}

int query(int node, int l, int r, int value)
{
    if (r < value)
        return 0;
    if (value <= l)
        return seg[node];
    int m = (l + r) / 2;
    return query(2 * node, l, m, value) + query(2 * node + 1, m + 1, r, value);
}

void solve()
{
    int n;
    cin >> n;
    build(1, 1, n);
    ll ans = 0;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    for (int i = 1; i <= n; i++)
    {
        ans += query(1, 1, n, arr[i]);
        update(1, 1, n, arr[i]);
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