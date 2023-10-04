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
 
bool test(int lim, int n, vector<int> &updates, vector<pair<int, int>> &segments){
	vector<int> prefix(n+1, 0);
	for(int i = 0; i < lim; i++)
		prefix[updates[i]] = 1;
	for(int i = 1; i <= n; i++)
		prefix[i] += prefix[i-1];
	for(auto seg: segments){
		int l = seg.first;
		int r = seg.second;
		if(prefix[r] - prefix[l-1] > (r - l + 1)/2){
			return true;
		}
	}
	return false;
}

void solve(){
	int n, m, q;
	cin >> n >> m;
	vector<pair<int,int>> segments(m); for( auto &it: segments) cin >> it.first >> it.second;
	cin >> q;
	vector<int> updates(q);
	for(auto &x: updates) cin >> x;
	int ans = -1, l = 1, r = q;
	while(l <= r){
		bug2(l, r);
		int mid = (l+r)/2;
		if(test(mid, n, updates, segments)){
			ans = mid;
			r = mid - 1;
		}else{
			l = mid + 1;
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
