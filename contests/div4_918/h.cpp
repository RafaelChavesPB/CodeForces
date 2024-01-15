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
	ll n, m; 
	cin >> n >> m;
	vector<vector<pair<ll,ll>>> adj(n+1);
	vector<ll> distances(n+1, 12345678912345);
	for(int i = 0, a, b, w; i < m; i++){
		cin >> a >> b >> w;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}
	vector<ll> s(n+1); for(int i = 1; i <= n; i++) cin >> s[i];
	priority_queue<array<ll,3>> pq;
	distances[1] = 0;
	pq.push({0, 1, s[1]});
	while(pq.size()){
		ll d = pq.top()[0];
		ll u = pq.top()[1];
		ll b = pq.top()[2];
		pq.pop();
		bug(u)
		for(auto v:adj[u]){
			if(v.second*b + distances[u]  < distances[v.first]){
				distances[v.first] = v.second*b + distances[u];
				pq.push({-distances[v.first], v.first, min(s[v.first], b)});
			}
		}
	}
	cout << distances[n] << endl;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
