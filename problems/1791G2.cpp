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
	ll n, c;
	cin >> n >> c;
	vector<ll> arr(n +1);
	vector<pair<ll,ll>> prefix(n + 1, {0,0}); 
	for(ll i = 1; i <= n; i++){
		cin >> arr[i];
		prefix[i] = {min(arr[i] + i, arr[i] + n + 1 - i), i};
	}
	sort(all(prefix));
	bool flag = false;
	ll ans = 0, res = 0, idx, value, searched, rightValue, leftValue;
	for(ll i = 1; i <= n; i++){
		prefix[i].first += prefix[i-1].first;
		idx = prefix[i].second;
		bug2(prefix[i].first, idx)
		if(prefix[i].first <= c){
			res = i;
			if(prefix[i].first - prefix[i-1].first == arr[idx] + idx)
				flag = true;
		}
	}
	bug(flag)
	if(flag == true){
		cout << res << '\n';
		return;
	}
	ans = 0;
	for(ll i = 1; i <= n; i++){
		idx = prefix[i].second;
		rightValue = arr[idx] + n + 1 - idx;
		leftValue = arr[idx] + idx;
		searched = c - leftValue;
		bug(idx)
		bug(leftValue)
		bug(searched)
		if(searched >= 0){
			ll pos = upper_bound(all(prefix), make_pair(searched, n + 1)) - prefix.begin();
			bug(pos)
			if(i <= pos){
				searched += rightValue;
				pos = (upper_bound(all(prefix), make_pair(searched, n + 1)) - prefix.begin()) - 1;
			}
			ans = max(ans, pos);
			bug(pos)
		}
		bugL()
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
