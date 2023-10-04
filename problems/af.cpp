#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> l(51), r(51);
        int n, k;
        bool flag = false;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            l[a]++;
            r[b]++;
            if(a == k and b == k)
                flag = true;
        }
        if((l[k] > 0 and r[k] > 0) or flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}