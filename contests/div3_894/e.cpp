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
	ll n, m, d; 
	cin >>n >> m >> d;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	vector<ll> arr(n + 1);
	ll ans = 0;
	ll sum = 0;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		if(arr[i] > 0){
			if(pq.size() < m){
				bug(arr[i])
				pq.push(arr[i]);
				sum += arr[i];
			}else if(arr[i] > pq.top()){
				sum += arr[i] - pq.top();
				pq.pop();
				pq.push(arr[i]);
			}
			ans = max(sum - i*d, ans);
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
