#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &it: arr) cin >> it;
    int ans = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] >= arr[i])
                ans++;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}