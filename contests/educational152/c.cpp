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
	ll n, m; 
	char ai;
	cin >> n >> m;
	set<pair<int,int>> diff;
	vector<int> zeros, ones;
	string s;
	cin >> s;
	s = '0' + s + '1';

	for(int i = 0; i <= n + 1; i++){
		if(s[i] == '1')
			ones.push_back(i);
		else
			zeros.push_back(i);
	}
	for(int i = 0; i < m; i++){
		int l, r;
		cin >> l >> r;
		if(s[l] == '0'){
			l = *lower_bound(all(ones), l);
		}
			
		if(s[r] == '1'){
			r = *(upper_bound(all(zeros), r)-1);
		}

		if(l >= r){
			diff.insert({0,0});
			bug2(0, 0);
		}else{
			diff.insert({l,r});
			bug2(l, r);
		}
	}
	cout << diff.size() << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
