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
        int n, ans = 0;
        string s, S, last = "";
        cin >> n >> s;
        for (int i = 0; i < n; i += 2)
        {
            string curr = s.substr(i, 2);
            if (curr != last)
                S += curr;
            last = curr;
        }
        for(int i = 0; i < S.size() - 1; i++){
            if(s[i] == s[i+2])
                i++;
            ans++;
        }
        cout << ans << endl;
    }
}