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
	bool flag = true;
	string s;
	cin >> s;
	stack<char> p;
	p.push('1');
	for(auto c: s){
		if(c == '+'){
			if(p.top() == '0'){
				p.push('0');
			}else if(p.top() == '1'){
				p.push('?');
			}else if(p.top() == '?'){
				p.push('?');
			}
		}
		if(c == '-'){
			char last = p.top();
			p.pop();
			if(last == '1'){
				if(p.top() == '?'){
					p.top() = '1';
				}else if(p.top() == '0'){
					flag = false;
					break;
				}
			}
		}
		if(c == '1'){
			if(p.top() == '0'){
				flag = false;
				break;
			}
			if(p.top() == '?'){
				p.top() = '1';	
			}
		}
		if(c == '0'){

			if(p.top() == '1' or p.size() <= 2){
				flag = false;
				break;
			}
			if(p.top() == '?'){
				p.top() = '0';
			}
		}
	}
	if(flag){
		cout << "YES\n";
	}else{
		cout << "NO\n";
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
