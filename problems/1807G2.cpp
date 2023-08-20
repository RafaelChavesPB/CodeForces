#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(auto &it: arr) cin >> it;
	sort(arr.begin(), arr.end());
	if(arr[0]!=1) {
		cout << "NO\n";
		return;
	}
	ll sum = arr[0];
	for(int i = 1; i < n; i++){
		if(arr[i] > sum){
			cout <<"NO\n";
			return;
		}
		sum += arr[i];
	}
	cout << "YES\n";
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
