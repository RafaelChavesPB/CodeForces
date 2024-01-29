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

struct Edge {
	int  a, b;
	double distance;
	bool operator<(Edge &other){
		return distance < other.distance;
	}
};

double distance(array<double, 2> &a, array<double, 2> &b){
	double dist_x = a[0] - b[0];
	double dist_y = a[1] - b[1];
	return sqrt(dist_x*dist_x + dist_y*dist_y);
}

class DSU{
private:
	vector<int> parents;
	vector<int> rank;
public:
	DSU(int n){
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
		if (a == b)
			return;
		if(rank[a] == rank[b]){
			parents[a] = b;
			rank[b]++;
		}else if(rank[a] < rank[b]){
			parents[a] = b;
		}else{
			parents[b] = a;
		}
	}
};
 
void solve(){
	ll n; 
	cin >>n;
	DSU dsu(n);
	double ans = 0;
	vector<array<double, 2>> isles(n);
	vector<Edge> edges;
	for(int  i = 0; i < n; i++){
		cin >> isles[i][0] >> isles[i][1];
		for(int j = 0; j < i; j++){
			Edge e = {i, j, distance(isles[i], isles[j])};
			edges.push_back(e);
		}
	}
	sort(edges.begin(), edges.end());
	for(Edge e: edges){
		if(dsu.find(e.a) == dsu.find(e.b))
			continue;
		dsu.join(e.a, e.b);
		ans += e.distance;
	}
	cout << fixed << setprecision(5) << ans << endl;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
