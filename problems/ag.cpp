    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    void solve()
    {
        int n;
        string s;
        cin >> n >> s;
        vector<int> arr(n + 1), prefix(n + 1), suffix(n + 1);
        for (int i = 1; i <= n; i++)
        {
            arr[i] = 1 << (s[i - 1] - 'a');
            prefix[i] = arr[i] | prefix[i - 1];
        }
        for (int r = n; r > 0; r--)
            suffix[r - 1] = arr[r] | suffix[r];
        int bst = 0;
        for (int i = 1; i < n; i++)
        {
            bst = max(bst, __builtin_popcount(prefix[i]) + __builtin_popcount(suffix[i]));
        }
        cout << bst << '\n';
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