#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;
    sort(arr.begin(), arr.end());
    int l = 0, r = -1, best = -1, bl, br, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == r)
            count++;
        else
        {
            if (count < k or arr[i] > r + 1)
                l = arr[i];
            r = arr[i];
            count = 1;
        }

        if(count >= k and best < r - l){
            bl = l;
            br = r;
            best = r - l;
        }
    }
    if (best != -1)
        cout << bl << ' ' << br << '\n';
    else
        cout << -1 << '\n';
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