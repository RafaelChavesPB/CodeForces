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
	ll n, a = 0, b = 0, mina = INT_MAX, minb = INT_MAX; 
	cin >>n;
	for(int i = 0, x; i < n; i++) {
		cin >> x;
		a += x;
		mina = min(mina, 1LL*x);
	}
	for(int i = 0, x; i < n; i++) {
		cin >> x;
		b += x;
		minb = min(minb, 1LL*x);
	}
	cout << min(a + n*minb, b + n*mina) << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
