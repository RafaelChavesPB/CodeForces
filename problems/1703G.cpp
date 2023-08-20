#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll rec(int i, int p, vector<ll> &arr){
	if(p == 31 or i == arr.size())
		return 0;
	return (arr[i] >> p) + rec(i+1, p+1, arr);
}

void solve(){
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(n), best(n+1, 0);
	for(auto &it: arr) cin >> it;
	for(int r = n - 1; r >= 0; r--)
		best[r] = max(arr[r] - k + best[r+1], rec(r, 1, arr));		
	cout << best[0] << '\n';
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
