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
 
void solve(){
	ll n; 
	cin >>n;
	vector<int>freq(200'000+1, 0);
	vector<ll> arr(n); for( auto &it: arr) 
	{
		cin >> it;
		freq[it]++;
	}
	int best = 0, qtd = 0;
	for(int i = 0; i <= 200'000; i++){
		if(freq[i] > qtd){
			best = i;
			qtd = freq[i];
		}
	}
	cout << n - qtd << '\n';
	queue<int> q;
	for(int i = 0; i < n; i++){
		if(arr[i] == best){
			q.push(i);			
		}
	}
	while(q.size()){
		int i = q.front();
		q.pop();
		if(i != 0){
			if(arr[i-1] != best){
				cout << (arr[i-1] > best?2:1) << ' ' << i << ' ' << i + 1<< '\n';
				arr[i-1] = best;
				q.push(i-1);
			}
		}
		if(i != n-1){
			if(arr[i+1] != best){
				cout << (arr[i+1] > best?2:1) << ' ' << i + 2 << ' ' << i + 1<< '\n';
				arr[i+1] = best;
				q.push(i+1);
			}
		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
		solve();
	return 0;
}
