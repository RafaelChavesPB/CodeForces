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
        int n, count = 0;
        string a, b;
        cin >> n >> n >> a >> b;
        reverse(b.begin(), b.end());
        a += b;
        char last = a[0];
        for (int i = 1; i < a.size(); i++)
        {
            if (last == a[i])
                count++;
            last = a[i];
        }
        if (count > 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}