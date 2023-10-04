#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool verify(vector<ll> &arr, ll c, int k, int  d)
{
    ll acc = 0;
    for (int i = 0; i < min(int(arr.size()), k + 1); i++)
    {
        ll times_used = (d - i - 1)/(k + 1) + 1;
        acc += times_used * arr[i];
    }
    return acc >= c;
}

void solve()
{
    int n, d;
    ll c;
    cin >> n >> c >> d;
    vector<ll> arr(n);
    for (auto &it : arr)
        cin >> it;
    sort(arr.begin(), arr.end(), greater<ll>());

    if (arr.front() * d < c)
    {
        cout << "Impossible\n";
    }
    else if (accumulate(arr.begin(), arr.begin() + min(d, n), ll(0)) >= c)
    {
        cout << "Infinity\n";
    }
    else
    {
        int r = d;
        int l = 0;
        int m;
        int ans = 0;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (verify(arr, c, m, d))
            {
                l = m + 1;
                ans = max(ans, m);
            }
            else
            {
                r = m - 1;
            }
        }
        cout << ans << '\n';
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