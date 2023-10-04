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
 

vector<string> s;
vector<Vi> visited;

int dl[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};
string dr = "v>^<";

ll L, C; 
bool  isIn(int cl, int cc){
	if(cl < 0 or cl == L or cc < 0 or cc == C)
		return false;
	return true;
}

void fill(int l, int c, int dir, bool carry){
	if(s[l][c] != '.'){
		visited[l][c] = 1;
		carry = s[l][c] == dr[dir];
	}else{
		visited[l][c] |= carry;	
	}

	int nl = l + dl[dir];
	int nc = c + dc[dir];
	if(isIn(nl, nc))
		fill(nl, nc, dir, carry);
}

void solve(){
	cin >> L >> C;
	pair<int,int> start, goal;
	s.assign(L, "");
	visited.assign(L, Vi(C, 0));
	for(int i = 0; i < L; i++)
		cin >> s[i];
	for(int l = 0; l < L; l++){
		for(int c = 0; c < C; c++){
			if(s[l][c] == 'S'){
				s[l][c] = '.';
				start = {l,c};
			}
			if(s[l][c] == 'G'){
				s[l][c] = '.';
				goal = {l,c};
			}
		}
	}
	for(int c = 0; c < C; c++){
		fill(0, c, 0, 0);
		fill(L-1, c, 2, 0);
	}
	for(int l = 0; l < L; l++){
		fill(l, C-1, 3, 0);
		fill(l, 0, 1, 0);
	}	
	queue<pair<int,int>> q;
	queue<int> d;
	q.push(start);
	d.push(0);
	int ans = -1;
	while(q.size()){
		auto curr = q.front();
		auto dist = d.front();
		if(curr == goal){
			ans = dist;
			break;
		}
		q.pop();
		d.pop();
		for(int i = 0; i < 4; i++){
			int nl = curr.first + dl[i];
			int nc = curr.second + dc[i];
			if(isIn(nl, nc) && !visited[nl][nc]){
				q.push({nl, nc});
				d.push(dist+1);
				visited[nl][nc] = true;
			}
		}
	}
	cout << ans << endl;
	
}


 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
