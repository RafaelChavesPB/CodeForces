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

ll pd[121][720] = {0};
ll mod = 1000000007;
void solve(){
	string s, p;
	cin >> s >> p;

	for(int i = 0; i < s.size(); i++)
		pd[0][i] = (p[0] == s[i]);
	bugV(pd[0])
	for(int i = 1; i < p.size(); i++){
		for(int j = 0; j < s.size(); j++){
			if(p[i] == s[j]){
				pd[i][j] = pd[i-1][j-1];
			}
			if(p[i] == '*'){
				pd[i][j] = pd[i-1][j];
				if(j)
					pd[i][j] = (pd[i][j] + pd[i][j-1]) % mod;
			}
		}
		bugV(pd[i])
	}
	ll ans = 0;
	for(int i = 0; i < s.size(); i++)
		ans = (ans + pd[p.size() - 1][i]) % mod;
	cout << ans << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
		solve();
	return 0;
}
