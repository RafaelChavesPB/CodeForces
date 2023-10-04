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
#define inf 1000000000
pair<int,int> range(int a, int b){
	if(a == b)
		return {0, inf};
 	int x = (a + b)/2 + (a + b)%2;
	if(a == b)
		return { 0, inf};
	if(a > b) 
		return {x, inf};
	return {0, x - ((a+b)%2?1:0)};
}

pair<int,int> merge(pair<int, int> a, pair<int, int> b){
	return {max(a.first, b.first), min(a.second, b.second)};
}

void solve(){
	ll n; 
	cin >>n;
	vector<ll> arr(n); for( auto &it: arr) cin >> it;
	pair<int,int> curr = {0, inf};

	for(int i = 0; i < n - 1; i++){
		curr = merge(curr, range(arr[i], arr[i+1]));
	}
	if(curr.first > curr.second)
		cout << -1 << '\n';
	else
		cout << curr.first << '\n';
	bug2(curr.first, curr.second);
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
