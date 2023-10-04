#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    deque<int> arr(1 << n);
    for(int i = 1; i <= (1 << n); i++)
        arr[i-1] = i;
    
    string s;
    cin >> s;
    int zeros = (1 << count(s.begin(), s.end(), '0')) - 1;
    int ones = (1 << count(s.begin(), s.end(), '1')) - 1;
    while(zeros--)
        arr.pop_back();
    while(ones--)
        arr.pop_front();
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);   
    solve();
    
}