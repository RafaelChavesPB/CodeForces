#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n, ans = 0;
    string s;
    cin >> n;
    vector<int> arr(n + 1);
    vector<int> pd(n + 1, 0);

    for (int i = 2; i <= n; i++)
        cin >> arr[i];
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'W')
            pd[i + 1] = -1;
        else
            pd[i + 1] = 1;
    }
    for (int r = n; r > 0; r--)
    {
        if (pd[r] == 0)
            ans++;
        pd[arr[r]] += pd[r];
    }
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