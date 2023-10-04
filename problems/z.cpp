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
        int n, ans = 0;
        cin >> n;
        int curr = 1, head = 1, pot = 0;
        while (curr <= n)
        {
            ans++;
            if(++head/10){
                pot++;
                head = 1;
            }
            curr = head*pow(10, pot);
        }
        cout << ans << '\n';
    }
}