#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_set<int> mem;
        queue<int> fila;
        bool flag = true;
        mem.insert(1);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        if(a[0] != 1){
            cout << "NO" << endl;
            continue;
        }
        for (int i = 1; i < n; i++)
        {
            if (mem.find(a[i]) == mem.end())
            {
                flag = false;
                break;
            }

            for (auto it : mem)
                fila.push(a[i] + it);

            while (fila.size())
            {
                mem.insert(fila.front());
                fila.pop();
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }

    return 0;
}