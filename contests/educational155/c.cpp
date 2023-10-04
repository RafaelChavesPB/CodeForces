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
ll mod =  998244353;
ll  fact(ll n){
	ll f = 1;
	for(ll i = 2; i <= n; i++){
		f = (f * i)%mod;
	}
	return f;
}
void solve(){
	string s;
	cin >> s;
	ll count = 1;
	ll a = 0, b = 1, n = s.size();
	s += '\0';
	for(int i = 1; i < s.size(); i++){
		if(s[i-1] == s[i]){
			count++;	
		}else{
			a += count - 1;
			b = (b * count) % mod;
			count = 1;
		}
	}


	
	cout << a << ' ' << (b*fact(a))%mod << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
