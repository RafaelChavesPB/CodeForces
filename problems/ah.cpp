#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n+2, 0);
    for(int i = 1, a; i <= n; i++){
        cin >> a;
        arr[i] = a%2 + arr[i-1];
    }
    while(q--){
        int l, r, k, aux, acc;
        cin >> l >> r >> k;
        aux = ((r-l+1)*(k%2))%2;
        acc = arr[l-1] + (arr[n] - arr[r]) + aux;
        if(acc%2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
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