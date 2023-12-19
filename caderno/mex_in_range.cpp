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
 
	#define bugL() { cout << "----------"<<endl; }
#else
	#define bug(x) { ; }
	#define bug2(x,y) { ; }
	#define bugV(V) { ; }
	#define bugP(V) { ; }
	#define bugL() { ; }
#endif
 
#define all(v) v.begin(), v.end()
#define TAM 200'001
typedef struct Query {
	ll l, r, order, ans;
} query;


ll seg[5*TAM];

void update(ll node, ll l, ll r, ll x, ll p){
	if(l == r){
		seg[node] = p;
		return;
	}
	ll m = (l+r)/2;
	if(x <= m)
		update(2*node, l, m, x, p);
	else
		update(2*node + 1, m + 1, r, x, p);
	seg[node] = min(seg[2*node], seg[2*node + 1]); 
}

//Retorna a menor posição que possui valor menor que Q
ll search(ll node, ll l, ll r, ll q){
	if(l == r)
		return l;
	ll m = (l+r)/2;
	if(seg[2*node] < q)
		return search(2*node, l, m, q);
	return search(2*node + 1, m+1, r, q);
}

void solve(){
	ll n, q; 
	cin >> n;
	vector<ll> arr(n + 1);
	for(ll i = 1; i <= n; i++){
		cin >> arr[i];
		arr[i]++;
	}
	cin >> q;
	vector<query> queries(q);
	for(ll i = 0; i < q; i++){
		cin >> queries[i].l >> queries[i].r;
		queries[i].order = i;
	}
	sort(all(queries), [](const query &a, const query &b){return a.r <= b.r;});
	ll curr_r = 0;
	for(auto &it: queries){
		while(curr_r < it.r)
		{
			curr_r++;
			update(1, 1, TAM, arr[curr_r], curr_r);
		}
		it.ans = search(1, 1, TAM, it.l);
	}
	sort(all(queries), [](const query &a, const query &b){return a.order <= b.order;});
	for(auto it: queries)
		cout << it.ans - 1 << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
