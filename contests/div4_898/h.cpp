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

vector<vector<int>> adj;
vector<int> visited;

bool ans;

void dfs(int v, int p, int m){
	visited[v] = 1;
	for(auto u: adj[v]){
		if(u == p)
			continue;
		if(visited[u] == 1){
			ans = true;
			continue;
		}
		if(u == m)
			continue;
		dfs(u, v, m);
	}
}

void solve(){
	ll n, a, b;
	ans = false;
	cin >>n >> a >> b;
	adj.assign(n+1, vector<int>());
	visited.assign(n+1, 0);
	int w,k;
	for(int i = 0; i < n; i++){
		cin >> w >> k;
		adj[w].push_back(k);
		adj[k].push_back(w);
	}
	dfs(b, -1, a);
	if(ans)
		cout << "YES\n";
	else
		cout << "NO\n";
}


 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
