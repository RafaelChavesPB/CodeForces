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
	int firstAvailable = 0;
	vector<ll> arr(n); for( auto &it: arr) cin >> it;
	while(firstAvailable < n - 1){
		
		int lesserIdx = min_element(arr.begin() + firstAvailable, arr.end()) - arr.begin();
		int lesser = arr[lesserIdx];
		if(lesserIdx == firstAvailable){
			firstAvailable++;
			continue;
		}     
		for(int r = lesserIdx; r > firstAvailable; r--)
			arr[r] = arr[r-1];
		arr[firstAvailable] = lesser;	
		firstAvailable = lesserIdx;
	}
	for(auto it: arr)
		cout << it << ' ';
	cout << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
