#include <bits/stdc++.h>
using namespace std;

vector<int> adj;
vector<bool> leaf;
vector<int> ans;

void dfs(int idx, int last)
{
    ans[idx] = !last;
    if (adj[idx] == -1)
        leaf[idx] = false;
    else
        dfs(adj[idx], !last);
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n, flag = false, flag2 = true;
        cin >> n;
        vector<int> arr(n);
        adj.assign(n, -1);
        leaf.assign(n, true);
        ans.assign(n, 0);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> arr[i];
            if (i and arr[i] != arr[i - 1])
            {
                adj[i - 1] = i;
                leaf[i] = false;
            }
        }
        cin >> arr[n - 1];
        if (arr[0] != arr[n - 1])
        {
            adj[n - 1] = 0;
            leaf[0] = false;
        }
        if (arr[n - 1] != arr[n - 2])
        {
            adj[n - 2] = n - 1;
            leaf[n - 1] = false;
        }
        for (int i = 0; i < n; i++)
        {
            if (leaf[i])
            {
                dfs(i, 1);
                flag = true;
            }
            else
            {
                flag2 = false;
            }
        }
        if (flag)
        {
            cout << (flag2 ? 1 : 2) << endl;
            for (int i = 0; i < n; i++)
            {
                cout << ans[i] + 1 << ' ';
            }
            cout << '\n';
        }
        else
        {
            if (n & 1)
            {
                cout << 3 << endl;
                for (int i = 0; i < n - 1; i++)
                {
                    cout << i % 2 + 1 << ' ';
                }
                cout << 3 << endl;
            }
            else
            {
                cout << 2 << endl;
                for (int i = 0; i < n; i++)
                {
                    cout << i % 2 + 1 << ' ';
                }
                cout << endl;
            }
        }
    }
}