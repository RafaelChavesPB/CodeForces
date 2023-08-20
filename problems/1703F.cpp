#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    vector<int> useful;
    vector<int> numbers(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> numbers[i];
        if (i > numbers[i])
        {
            useful.push_back(i);
            int curr = lower_bound(useful.begin(), useful.end(), numbers[i]) - useful.begin();
            ans += curr;
        }
    }
    cout << ans << '\n';
    ;
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