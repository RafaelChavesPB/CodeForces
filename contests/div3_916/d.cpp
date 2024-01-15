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
 
long long get_best(vector<vector<int>> &grid, vector<int> &order){
	int  a = -1, b = -1, best;
	long long ans = 0;
	best = 0;
	for(int i = 0; i < grid[0].size(); i++){
		if(grid[order[0]][i] >= best){
			a = i;
			best = grid[order[0]][i];
		}
	}
	ans += best;
	best = 0;
	for(int i = 0; i < grid[0].size(); i++){
		if(i != a and grid[order[1]][i] >= best){
			b = i;
			best = grid[order[1]][i];
		}
	}
	ans += best;
	best = 0;
	for(int i = 0; i < grid[0].size(); i++){
		if( i != a and i != b and grid[order[2]][i] >= best){
			best = grid[order[2]][i];
		}
	}
	ans += best;
	return ans;
}

void solve(){
	ll n, answer = INT_MIN; 
	cin >> n;
	vector<int> order{0,1,2};
	vector<vector<int>> arr(3, vector<int>(n)); 
	for(int j = 0; j < 3; j++) for(int i = 0; i < n; i++) cin >> arr[j][i];
	answer = get_best(arr, order);
	while(next_permutation(order.begin(), order.end())){
		long long value = get_best(arr, order);
		answer = max(answer, value);
	}
	cout << answer << endl;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
