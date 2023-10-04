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
	priority_queue<int, vector<int>, greater<int>> pq;
	ll n, c, sum = 0, ans = 0; 
        cin >> n >> c;
	vector<ll> arr(n+1); 
	for( int i = 1; i <= n; i++) { 
		cin >> arr[i];
		pq.push(arr[i]+i);
	}
	while(pq.size()){
		ll top = pq.top();
		pq.pop();
		if( top <= c ){
			ans++;
			c -= top;
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
