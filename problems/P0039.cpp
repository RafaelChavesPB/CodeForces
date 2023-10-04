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
map<pair<int,int>, int> grid;
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

void coutDir(int dir){
	string a = "RULD";
	cout << a[dir];
}
void solve(){
	int n, row = 0, col = 0, dir = 0, next_dir = 0; 
	cin >>n;
	for(int i = 1; i <= n*n; i++){
		grid[make_pair(row, col)] = i;
		if(grid.find({row + dr[next_dir], col + dc[next_dir]})== grid.end()){
			dir = next_dir;
			next_dir = (next_dir + 1) % 4;
		}
		row += dr[dir];
		col += dc[dir];
	}
	auto last = (grid.begin()->first).first;
	for(auto curr: grid){
		if(curr.first.first == last)
			cout << ' ';
		else
			cout << '\n';
		last = curr.first.first;
		cout << curr.second;
	}
	cout << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
