#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
	int n;
	cin >> n;
	vector<int> prefix(n+1, 0);
	for(int i = 1; i <= n; i++) {
		cin >> prefix[i]; 
		prefix[i]+= prefix[i-1];
	}
	int l = 1, r = n;
	int acc, ans;
	while(l <= r){
		int m = (l+r)/2;
		cout << "? " << m - l + 1 << ' ';
		for(int i = l; i <= m; i++){
			cout << i << ' '; 
		}
		cout << endl;
		cin >> acc;
		if(acc > prefix[m]-prefix[l-1]){
			ans = m;
			r = m - 1;
		}else{
			l = m + 1;
		}
	}
	cout <<"! " << ans << endl;
	
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
