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
	ll n; 
	cin >>n;
	vector<ll> arr(n); for( auto &it: arr) cin >> it;
	vector<vector<int>> pd(2, vector<int>(n));
	for(int i = 1; i < n; i++){
		bool desc = arr[i] >= arr[i-1];
		bool asc = arr[i] <= arr[i-1];
		pd[0][i] = min(pd[0][i-1] + asc, pd[1][i-1] + 1);
		pd[1][i] = pd[1][i-1] + desc;
	}
	cout << min(pd[1][n-1] + 1, pd[0][n-1]) <<  endl;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
