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

typedef struct Node {
	int greater = 0;
	int lesser = 0;
	int curr_greater = 0;
	int curr_lesser = 0;
} node;

void solve(){
	ll n; 
     	cin >>n;
	vector<node> arr(2);
	arr[1] = {1, 0, 1, 0};
	while(n--){
		string op;
		cin >> op;
		if(op == "+"){
			int u, p;
			cin >> u >> p;
			node newnode;
			newnode.curr_greater = max(0, arr[u].curr_greater+ p);
			newnode.curr_lesser = min(0, arr[u].curr_lesser + p);
			newnode.greater = max(arr[u].greater, newnode.curr_greater);
			newnode.lesser = min(arr[u].lesser, newnode.curr_lesser);
			arr.push_back(newnode);
		}else{
			int u, v, p;
			cin >> u >> v >> p;
//			bug(p);
//			bug2(arr[v].lesser, arr[v].greater);
			if(arr[v].lesser <= p and  p <= arr[v].greater){
				cout << "YES\n";
			}else{
				cout << "NO\n";
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
