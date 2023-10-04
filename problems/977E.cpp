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
 
pair<int, int> dfs(int v, vector<vector<int>> &adj, vector<int> &visited){
	int greater = adj[v].size(), less = adj[v].size();
	visited[v] = 1;
	for(auto u: adj[v]){
		if(visited[u])
			continue;
		auto gl = dfs(u, adj, visited);
		greater = max(greater, gl.first);
		less = min(less, gl.second);
	}
	return {greater, less};

}

void solve(){
	int n, m, ans = 0;
	cin >> n >> m;
	vector<int> visited(n+1);
	vector<vector<int>> adj(n+1);
	for(int i = 0, a, b; i < m; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 1; i <= n; i++){
		if(visited[i])
			continue;
		auto gl = dfs(i, adj, visited);
		if(gl.first == 2 and gl.second == 2)
			ans++;

	}
	cout << ans << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
