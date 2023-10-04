#include <bits/stdc++.h>
using namespace std;

int gcdExtended(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

int modInverse(int A, int M)
{
    int x, y;
    int g = gcdExtended(A, M, x, y);
    return (x % M + M) % M;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long mod = 998244353;
    int n, tri;
    cin >> n;
    tri = n / 3;
    vector<int> arr(n);
    vector<int> pd(n, 0);
    long long den = 1, num = 1;
    for (long long i = 1; i <= tri; i++)
    {
        if (i <= tri / 2)
        {
            den *= i;
            den %= mod;
        }
        else
        {
            num *= i;
            num %= mod;
        }
    }
    long long ans = (num * modInverse(den, mod)) % mod;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i += 3)
    {
        long long op = 0;
        sort(arr.begin() + i, arr.begin() + i + 3);
        if (arr[i] == arr[i + 2])
            op = 3;
        else if (arr[i] == arr[i + 1])
            op = 2;
        else
            op = 1;
        ans *= op;
        ans %= mod;
    }
    cout << ans << '\n';
}