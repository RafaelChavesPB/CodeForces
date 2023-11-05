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
 
pair<ll, ll> ballons_penalty(int m, int limit){
	vector<ll> time(m);
	for(int i = 0; i < m; i++)
		cin >> time[i];
	sort(all(time));
	for(int i = 1; i < m; i++)
		time[i] += time[i-1];
	ll amount = upper_bound(all(time), limit) - time.begin();
	for(int i = 1; i < amount; i++)
		time[i] += time[i-1];
	ll penalty = amount?time[amount - 1]:0;
	return {amount, -penalty};
}

void solve(){
	ll n, m, limit; 
	cin >> n >> m >> limit;
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, less<pair<ll,ll>>> pq;
	pair<ll,ll> player = ballons_penalty(m, limit);
	for(int i = 1; i < n; i++)
		pq.push(ballons_penalty(m, limit));
	ll pos = 1;
	bug2(player.first, player.second);
	while(pq.size() and player < pq.top()){
		pq.pop();
		pos++;
	}
	cout << pos << '\n';

}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
