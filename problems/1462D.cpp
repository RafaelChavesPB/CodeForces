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
	#define bugR(V) { cout << "*** "; for( auto v:V) cout << v.first << ':' << v.second << " ";\
                      cout << '\n' << flush; }
 
	#define bugL() { cout << "----------\n"; }
#else
	#define bug(x) { ; }
	#define bug2(x,y) { ; }
	#define bugV(V) { ; }
	#define bugP(V) { ; }
	#define bugL() { ; }
#endif
 
#define all(v) v.begin(), v.end()
 
void solve(){
	ll n; 
    cin >>n;
	vector<ll> arr(n); for( auto &it: arr) cin >> it;
	ll ans = n;
	for(int j = 1; j <= n; j ++){
		int x = 0;
		for(int i = 0; i < j; i++){
			x += arr[i];
		}
		int groups = 0, curr = 0;
		bool flag = true;
		for(int i = 0; i < n; i ++){
			if(curr + arr[i] < x){
				curr += arr[i];
			} else if(curr + arr[i] == x){
				curr = 0;
				groups++;

			} else {
				flag = false;
			}
		}
		if(curr != 0)
			flag = false;
		if(flag){
			bug2(x, groups)
			ans = min(ans, n - groups);
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
