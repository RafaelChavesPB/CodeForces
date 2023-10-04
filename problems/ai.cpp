#include <bits/stdc++.h>
using namespace std;
int mod = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int maior = *max_element(arr.begin(), arr.end());
    int a = count(arr.begin(), arr.end(), maior);
    int b = count(arr.begin(), arr.end(), maior - 1);
    long long ans = 1, sub = 1;
    for (long long i = 1; i <= n; i++)
    {
        ans = (ans * i % mod);
        if (i == b + 1)
            continue;
        sub = (sub * i % mod);
    }
    if (a == 1)
        cout << (ans - sub + mod) % mod << '\n';
    else 
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