#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, aux;
        cin >> n >> m;
        map<int, vector<pair<int, int>>> usefull;
        vector<int> array(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> array[i];
            usefull[array[i]].push_back({0, m});
        }
        for (int i = 1, p, v, sz; i <= m; i++)
        {
            cin >> p >> v;
            if (array[p] == v)
                continue;
            sz = usefull[array[p]].size();
            usefull[array[p]][sz - 1].second = i - 1;
            array[p] = v;
            usefull[v].push_back({i, m});
        }
        long long ans = 0;
        for (auto it : usefull)
        {
            long long d = 0;
            for (auto p : it.second)
                d += (p.second - p.first) + 1;
            long long f = m - d + 1;
            ans += d * f + (d * (d - 1)) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}