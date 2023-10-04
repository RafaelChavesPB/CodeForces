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
	#define bugR(V) { cout << "*** "; for( auto v:V) cout << v.first << ':' << v.second << " ";\
                      cout << '\n' << flush; }
 
	#define bugL() { cout << "----------\n"; }
#else
	#define bug(x) { ; }
	#define bug2(x,y) { ; }
	#define bugV(V) { ; }
	#define bugP(V) { ; }
	#define bugL() { ; }
#endif
 
#define all(v) v.begin(), v.end()
#define SIZE 10000

void solve(){
	int n, q, a, b; 
	cin >>n >> q;
	vector<vector<int>> index(SIZE);
	vector<int> arr(n); 
	map<pair<int,int>, int> cache;

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		index[arr[i]].push_back(i);
	}
	// A -> Search for the first index of B in left (upper_bound - 1), After that search for last index of B.
	// B -> Search for the first index of A in right (upper_bound), After that search for the first index of A.
	while(q--){
		cin >> a >> b;
		auto pointer = cache.find({a,b});
		if( pointer != cache.end()){
			cout << pointer -> second << '\n';
		}else{
			int best = 0;
			if(index[a].size() <= index[b].size()){
				for(auto it: index[a]){
					int first_before = (upper_bound(all(index[b]), it) - index[b].begin()) - 1;
					if(first_before >= 0){
						best = max(best, n - it + index[b][first_before] + 1);
					}else{
						int last_after = index[b].back();
						best = max(best, last_after - it + 1);
					}
				}
			}else{
				for(auto it: index[b]){
					int first_after = (upper_bound(all(index[a]), it) - index[a].begin());
					if(first_after < index[a].size()){
						bug(it + 1 + n - index[a][first_after])
						best = max(best, it + 1 + n - index[a][first_after]);
					}else{
						int first_before = index[a].front();
						best = max(best, it - first_before + 1);
						bug(it - first_before + 1)
					}
				}
			}
			cache[make_pair(a,b)] = best;
			cout << best << '\n';
		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
