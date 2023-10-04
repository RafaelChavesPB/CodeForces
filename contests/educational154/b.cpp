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
	ll n, end = 0; 
	string a, b, prefix = "", suffix = "";
	cin >> a >> b;
	n = a.size();
	for(int i = 0; i < n - 1; i++){
		if(a[i] == b[i] and a[i] == a[0] and b[i] == a[i]){
			for(int j = 0; j < 2; j++){
				if(a[i+j] == a[n-1] and b[i+j] == b[n -1] and a[n -1] == b[n -1]){
					cout << "YES" << endl;
					return;
				}
			
			}
		}
	}
	cout << "NO\n";
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
