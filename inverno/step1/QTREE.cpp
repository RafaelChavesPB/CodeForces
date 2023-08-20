#include <bits/stdc++.h>
#define LIM 10001

using namespace std;

typedef long long ll;

namespace seg {
	ll array[LIM];
	ll segtree[4*LIM];
	void build(int idx, int l, int r){
		if(l == r){
			segtree[idx] = array[l];
			return ;
		}
		int m = (l+r)/2;
		build(2*idx, l, m);
		build(2*idx + 1, m+1, r);
		segtree[idx] = max(segtree[2*idx], segtree[2*idx + 1]);
	}

	ll query(int idx, int ql, int qr, int l, int r){
		
		if(ql <= l  and r <= qr){
			return segtree[idx];
		}

		if(r < ql or qr < l){
			return INT_MIN;
		}

		int m = (l + r)/2;
		return max(query(2*idx, ql, qr, l, m),query(2*idx + 1, ql, qr, m + 1, r));
	}

	void update(int idx, int pos, ll val, int l, int r){
		if(l == r){
			segtree[idx] = val;
			array[pos] = val;
			return;
		}

		int m = (l + r)/2;
		if(pos <= m)
			update(2*idx, pos, val, l, m);
		else 
			update(2*idx + 1, pos, val, m+1, r);

		segtree[idx] = max(segtree[2*idx],segtree[2*idx + 1]);
	}
}


int  sz[LIM], h[LIM], pai[LIM], pos[LIM];
ll val[LIM];
vector<vector<pair<int,ll>>> g;
vector<pair<int,ll>> arestas;
int n, t;

void dfs(int i, int p = -1){
	sz[i] = 1;
	for (auto& fs : g[i]) if ( fs.first != p ) {
		int j = fs.first;
		int value = fs.second;
		val[j] = value;
		dfs(j, i);
		sz[i] += sz[j];
		if(sz[j] > sz[g[i][0].first] or g[i][0].first == p) swap(fs, g[i][0]);
	}
}

void build_hld(int i, int p = -1){
	pos[i] = ++t;
	seg::array[pos[i]] = val[i];
	for (auto& fs : g[i]) if ( fs.first != p ) {
		int j = fs.first;
		pai[j] = i;
		h[j] = (j == g[i][0].first ? h[i] : j);
		build_hld(j, i);
	}
}

void build(int root = 0){
	dfs(root);
	t = 0;
	h[root] = root;
	pai[root] = root;
	build_hld(root);
	seg::build(1, 1, n);
}

ll query_path(int a, int b){
	if(pos[a] < pos[b]) swap(a, b);
	if(h[a] == h[b]) return seg::query(1, pos[b], pos[a], 1, n);  
	else return max(seg::query(1, pos[h[a]] + 1, pos[a], 1, n), query_path(pai[h[a]], b));  
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		g.assign(n+1, vector<pair<int,ll>>());
		arestas.assign(n+1, pair<int,int>());
		for(int i = 0; i < n -1; i++){
			int a, b;
			ll c;
			cin >> a >> b >> c;
			g[a].push_back({b,c});
			g[b].push_back({a,c});
			arestas.push_back({a,b});
		}
		build(1);
		string op;
		while(cin >> op && op != "DONE"){
			if(op == "QUERY"){
				int a, b;
				cin >> a >> b;
				cout << query_path(a, b) << '\n'; 
			}else{
				int edge;
				ll value;
				cin >> edge >> value;
				int a = arestas[edge].first;
				int b = arestas[edge].second;
				if(pai[a] == b){
					seg::update(1, a, value, 1, n);
				}else{
					
					seg::update(1, b, value, 1, n);
				}
			}
		}
	}
}
