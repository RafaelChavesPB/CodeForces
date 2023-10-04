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

int arr[200001], segtree[1000001];

void build(int node, int l, int r){
	if(l == r){
		segtree[node] = arr[l]; 
		return;
	}

	int m = (r + l)/2;
	build(2*node, l, m);
	build(2*node + 1, m + 1, r);
	segtree[node] = segtree[2*node] & segtree[2*node+1];
}

int query(int node, int ql, int qr, int l, int r){
	if( ql <= l and r <= qr)
		return segtree[node];
	
	if(r < ql or qr < l)
		return (1 << 30) - 1;

	int m = (r + l)/2;
	return query(2*node, ql, qr, l, m) & query(2*node + 1, ql, qr, m+1, r);
}

void solve(){
	ll n; 
	cin >>n;
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	build(1, 1, n);
	ll q;
	cin >> q;
	while(q--){
		ll ql, k, ans = ql;
		cin >> ql >> k;
		if(k > arr[ql]){
			cout << -1 << ' ';
			continue;
		}
		ll l = ql, r = n;
		while(l <= r){
			ll qr = (l + r)/ 2;
			if(query(1, ql, qr, 1, n) >= k){
				ans = qr;
				l = qr + 1; 
			}else{
				r = qr - 1;
			}
		}
		cout << ans << ' ';
	}
	cout << '\n';


}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
