#include <bits/stdc++.h>
using namespace std;

vector<int> freq(1000001, 0);

void solve()
{
    long long ans = 0;
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
        freq[numbers[i]]++;
    }
    sort(numbers.begin(), numbers.end());
    vector<int>::iterator new_end = unique(numbers.begin(), numbers.end());
    numbers.resize(distance(numbers.begin(), new_end));
    for (auto it = numbers.rbegin(); it != numbers.rend(); it++)
    {

        int k = *it;
        ans += (1ll*freq[k])*(freq[k]-1)*(freq[k]-2);
        for (int d = 2; d <= sqrt(k); d++)
        {
            if (k % d == 0)
            {
                int j = k / d;
                if (j % d == 0)
                {
                    int i = j / d;    
                    ans += (1ll*freq[k]) * freq[j] * freq[i];
                }
            }
        }
        freq[k] = 0;
    }
    cout << ans << '\n';
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