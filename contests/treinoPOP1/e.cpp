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
	ll n, k;
	cin >> n >> k;
	vector<vector<ll>> arr(k); 
	for(int i = 0, x; i < n; i++){
		cin >> x;
		arr[x % k].push_back(x);
	}
	ll ans = 0;
	int count = n;
	for(int i = 0; i < k; i++){
		for(int j = k-1;  j >= 0; j--){
			int target = (k-j)%k + i;
			int a1 = j % k, a2 = target % k;
			while(arr[a2].size() and arr[a1].size()){
				if(a1 == a2 and arr[a2].size() < 2)
					break;
				ll aux = arr[a2].back(); 
				arr[a2].pop_back();
				aux += arr[a1].back();
				arr[a1].pop_back();
				ans += aux/k;
				count -= 2;
			}
		}
		if(count == 0)
			break;
	}
	cout << ans << endl;


}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
