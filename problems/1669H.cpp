#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> arr(31, 0);
	for(int i = 0, a; i < n; i++) {
		cin >> a;
		for(int j = 0; j <= 30; j++){
			if(a  & (1 << j))
				arr[j]++;
		}
	};
	int  ans = 0;
	for(int r = 30; r >= 0; r--){
		int diff = n - arr[r];
		if(diff <= k){
			ans |= 1 << r;
			k-= diff;
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
