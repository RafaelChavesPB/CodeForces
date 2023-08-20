#include <bits/stdc++.h>
using namespace std;
string tostr(vector<int> &a)
{
    string b;
    for (auto it : a)
        b += char('0' + it);
    return b;
}

int diff(string &a, string &b)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            return i;
    }
    return a.size();
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        vector<string> searched(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
                arr[i][j]--;
            }
            vector<int> temp(m);
            for (int j = 0; j < m; j++)
                temp[arr[i][j]] = j;
            searched[i] = tostr(temp);
        }
        sort(searched.begin(), searched.end());
        for (auto it : arr)
        {
            auto ideal = tostr(it);
            int pos = lower_bound(searched.begin(), searched.end(), ideal) - searched.begin();
            int ans = 0;
            if (pos < n)
                ans = max(diff(ideal, searched[pos]), ans);
            if (pos > 0)
                ans = max(diff(ideal, searched[--pos]), ans);
            cout << ans << ' ';
        }
        cout << endl;
    }
}