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
	int q, L = 0, R = 0, id;
	cin >> q;
	string side;
	vector<int> left(200001, -1), right(200001, -1); 
	while(q--){
		cin >> side >> id;
		if(side == "L"){
			left[id] = (++L);
		}else if(side == "R"){
			right[id] = (++R);
		}else{
			int ans = 200001;
			if(left[id] > 0){
				ans = min(R+left[id]-1, L-left[id]);
			}else{
				ans = min(L+right[id]-1, R-right[id]);
			}
			cout << ans << '\n';
		}
		
	}
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
