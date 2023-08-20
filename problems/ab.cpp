#include <bits/stdc++.h>
using namespace std;
vector<string> s(2);
int dfs(int i, int j, int li)
{
    if (s[!i][j] == 'B' and li == i)
        return dfs(!i, j, i) + 1;
    
    if (j < s[i].size() and s[i][j + 1] == 'B')
        return dfs(i, j + 1, i) + 1;
    
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cin >> s[0] >> s[1];
        int count = 0;
        for (auto row : s)
            for (auto c : row)
                if (c == 'B')
                    count++;
        int a = 0, b = 0;
        if (s[0][0] == 'B')
            a = dfs(0, 0, 0);
        if (s[1][0] == 'B')
            b = dfs(1, 0, 1);
        if (a == count or b == count)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}