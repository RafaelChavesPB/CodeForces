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

typedef struct Node {
	map<char, Node> child_tries;
	int index;
	Node(){
	}
	Node(int idx){
		this-> index = idx;
	}
} node;

typedef struct State {
	int index;
	int i;
	int stage;
	bool value;
} state;

ll n, m, cont = 0; 
string s, t;
node root(cont++);
vector<node*> nodes_pack{&root};

vector<vector<bool>> visited(200, vector<bool>(200'000, false)), pd(200, vector<bool>(200'000, false));

void solve(){
	cin >> n >> m;
	cin >> s >> t;
	for(int i = 0; i < m; i++){
		node *curr_node = &root;
		for(int j = i; j <= m; j++){
			if(j == m){
				curr_node->child_tries['r'] = node(cont++);
				nodes_pack.push_back(&(curr_node->child_tries['r']));
				continue;
			}
			if(curr_node->child_tries.find(t[j]) == curr_node->child_tries.end()) {
				curr_node->child_tries[t[j]] = node(cont++);
				nodes_pack.push_back(&(curr_node->child_tries[t[j]]));

			}
			curr_node = &(curr_node->child_tries[t[j]]);
		}
		
	}
	
	bool value;
	stack<state> stk;
	stk.push({0, 0, 0, false});
	state curr_state;
	node* curr_node;
			
	while(stk.size()){
		curr_state = stk.top();
		curr_node = nodes_pack[curr_state.index];
		stk.pop();
		if(curr_state.i == n){
			value = curr_node->child_tries.find('r') != curr_node->child_tries.end();
			continue;
		}
		if(visited[curr_state.index][curr_state.i]){
			value = pd[curr_state.index][curr_state.i];
			continue;
		}
		if(curr_state.stage == 0){
			value = false;
			curr_state.stage = 1;
			stk.push(curr_state);
			if(curr_node->child_tries.find(s[curr_state.i]) != curr_node->child_tries.end()){
				stk.push({curr_node->child_tries[s[curr_state.i]].index, curr_state.i+1, 0, false});
			}
		} else if(curr_state.stage == 1){
			curr_state.value = value;
			value = false;
			curr_state.stage = 2;
			stk.push(curr_state);
			if(s[curr_state.i] == t[0]){
				stk.push({root.child_tries[t[0]].index, curr_state.i+1, 0, false});
			}

		} else if(curr_state.stage == 2){
			curr_state.value = curr_state.value or value;
			value = false;
			curr_state.stage = 3;
			stk.push(curr_state);
			if(curr_node->child_tries.find('r') != curr_node->child_tries.end()){
				 stk.push({root.index, curr_state.i, 0, false});
			}
		} else if(curr_state.stage == 3){
			value = value or curr_state.value;
			visited[curr_state.index][curr_state.i] = 1;
			pd[curr_state.index][curr_state.i] = value;
		}
	}
	cout << (value?"Yes":"No") << endl;
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
