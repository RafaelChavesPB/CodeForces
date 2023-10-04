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
	string s;
	cin >> s;
	ll n = s.size();
	vector<ll> left(n, 0);
	vector<ll> right(n, 0);
	ll a = 0;
	for(int i = 0; i < n; i++){
		if(i)
			left[i] = left[i-1];
		if(s[i] == 'A'){
			a++;
		}else{
			left[i]  += a;
			a = 0;
		}
	}
	a = 0;
	for(int i = n - 1; i >= 0; i--){
		if(i < n - 1)
			right[i] = right[i+1];
		if(s[i] == 'A'){
			a++;
		}else{
			right[i] += a;
			a = 0;
		}
	}
	ll ans = max(right[0], left[n-1]);
	for(int i = 1; i < n -1; i++){
		ans = max(left[i]+right[i+1], ans);
	}
	cout << ans << '\n';

}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
