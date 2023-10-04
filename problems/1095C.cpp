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
	ll n, k, pot = 1; 
	cin >> n >> k;
	vector<int> ans;
	if(n < k or __builtin_popcount(n) > k){
		cout << "NO\n";
		return;
	}
	while(true){
		
		if(n <= 2*k){
			for(int i = 0; i < n - k; i++)
				ans.push_back(2*pot);
			for(int i = 0; i < 2*k-n; i++)
				ans.push_back(pot);
			break;
		}else{
			if(n%2){
				ans.push_back(pot);
				k -= 1;
			}
			n /= 2;
			pot *= 2;
		}
	}
	cout << "YES\n";
	for(auto it: ans)
		cout << it << ' ';
	cout << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	solve();
	return 0;
}
