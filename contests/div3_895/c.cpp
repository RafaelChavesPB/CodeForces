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
	ll l, r; 
	cin >> l >> r;
	if(r <= 3){
		cout << -1 << '\n';
	} else if(r%2 == 0){
		cout << r/2 << ' ' << r/2 << '\n';
	}
	else if(l != r){
		r--;
		cout << r/2 << ' ' << r/2 << '\n';
	}else{
		for(int i = 2; i<= sqrt(r); i++){
			if(r%i == 0){
				int q = r/i;
				cout << q << ' ' << (i-1)*q << '\n';
				return;
			}
		}
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
