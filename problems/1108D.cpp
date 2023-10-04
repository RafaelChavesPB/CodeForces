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
 
void solve(){
	ll n; 
	cin >>n;
	string s;
	cin >> s;
	int r = 17, g = 6, b = 1, count = 0;
	for(int i = 1; i < n; i++){
		int possible = 131138;
		if(s[i] != s[i-1])
			continue;
		possible &= ~(1 << (s[i-1]-'A'));
		if(i != n-1)
			possible &= ~(1 << (s[i+1]-'A'));
		
		for(int j = 0; j < 26; j++){
			if(possible & (1 << j)){
				s[i] = 'A'+j;
				count++;
				break;
			}
		}
	}
		cout << count << '\n' << s;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
