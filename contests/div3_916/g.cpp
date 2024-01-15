#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
using ll = long long;
 
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
	ll n; 
	cin >> n;
	map<int, int> first_idx, second_idx;
	vector<ll> arr(2*n); 
	for(int i = 0; i < 2*n; i++) {
		cin >> arr[i];
		if(first_idx.find(arr[i]) == first_idx.end()){
			first_idx[arr[i]] = i;
		}else{
			second_idx[arr[i]] = i;
		}
	}

	vector<pair<int,int>> groups;
	int start_group = -1, end_group = -1;
	for(size_t  i = 0; i < 2*n; i++){
		if(start_group == -1){
			start_group = i;
			end_group = second_idx[arr[i]];
		}else if(first_idx[arr[i]] == i){
			end_group = max(end_group, second_idx[arr[i]]);
		} else if(i == end_group){
			groups.push_back({start_group, end_group});
			start_group = -1;
			end_group = -1;
		}
	}
	auto find_possible_bulbs_in_group = [&](int start, int end){
		if(arr[start] == arr[end]) return (ll) 2;
		queue<long long> q; q.push(arr[start]); q.push(arr[end]);
		set<long long> visited{arr[start], arr[end]};
		while(q.size()){
			set<long long> candidates;
			size_t curr_start = first_idx[q.front()];
			size_t curr_end = second_idx[q.front()];
			for(size_t curr = curr_start + 1; curr < curr_end; curr++)
				if(candidates.find(arr[curr]) != candidates.end())
					candidates.erase(arr[curr]);
				else
					candidates.insert(arr[curr]);
			for(auto candidate: candidates){
				if(visited.find(candidate) == visited.end()){
					visited.insert(candidate);
					q.push(candidate);
				}
			}
			q.pop();
		}
		return  (ll) visited.size() * 2;
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
