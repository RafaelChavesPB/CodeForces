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
	vector<string> a(3);
	for(auto &s: a)
		cin >> s;
	for(int i = 0; i < 3; i++){
		if((a[i][0] == a[i][1] and a[i][0] == a[i][2]) 
			or (a[0][i] == a[1][i] and a[0][i] == a[2][i]))
			if(a[i][i] != '.' ){
				cout << a[i][i] << '\n';
				return;
			}
	}
	if((a[0][0] == a[1][1] and a[2][2] == a[1][1]) or (a[0][2] == a[1][1] and a[2][0] == a[1][1]))
		if(a[1][1] != '.'){
			cout << a[1][1] << '\n';
			return;
		}
	cout << "DRAW\n";
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
