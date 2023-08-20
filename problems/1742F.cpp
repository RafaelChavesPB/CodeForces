#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int q, op, k;
    cin >> q;
    string x;
    ll t = 1, s = 1;
    bool only_a_t = true, only_a_s = true;
    while (q--)
    {
        cin >> op >> k >> x;

        ll count = 0;
        for (auto c : x)
            count += (c == 'a');

        if (op == 2)
        {
            only_a_t &= (count == x.size());
            t += k * count;
        }
        else
        {
            only_a_s &= (count == x.size());
            s += k * count;
        }

        if (only_a_s and only_a_t)
        {
            if (s < t)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else if (only_a_t)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
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