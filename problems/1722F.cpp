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
 
void solve(){
	ll r, c; 
	cin >> r >> c;
	string s;
	vector<string> grid(r + 2);
	for(int i = 0; i <= r+1; i++) grid[0]+=' ', grid[r+1]+= ' ';
	for(int i = 1; i <= r; i++) {
		cin >> s;
		s += ' ';
		grid[i] += ' ' + s;
	}
	int dr[] = {-1, -1, -1, 0, 1, 1,  1,  0};
	int dc[] = {-1,  0,  1, 1, 1, 0, -1, -1};
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			int count = 0;
			if(grid[i][j] != '*')
				continue;
			for(int k = 0; k < 8; k++){
				if(grid[i+dr[k]][j+dc[k]]=='*')
					count++;
			}
			if(count != 2){
				cout <<"NO\n";
				return;
			}
			bool flag = false;
			for(int k = 0; k < 8; k++){
				char a = grid[i + dr[k]][j + dc[k]];
				char b = grid[i + dr[(k + 1)%8]][j + dc[(k + 1)%8]];
				if(a == '*' and b == '*'){
					flag = true;
				}
			}

			for(int  k = 1; k < 8; k += 2){
				char a = grid[i + dr[k]][j + dc[k]];
				char b = grid[i + dr[(k + 2)%8]][j + dc[(k + 2)%8]];
				if(a == '*' and b == '*'){
					flag = true;
				}
			}

			if(flag == false){
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";

}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
