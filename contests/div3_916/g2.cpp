#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
using ll = long long;
using ull = unsigned long long;
 
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

ull generate_hash(){
	static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
	return rnd();
}
 
void solve(){
	ll n, groups = 0, good_bulbs_in_group = 0, ans = 1; 
	cin >> n;
	vector<ull> prefix_hash(2*n + 1), hash_values(n+1);
	unordered_map<ull, vector<int>> hash_indexes;
	for(int i = 1; i <= n; i++) hash_values[i] = generate_hash();
	for(int i = 1, color; i <= 2*n; i++){
		cin >> color;
		prefix_hash[i] = prefix_hash[i-1] ^ hash_values[color];
		hash_indexes[prefix_hash[i]].push_back(i);
	}
	for(int i = 1; i <= 2*n + 1; i++){
		if(prefix_hash[i-1] == 0){
			ans = (ans * (good_bulbs_in_group + 1)) % MOD;
			good_bulbs_in_group = 0;
			groups++;
		}else{
			vector<int> &curr_hash_indexes = hash_indexes[prefix_hash[i - 1]];
			vector<int>::iterator end_minimum_group = upper_bound(curr_hash_indexes.begin(), curr_hash_indexes.end(), i);
			if(end_minimum_group != curr_hash_indexes.end()){
				i = *end_minimum_group;
			}else{
				good_bulbs_in_group++;
			}
		}
	}
	bugV(prefix_hash);
	cout << groups - 1 << ' ' << ans << endl;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
