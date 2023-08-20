#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> suffix1(n + 1, 0), prefix0(n + 1, 0), z(n + 1);
    map<int, int> dp;
    cout << s << endl;

    for (int i = 0; i < n; i++)
    {
        prefix0[i + 1] = prefix0[i];
        if (s[i] == '0')
            prefix0[i + 1]++;
    }

    for (int r = n - 1; r >= 0; r--)
    {
        suffix1[r] = suffix1[r + 1];
        if (s[r] == '1')
            suffix1[r]++;
    }

    int ans = INT_MAX;
    for(int i = 0; i <= n; i++){
        dp[prefix0[i] - suffix1[i]] = i;
        z[i] = prefix0[i] - suffix1[i];
        ans = min(ans, max(prefix0[i], suffix1[i]));
    }

    for (auto it : prefix0)
    {
        cout << it << ' ';
    }
    cout << endl;

    for (auto it : suffix1)
    {
        cout << it << ' ';
    }
    cout << endl;
    for (auto it : z)
    {
        cout << it << ' ';
    }
    cout << endl;

    int zeros = 0;
    int ones = 0;
    for(int i = 0; i <= n; i++){
        if(s[i] == '0'){
            zeros++;
        }else{
            ones++;
        }
        int x = ones - zeros;
        if(dp.find(x) != dp.end()){
            int pos = dp[i];
            if(i < pos){
                ans = min(ans, max(prefix0[pos] - zeros, suffix1[pos] + ones));
            }
        }
        cout << x << ' ';
    }
    cout << endl;
    cout << ans << endl;
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