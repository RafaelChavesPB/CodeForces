#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> triples;

void solve()
{
    int n;
    cin >> n;
    vector<int> freq(10, 0);
    for (int i = 0, a; i < n; i++)
    {
        cin >> a;
        freq[a % 10]++;
    }

    for (auto tp : triples)
    {
        freq[tp[0]]--, freq[tp[1]]--, freq[tp[2]]--;
        if (freq[tp[0]] >= 0 and freq[tp[1]] >= 0 and freq[tp[2]] >= 0)
        {
            cout << "YES\n";
            return;
        }
        freq[tp[0]]++, freq[tp[1]]++, freq[tp[2]]++;
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 10; i++)
        for (int j = i; j < 10; j++)
            for (int k = j; k < 10; k++)
                if ((i + j + k) % 10 == 3)
                    triples.push_back({i, j, k});
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}