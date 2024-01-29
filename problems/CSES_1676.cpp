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
class DSU {
	private: 
		vector<int> parents;
		vector<int> rank;
	public:
	int max_component_size;
	int number_of_components;
	DSU(int n): max_component_size(1), number_of_components(n){
		parents.resize(n + 1);
		iota(parents.begin(), parents.end(), 0);
		rank.assign(n + 1, 1);
	}

	int find(int v){
		if(v == parents[v])
			return v;
		return parents[v] = find(parents[v]);
	}
	void join(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y)
			return;
		number_of_components--;
		if(rank[x] < rank[y])
			swap(x, y);
		parents[y] = x;
		rank[x] += rank[y];
		max_component_size = max(max_component_size, rank[x]);
	}
};

void solve(){
	int n, m, a, b;
	cin >> n >> m;
	DSU dsu(n);
	while(m--){
		cin >> a >> b;
		dsu.join(a, b);
		cout << dsu.number_of_components << ' ' << dsu.max_component_size << endl;
	}
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
