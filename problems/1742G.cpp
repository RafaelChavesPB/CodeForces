#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin >> n;
    vector<bool> used(n, 0);
    vector<int> arr(n), ans;
    for (auto &it : arr)
        cin >> it;
    int orTotal = 0;
    for (int i = 0; i < min(31, n); i++)
    {
        int curr = orTotal;
        pair<int, int> bst = {-1, -1};
        for (int j = 0; j < n; j++)
        {
            if (used[j] == 0)
            {
                auto temp = make_pair(curr | arr[j], j);
                bst = max(temp, bst);
            }
        }
        orTotal = bst.first;
        ans.push_back(arr[bst.second]);
        used[bst.second] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (used[i] == 0)
            ans.push_back(arr[i]);
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
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