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
	for(int i = 0; i < n; i++){
		if(arr[i] % 10 == 5)
			arr[i] += 5;
		if(arr[i] % 10 == 0)
			continue;
		while(arr[i] % 10 != 2)
			arr[i] += arr[i] % 10;
	}
	ll curr = arr[0];
	for(int i = 1; i < n; i++){
		if(curr % 10 != arr[i] % 10){
			cout << "NO\n";
			return;
		}
		if(curr % 10 == 0){
			if(curr != arr[i]){
				cout <<"NO\n";
				return;
			}
			continue;
		}

		if((curr/10) % 2 != (arr[i]/10) % 2){
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
