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
        long long l, r, ans = 0;
        cin >> l >> r;
        long long n = 0, temp = l;
        while (temp <= r)
        {
            temp *= 2;
            n++;
        }
        cout << n-- << ' ';
        ans = r / (1 << n) - l + 1;
        if (n and (l << (n - 1)) * 3 <= r)
        {
            long long f = r / ((1 << (n - 1)) * 3);
            ans += (f - l + 1) * (n);
        }
        cout << ans << endl;
    }
}