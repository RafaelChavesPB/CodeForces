#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    string base = "";
    for (int i = 1; i <= 60; i++)
    {
        if (i % 3 == 0)
            base += "F";
        if (i % 5 == 0)
            base += "B";
    }
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        if (base.find(s) != string::npos)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}