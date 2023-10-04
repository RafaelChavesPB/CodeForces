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
	string n; 
	cin >> n;
	for(int i = 0; i < n.size() - 1; i++){
		for(int j = i+1; j < n.size(); j++){
			int num = (n[i]-'0')*10 + (n[j]-'0');
			bool flag = true;
			for(int k = 2; k <= sqrt(num); k++){
				if(num % k == 0){
					flag = false;
					break;
				}
			}
			if(flag){
				cout << num << endl;
				return;
			}
		
		}	
	}
	cout << -1 << endl;
	return;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
