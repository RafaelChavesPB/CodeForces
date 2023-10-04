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



vector<Vl> grid;
Vi visited;
int n, m;

ll backtracking(int curr){
	ll best = 0;
	visited[curr] = 1;
	for(int i = 1; i <= n; i++){
		if(visited[i] or grid[curr][i] == -1)
			continue;
		best = max(best, backtracking(i) + grid[curr][i]);
	}
	visited[curr] = 0;
	return best;
}



void solve(){
	cin >>n >> m;
	grid.assign(n+1, Vl(n+1, -1));
	visited.assign(n+1,0);
	for(int i = 1; i <= n; i++)
		grid[0][i] = 0;
	
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		grid[a][b] = c;
		grid[b][a] = c;
	}
	cout << backtracking(0) << endl;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
