
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> visited;

void dfs(int v){
	visited[v] = 1;
	for(auto u: adj[v])
		if(!visited[u])
			dfs(u);
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	adj.assign(n+1, vector<int>());
	visited.assign(n+1, 0);
	for(int i = 0; i < m; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int count = 0;
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			count++;
			dfs(i);
		}
	}
	cout << count << '\n';
	return 0;
}
