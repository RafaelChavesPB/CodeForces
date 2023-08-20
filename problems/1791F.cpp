#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> seg(5 * 200000);
vector<int> arr;

int sum(int num)
{
    int res = 0;
    while (num)
    {
        res += num % 10;
        num /= 10;
    }
    return res;
}

void build(int node, int l, int r)
{
    seg[node] = 0;
    if (l == r)
        return;
    int m = (l + r) / 2;
    build(2 * node, l, m);
    build(2 * node + 1, m + 1, r);
}

void update(int node, int l, int r, int ul, int ur)
{
    if (r < ul or ur < l)
        return;
    if (ul <= l and r <= ur)
    {
        seg[node]++;
        return;
    }
    int m = (l + r) / 2;
    update(2 * node, l, m, ul, ur);
    update(2 * node + 1, m + 1, r, ul, ur);
}

int query(int node, int l, int r, int pos)
{
    if (pos < l or r < pos)
        return 0;

    int count = seg[node];

    if (l == r)
        return count;

    int m = (l + r) / 2;

    if (pos <= m)
    {
        return count + query(2 * node, l, m, pos);
    }
    else
    {
        return count + query(2 * node + 1, m + 1, r, pos);
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    build(1, 1, n);
    arr.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    while (q--)
    {
        int o;
        int l, r;
        cin >> o;
        if (o == 2)
        {
            cin >> l;
            int op = query(1, 1, n, l);
            int curr = arr[l];
            while (op-- and curr >= 10)
            {
                curr = sum(curr);
            }
            cout << curr << '\n';
        }
        else
        {
            cin >> l >> r;
            update(1, 1, n, l, r);
        }
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