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
	ll n, zeros = 0, ones = 0; 
	cin >> n;
	string s;
	vector<ll> arr(n+1), prefix(n + 1); 
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		prefix[i] = arr[i] ^ prefix[i-1];
	}
	cin >> s;
	for(int i = 0; i < n; i++){
		if(s[i] == '0'){
			zeros ^= arr[i+1];
		}else{
			ones ^= arr[i+1];
		}
	}
	bug2(zeros, ones)
	int q;
	cin >> q;
	while(q--){
		int op;
		cin >> op;
		if(op == 1){
			int l, r;
			cin >> l >> r;
			ll total = prefix[r] ^ prefix[l-1];
			zeros ^= total;
			ones ^= total;
		}else{
			int type;
			cin >> type;
			if(type == 0)
				cout << zeros << ' ';
			else
				cout << ones << ' ';
		}
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
