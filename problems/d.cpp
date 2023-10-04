#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, componentes = 0, total = 0;
        cin >> n >> k;
        vector<long long> array(n + 1);
        vector<set<long long>> adj(n + 1);
        queue<long long> fila;
        for (long long i = 1; i <= n; i++)
        {
            cin >> array[i];
            total ^= array[i];
        }
        for (long long i = 0; i < n - 1; i++)
        {
            long long a, b;
            cin >> a >> b;
            adj[a].insert(b);
            adj[b].insert(a);
        }
        if (total == 0)
        {
            cout << "YES" << endl;
        }
        else
        {

            for (long long i = 1; i <= n; i++)
            {
                if (adj[i].size() == 1)
                {
                    fila.push(i);
                }
            }

            long long pai;
            while (fila.size())
            {
                long long idx = fila.front();
                fila.pop();

                if (adj[idx].empty())
                    continue;

                pai = *begin(adj[idx]);
                adj[pai].erase(idx);
                if (adj[pai].size() == 1)
                    fila.push(pai);
                

                if (array[idx] != total)
                    array[pai] ^= array[idx];
                else
                {
                    componentes++;
                }
            }
            if (array[pai] == total and k >= 3 and componentes)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}