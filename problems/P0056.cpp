#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e3+10;

vector<vector<int>> grafo(MAX);
vector<bool> visitados(MAX);

bool dfs(int v){
    visitados[v] = true;
    for (int i = 0; i < grafo[v].size(); i++){
        if (!visitados[grafo[v][i]]){
            dfs(grafo[v][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, i, j; 
    string line;
    char s;
    cin>> n;
    for (int k = 0; k < n; k++){
        cin >> i >> s;
        getline(cin, line);
        istringstream line_input(line);
        while (line_input >> j){
            grafo[j].push_back(i);
        }
    }
    dfs(1);
    if (visitados[n]){
        cout << "VERY GOOD PROGRAM!" << '\n';
    } else {
        cout << "TOO BAD..." << '\n';
    }
    return 0;
}
