#include <bits/stdc++.h>
using namespace std;

typedef struct Var
{
    long long gcd = 0;
    long long lcm = 1;
} var;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, ans = 1;
        cin >> n;
        long long a, b;
        var curr;
        for (long long i = 0; i < n; i++)
        {
            cin >> a >> b;
            long long c = 1ll *a * b;
            long long gcd = __gcd(curr.gcd, c);
            long long lcm = (curr.lcm * b) / __gcd(curr.lcm, b);
            if (gcd % lcm == 0)
            {
                curr.gcd = gcd;
                curr.lcm = lcm;
            }
            else
            {
                curr.gcd = c;
                curr.lcm = b;
                ans++;
            }
        }
        cout << ans << "\n";
    }
}