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
	vector<int> ans(n);
	for(int i = 1; i <=n; i++) ans[i-1] = i;
	if(k <= n/2){
		reverse(ans.begin(), ans.end());
	}else{
		k = n - k - 1;
	}

	for(int i = 0; i < k; i++)
		swap(ans[2*i], ans[2*i+1]);
	for(auto it: ans) cout << it << ' ';
	cout << endl;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
