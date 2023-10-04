#include <bits/stdc++.h>
using namespace std;

pair<int, int> best(int ai, int s)
{
    pair<int, int> dual;
    if (s > ai)
    {
        dual = {ai - 1, 1};
    }
    else
    {
        int h = ai - s;
        dual = {max(h, s), min(h, s)};
    }
    return dual;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, s, a1, an, a;
        cin >> n >> s;
        vector<pair<int, int>> duals(n + 1);
        cin >> a1;
        for (int i = 2; i < n; i++)
        {
            cin >> a;
            duals[i] = best(a, s);
        }
        cin >> an;

        long long ans = LONG_LONG_MAX;
        for (int i = 0; i < 2; i++)
        {
            long long acc = a1 * 1ll * duals[2].first + an * 1ll * duals[n - 1].second;
            for (int j = 3; j < n; j++)
            {
                acc += duals[j].first * 1ll * duals[j - 1].second;
                swap(duals[j - 1].first, duals[j - 1].second);
            }
            swap(duals[n - 1].first, duals[n - 1].second);
            ans = min(ans, acc);
            cout << ans << ' ';
        }
        cout << '\n';
    }
}