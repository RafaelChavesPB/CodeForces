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
    	ll n; 
    	cin >>n;
    	vector<int> botouMedo(n+1), valor(n+1), adj(n+1), ans;
    	ans.reserve(n);
    	for(int i = 1; i <= n; i++){
    		cin >> adj[i];
    		botouMedo[adj[i]]++;
    	}
    	
    	queue<int> q;
    	for(int i = 1; i <= n; i++){
    		cin >> valor[i];
    		if(botouMedo[i] == 0)
    			q.push(i);
    	}
    	bugV(botouMedo);
     
    	while(q.size()){
    		int v = q.front();
    		q.pop();
    		cout << v << ' ';
    		if(--botouMedo[adj[v]] == 0)
    			q.push(adj[v]);
    	}
     
    	for(int i = 1; i <= n; i++){
    		if(botouMedo[i] > 0){
    			int curr = adj[i];
    			pair<int,int> worst = {valor[i], i};
    			while(curr != i){
    				worst = min(worst, {valor[curr], curr});
    				curr = adj[curr];
    			}
    			q.push(adj[worst.second]);
    			while(q.size()){
    				botouMedo[q.front()] = 0;
    				cout << q.front() << ' ';
    				int next = adj[q.front()];
    				q.pop();
    				if(botouMedo[next] > 0)
    					q.push(next);
    			}
    		}
    	}
    	cout << '\n';
    }
     
    int main(){
    	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    	int t;
    	cin >> t;
    	while(t--)
    		solve();
    	return 0;
    }
