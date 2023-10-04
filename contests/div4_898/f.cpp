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
	ll n, k,  ans = 0; 
	cin >> n >> k;
	vector<ll> a(n); for(int i = 0; i < n; i++) {cin >> a[i]; if(a[i] <= k) ans = 1; }; 
	vector<ll> h(n); for(int i = 0; i < n; i++) cin >> h[i]; 
	queue<ll> q;
	ll total = 0;
	for(int i = 1; i < n ; i++){
		if(h[i-1] % h[i] == 0){
			bug(i);
			q.push(a[i-1]);
			total += a[i-1];
			while(q.size() and total + a[i] > k){
				total -= q.front();
				q.pop();
			}
			if(q.size()){
				ans = max(ans, ll(q.size()) + 1);
			}
		}else{
			while(q.size())
				q.pop();
			total = 0;

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
