#include <bits/stdc++.h>
using namespace std;
vector<int> comp;
void dfs(int i, int k, int cor)
{
    if (i >= 0 and i < comp.size() and comp[i] == -1)
    {
        comp[i] = cor;
        dfs(i + k, k, cor);
        dfs(i + k + 1, k, cor);
        dfs(i - k, k, cor);
        dfs(i - k - 1, k, cor);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, q_comp = 0;
        string a, b;
        cin >> n >> k >> a >> b;
        comp.assign(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (comp[i] == -1)
            {
                dfs(i, k, q_comp);
                q_comp++;
            }
        }
        vector<string> strA(q_comp), strB(q_comp);
        for (int i = 0; i < n; i++)
        {
            strA[comp[i]] += a[i];
            strB[comp[i]] += b[i];
        }
        bool flag = true;
        for (int i = 0; i < q_comp; i++)
        {
            sort(strA[i].begin(), strA[i].end());
            sort(strB[i].begin(), strB[i].end());
            if (strA[i] != strB[i])
            {
                flag = false;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}