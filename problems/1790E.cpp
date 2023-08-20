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

bool test(ll vxor, ll vsum){
	ll a = 0, b = 0;
	bool need_carry = false;
	for(ll i = 30; i>= 0; i--){
		bool bxor = vxor & (1 << i);
		bool bsum = vsum & (1 << i);
		if(bxor and not bsum){
			if(not need_carry){
				return false;
			}
			if(a != 0){
				b |= 1 << i;
			}else{
				a |= 1 << i;
			}

		}else if(not bxor and bsum){
			if(need_carry){
				b |= 1 << i;
				a |= 1 << i;
			}else{
				need_carry = true;
			}
		}else if(not bxor and not bsum){
			if(need_carry){
				a |= 1 << i;
				b |= 1 << i;
			}
			need_carry = false;
		}else{
			if(need_carry){
				return false;
			}
			if(a != 0){
				b |= 1 << i;
			}else{
				a |= 1 << i;
			}
		}
	}
	if(need_carry or not a or not b)
		return false;
	cout << a << ' ' << b << '\n';
	return true;
}

void solve(){
	ll n; 
	cin >>n;
	if(not test(n, n << 1) and not test(n, (n << 1) + 1)){
		cout << -1 << '\n';
	}
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
