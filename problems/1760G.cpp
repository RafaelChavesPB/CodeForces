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
     
    vector<vector<pair<int,int>>> adj;
     
    void dfs(int v, int blocked, int father, int xortotal, set<int> &mem){
            for(auto nk: adj[v]){
                    if(nk.first != blocked and nk.first != father){
                            mem.insert(xortotal ^ nk.second);
                            dfs(nk.first, blocked, v, xortotal ^ nk.second, mem);
                    }
            }
    }
     
    void solve(){
            ll n, a, b;
            cin >> n >> a >> b;
            adj.assign(n+1, vector<pair<int,int>>());
            for(int i = 1, u, v, k; i < n; i++){
                    cin >> u >> v >> k;
                    adj[u].push_back({v,k});
                    adj[v].push_back({u,k});
            }
            set<int> axor, bxor;
            dfs(a, b, -1, 0, axor);
            dfs(b, -1, -1, 0, bxor);
	    axor.insert(0);
            Vi intersection;
            set_intersection(all(axor), all(bxor), back_inserter(intersection));
            cout << (intersection.size()?"YES":"NO") << '\n';
    }
     
    int main(){
            ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
            int t;
            cin >> t;
            while(t--)
                    solve();
            return 0;
    }
