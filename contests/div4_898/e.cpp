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
	ll n, x, ans = 0; 
	cin >> n >> x;
	vector<ll> arr(n); for(int i = 0; i < n; i++) cin >> arr[i]; 
	ll l = 1;
	ll r = 3000000001;
	while(l <= r){
		ll m = (r+l)/2;
		ll val = 0;
		for(int i = 0; i < n; i++)
			val += max(1LL*0, m - arr[i]);
		if(val <= x){
			ans = m;
			l = m + 1;
		}else{
			r = m - 1;
		}
	}
	cout << ans << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
