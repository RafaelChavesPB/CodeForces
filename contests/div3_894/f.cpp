#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
 
#ifdef EBUG
	#define bug(x) { cout << "*** " << #x << " " << x << '\n' << flush; }
 
	#define bug2(x,y) { cout << "*** " << #x << " " << x \
                        << " " << #y << " " << y << '\n' << flush; }
 
	#define bugV(V) { cout << "*** "; for( auto v:V) cout << v << " ";\
                      cout << '\n' << flush; }
 
	#define bugL() { cout << "----------\n"; }
#else
	#define bug(x) { ; }
	#define bug2(x,y) { ; }
	#define bugV(V) { ; }
	#define bugL() { ; }
#endif
 
#define all(v) v.begin(), v.end()
 
void solve(){
	ll w, f, n, sum = 0; 
	cin >> w >> f;
	cin >> n;
	vector<ll> arr(n); for( auto &it: arr) {cin >> it; sum += it;}
	vector<bool> subsetsums(sum+1);
	subsetsums[0] = true;
	for(int i = 0; i < n; i++){
		for(int r = sum; r >= arr[i]; r--){
			if(subsetsums[r-arr[i]])
				subsetsums[r] = true;
		}
	}
	ll ans = INT_MAX;
	for(int i = 0; i <= sum; i++){
		if(subsetsums[i]){
			ll complementary = sum - i;
			ll days_w = i / w + (i % w != 0);
			ll days_f = complementary / f  + (complementary % f != 0);
			ans = min(ans, max(days_w, days_f));
		}
	}
	cout << ans << endl;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
