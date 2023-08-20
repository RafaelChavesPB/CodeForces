#include <bits/stdc++.h>
using namespace std;


void solve()
{
    long long ans = 0;
    int n;
    cin >> n;
    map<int, int> freq;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
        freq[numbers[i]]++;
    }
    sort(numbers.begin(), numbers.end());
    auto new_end = unique(numbers.begin(), numbers.end());
    numbers.resize(distance(numbers.begin(), new_end));
    for (auto it = numbers.rbegin(); it != numbers.rend(); it++)
    {
        int k = *it;
        int f = freq[k];
        ans += (1ll*f)*(f-1)*(f-2);
        for (int d = 2; d <= cbrt(k); d++)
        {
            if (k % d == 0)
            {
                int j = k / d;
                if (j % d == 0)
                {
                    int i = j / d;    
                    if(freq.find(j) != freq.end() and freq.find(i) != freq.end()){
                        ans += (1ll*f) * freq[j] * freq[i];
                    }
                }
            }
        }
        for (int idx = 0; numbers[idx] < cbrt(k); idx++)
        {
            int i = numbers[idx];
            if (k % i == 0)
            {
                int d = sqrt(k / i);
                if (i*d*d == k)
                {
                    int j = i * d;    
                    if(freq.find(j) != freq.end() and freq.find(i) != freq.end()){
                        ans += (1ll*f) * freq[j] * freq[i];
                    }
                }
            }
        }
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