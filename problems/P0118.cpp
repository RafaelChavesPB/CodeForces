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

pair<ll, ll> arr[1000000];

pair<ll, ll> create_hash(string &word){
	int first = word.size() - 10 - 1;
	int second =  word.size() - 1;
	pair<ll, ll> word_hash = {0,0};
	for(int i = second, bit = 0; i > first and i >= 0; i--, bit++)
		word_hash.second |= (1LL*word[i] - 'a') << 5*bit;
	for(int i = first, bit = 0; i >= 0; i--, bit++)
		word_hash.first |=  (1LL*word[i] - 'a') << 5*bit;
	return word_hash;
}
void solve(){
	int n, m, w;
	string s;
	cin >> n >> m;
	w = n*m;
	for(int i = 0; i < w; i++){
		cin >> s;
		arr[i] = create_hash(s);
	}
	int q;
	cin >> q;
	while(q--){
		cin >> s;
		auto word_hash = create_hash(s);
		cout << (lower_bound(arr, arr + w, word_hash) - arr)/m + 1 << '\n';
	}
}

 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
