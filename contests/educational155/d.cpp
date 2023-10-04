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

ll mod = 998244353;
 
void solve(){
	ll n; 
	cin >>n;
	vector<ll> arr(n + 1); for(int i = 1; i <= n; i++) cin >> arr[i]; 
	ll sum_total = 0;
	for(int b = 0; b < 32; b++){
		ll zeros = 0;
		ll ones = 0;
		ll xor_total = 0;
		ll curr_number = (1LL << b) % mod;
		for(int i = 1; i <= n; i++){
			int curr_xor = ((1LL << b) & arr[i])  > 0;
			xor_total =  curr_xor ^ xor_total;
			if(curr_xor){
				sum_total = (sum_total + (curr_number * zeros) % mod) %mod;
				ones++;	
			}else{
				sum_total = (sum_total + (curr_number * ones) % mod) %mod;
				zeros++;
			}
		}
	}
	cout << sum_total << endl;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
