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
 
void solve(){
	int k;
	cin >> k;
	vector<vector<int>> seq(k);
	map<int, set<int>> equalSums;
	for(int i = 0; i < k; i++){
		int sum = 0;
		int n;
		cin >> n;
		seq[i].resize(n);
		for(auto &it: seq[i] ){
			cin >> it;
			sum += it;
		}
		for(auto it: seq[i])
			equalSums[sum-it].insert(i);	
	}
	for(auto fs: equalSums){
		if(fs.second.size() > 1){
			int a = *fs.second.begin();
			int b = *fs.second.rbegin();
			int sum = 0;
			cout << "YES\n";
			for(auto it: seq[a])
				sum += it;
			for(int i = 0;i < seq[a].size(); i++)
				if(sum - seq[a][i] == fs.first){
					cout << a + 1 << ' ' << i + 1 << '\n';
					break;
				}
			sum = 0;
			for(auto it: seq[b])
				sum += it;
			for(int i = 0;i < seq[b].size(); i++)
				if(sum - seq[b][i] == fs.first){
					cout << b + 1 << ' ' << i + 1 << '\n';
					break;
				}
			return;

		}
	}

	cout << "NO\n";
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
