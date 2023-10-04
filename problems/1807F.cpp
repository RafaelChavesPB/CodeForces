#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int hashd(int i, int j){
	return (i==-1?0:1)+2*(j==-1?0:1);
}
void solve(){
	int R, C, r, c, fr, fc, count = 0;
	string dir;
	cin >> R >> C >> r >> c >> fr >> fc >> dir;
	int dr = (dir[0] == 'U'?-1:1), dc=(dir[1] == 'L'?-1:1);
	vector<vector<vector<int>>> vis(R+1, vector<vector<int>>(C+1, vector<int>(4, INT_MAX)));		
	while(true){
		int d = 1;
		if(r == fr and c == fc){
			cout << count << '\n';
			break;
		}
		if(vis[r][c][hashd(dr,dc)] < INT_MAX){
			cout << -1 << '\n';
			break;
		}
		vis[r][c][hashd(dr,dc)] = count;
		if(r + dr == 0 or r + dr == R+1){
			dr*=-1;
			count+=d--;
		}
		if(c + dc == 0 or c + dc == C+1){
			dc*=-1;
			count+=d--;
		}
		r += dr;
		c += dc;
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
