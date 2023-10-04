#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(auto &it: arr) cin >> it;
	map<int, int> left, right;
	for(int i = 0, sum = 0; i < n; i++) {
		sum += arr[i];
		left[sum] = i + 1;
	}
	for(int r = n - 1, sum = 0; r >= 0; r--){
		sum += arr[r];
		right[sum] = n - r;
	}
	int ans = 0;
	for(auto fs: left){
		if(right.find(fs.first) != right.end())
			if(right[fs.first] + fs.second <= n)
				ans = max(right[fs.first] + fs.second, ans);
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
