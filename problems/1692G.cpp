#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1, 0), prefix(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        if(arr[i]*2 > arr[i-1]){
            prefix[i]++;
        }
        prefix[i] += prefix[i-1];
    }
    int ans = 0;
    for(int i = 0; i < n - k; i++){
        int curr = prefix[i + k + 1] - prefix[i + 1];
        if(curr == k)
            ans++;   
    }
    cout << ans << endl;;
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