#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    vector<multiset<int>> box(n+1);
    map<int, set<int>> cards;
    for(int k = 0, t, i, j; k < q; k++){
        cin >> t;
        if(t == 1){
            cin >> i >> j;
            box[j].insert(i);
            cards[i].insert(j);
        } else if(t == 2){
            cin >> j;
            for(auto it: box[j])
                cout << it << " ";
            cout << endl;
        } else{
            cin >> j;
            for(auto it: cards[j]){
                cout << it << " ";
            }
            cout << endl;
        }
    }
    return 0;
}