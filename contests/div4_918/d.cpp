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

bool isVowel(char a){
	return a == 'a' or a == 'e';
}

void solve(){
	ll n; 
	cin >>n;
	string s;
	// b c d
	// a b
	cin >> s;
	string curr;
	vector<string> ans;
	for(int i = n-1; i >= 0; i--){
		if(isVowel(s[i])){
			ans.push_back(s.substr(i-1, 2));
			i -= 1;
		}else{
			ans.push_back(s.substr(i-2, 3));
			i -= 2;
		}
		//	cout << ans.back() << endl;
	}
	reverse(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++){
		if(i) cout << '.';
		cout << ans[i];
	}
	cout << endl;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
