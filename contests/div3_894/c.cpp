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
	ll n; 
	cin >>n;
	vector<ll> arr(n); for( auto &it: arr) cin >> it;
	vector<ll> builded(n);
	if(*max_element(arr.begin(), arr.end()) > arr.size()){
		cout << "NO\n";
		return;
	}
	int curr = 1;
	for(int i = n - 1; i >= 0; i--)
		while(curr <= arr[i]){
			builded[curr-1] = i + 1;
			curr++;
		}
	bugV(builded);
	for(int i = 0; i < n; i++){
		if(arr[i] != builded[i]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
