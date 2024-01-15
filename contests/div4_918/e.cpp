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
	cin >> n;
	vector<ll> arr(n + 1);
	vector<ll> prefix(n + 1);
	set<ll> appeared;
	appeared.insert(0);
	for(int i = 1; i <= n; i++) cin >> arr[i];
	for(int i = 1; i <= n; i++) 
	{
		if(i%2) prefix[i] = prefix[i-1] - arr[i] ;
		else prefix[i] = prefix[i-1] + arr[i];
		if(appeared.find(prefix[i]) != appeared.end()){
			cout << "YES" << endl;
			return;
		}else{
			appeared.insert(prefix[i]);
		}
	} 
	cout << "NO" <<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
