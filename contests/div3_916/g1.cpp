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
	ll n; 
	cin >> n;
	vector<int> arr(2*n + 1); 
	vector<pair<int,int>> groups;
	map<int, vector<int>>  color_indexes;
	map<ull, vector<int>> xor_indexes{{0, vector<int>{0}}};
	vector<ull> prefix_xor(2*n + 1);
	for(int i = 1; i <= 2*n; i++) {
		cin >> arr[i];
		color_indexes[arr[i]].push_back(i);
		if(color_indexes[arr[i]].size() == 1)
			prefix_xor[i] = generate_hash();
		else
			prefix_xor[i] = prefix_xor[color_indexes[arr[i]].front()];
	}
	for(int i = 1; i <= 2*n; i++) {
		prefix_xor[i] ^= prefix_xor[i-1];
		xor_indexes[prefix_xor[i]].push_back(i);
	}
	int start_group = -1, end_group = -1;
	for(int  i = 1; i <= 2*n; i++){
		if(start_group == -1){
			start_group = i;
			end_group = color_indexes[arr[i]][1];
		}else if(color_indexes[arr[i]][0] == i){
			end_group = max(end_group, color_indexes[arr[i]][1]);
		}else if(i == end_group){
			groups.push_back({start_group, end_group});
			start_group = -1;
			end_group = -1;
		}
	}
	auto find_possible_bulbs_in_group = [&](int start, int end){
		int total = end - start + 1;
		if(arr[start] == arr[end]) return 2;
		for(int i = start + 1; i < end; i++){
			ull subgroup_xor = prefix_xor[i-1];
			auto end_subgroup = upper_bound(xor_indexes[subgroup_xor].begin(), xor_indexes[subgroup_xor].end(), i);
			if(end_subgroup != xor_indexes[subgroup_xor].end() and *end_subgroup < end){
				total -= *end_subgroup - i + 1;
				i = *end_subgroup;
			}
		}
		return total;
	};
	ll ans = 1;
	for(auto it: groups){
		ll possible_bulbs = find_possible_bulbs_in_group(it.first, it.second);
		ans = (ans * possible_bulbs)%MOD;
	}
	cout << groups.size() << ' ' << ans << endl;

}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
