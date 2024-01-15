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
	vector<vector<pair<ll, ll>>> graph(n+1);
	for(int i = 0, a, b, w; i < m; i++){
		cin >> a >> b >> w;
		graph[a].push_back({b, w});
		graph[b].push_back({a, w});
	}
	vector<ll> s(n+1);
	for(int i = 1; i <= n; i++){
		cin >> s[i];
	}
	vector<vector<ll>> distances(n+1, vector<ll>(s.size()+1, LLONG_MAX));
	priority_queue<array<ll,3>> pq;
	pq.push({0, 1, 1});
	while(pq.size()){
		ll curr_distance = -pq.top()[0];
		ll curr_city = pq.top()[1];
		ll curr_bycicle = (s[pq.top()[2]] < s[curr_city]?pq.top()[2]:curr_city);
		pq.pop();
		if(distances[curr_city][curr_bycicle] < curr_distance) continue;
		for(auto [u, w]: graph[curr_city]){
			ll new_distance = curr_distance + w*s[curr_bycicle];
			if(new_distance < distances[u][curr_bycicle]){
				distances[u][curr_bycicle] = new_distance;
				pq.push({-new_distance, u, curr_bycicle});
			}
		}
	}
	ll answer = LLONG_MAX;
	for(auto it: distances[n])
		answer = min(answer, it);
	cout << answer << endl;;

}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
