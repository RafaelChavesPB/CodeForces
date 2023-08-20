#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        vector<int> memory(26 * 26, -1);
        bool flag = false;
        for (int i = 1; i < n; i++)
        {
            int hash = 26 * (s[i - 1] - 'a') + (s[i] - 'a');
            if (memory[hash] == -1)
                memory[hash] = i;
            else if (memory[hash] < i - 1)
            {
                flag = true;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
}