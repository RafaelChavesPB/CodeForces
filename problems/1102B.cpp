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
	ll n, k; 
	cin >> n >> k;
	vector<vector<int>> freq(5001);
	vector<ll> arr(n), ans(n);
	for( int i = 0; i < n; i++) { cin >> arr[i]; freq[arr[i]].push_back(i);};
	int curr = 0;
	for(int i = 0; i <= 5000; i++){
		if(freq[i].size() > k){
			cout << "NO\n";
			return;
		}
		for(auto it: freq[i]){
			ans[it] = ++curr;
			curr %= k;
		}
	}
	cout << "YES\n";
	for(auto it: ans)
		cout << it << ' ';
	cout << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
