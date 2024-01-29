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
	int n;
	vector<int> parents;
	vector<int> rank;
public:
	DSU(int n) : n(n){
		parents.resize(n + 1);
		iota(parents.begin(), parents.end(), 0);
		rank.assign(n + 1, 1);
	}
	int find(int a){
		if(a == parents[a])
			return a;
		return parents[a] = find(parents[a]);
	}
	void join(int a, int b){
		a = find(a);
		b = find(b);
		if(a == b)
			return;
		
		if(rank[a] == rank[b]){
			parents[b] = a;
			rank[a] ++;
			return;
		}

		if(rank[a] < rank[b])
			parents[a] = b;
		else
			parents[b] = a;
	}
};
 
void solve(){
	ll milk, cats; 
	cin >> milk >> cats;
	DSU dsu(cats);
	ll number_of_edges = (cats*(cats - 1))/2;
	vector<array<int,3>> edges(number_of_edges); 
	for(int i = 0, a, b, d; i < number_of_edges; i++){
		cin >> a >> b >> d;
		edges[i] = {d, a, b};
	}
	sort(edges.begin(), edges.end());
	for(array<int, 3> edge: edges){
		if(dsu.find(edge[1]) == dsu.find(edge[2]))
			continue;
		dsu.join(edge[1], edge[2]);
		milk -= edge[0];
	}
	if(milk >= cats)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
