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

typedef struct Marbles {
	ll a, b, c;
} marbles;

void solve(){
	ll n; 
	cin >> n;
	vector<ll> a(n); for(int i = 0; i < n; i++) cin >> a[i]; 
	vector<ll> b(n); for(int i = 0; i < n; i++) cin >> b[i]; 
	vector<marbles> arr;
	for(int i = 0; i < n; i++){
		marbles tmp = {a[i] - 1, b[i] - 1, a[i]+b[i]-1}; 
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end(), [](marbles &x, marbles &y){
			return  x.c < y.c;
	});
	bool flag = false;
	ll ans = 0;
	while(arr.size()){
		if(!flag){
			ans += arr.back().a;
		}else{
			ans -= arr.back().b;
		}
		flag = !flag;
		arr.pop_back();
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
