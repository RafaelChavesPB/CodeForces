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
vector<set<int>> filhos;
vector<int> pai;
vector<int> nivel;
vector<int> add;

void dfs(int v, int lvl){
	nivel[v] = lvl;
	bool bifurc = filhos[v].size() > 1;
	for(auto f: filhos[v])
		dfs(f, lvl + 1);
}

void solve(){
	ll n; 
	cin >>n;
	filhos.assign(n+1, set<int>());
	pai.assign(n+1, 1);
	nivel.assign(n+1, -1);
	add.assign(n+1, 0);
	for(int i = 2; i <= n; i++){
		cin >> pai[i];
		filhos[pai[i]].insert(i);
	}
	priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq;
	dfs(1, 0);
	for(int i = 1; i <= n; i++){
		if(filhos[i].size() == 0){
			pq.push({nivel[i], i});
			add[i] = 1;
		}
	}
	int ans = 0;
	while(pq.size() > 1){
		int a = pq.top().second;
		pq.pop();
		filhos[pai[a]].erase(a);
		int b = pq.top().second;
		filhos[pai[b]].erase(b);
		pq.pop();
		ans++;
		if(!add[pai[a]] and filhos[pai[a]].size() == 0){
			pq.push({nivel[pai[a]], pai[a]});
			add[pai[a]] = 1;
		}
		if(!add[pai[b]] and  filhos[pai[b]].size() == 0){
			pq.push({nivel[pai[b]], pai[b]});
			add[pai[b]] = 1;
		}
	}
	cout << ans << endl;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

