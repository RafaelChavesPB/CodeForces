#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, s1, s2;
        cin >> n >> s1 >> s2;
        vector<pair<int,int>> r(n);
        for(int i = 0; i < n; i++){
            cin >> r[i].first;
            r[i].second = i + 1;
        }
        sort(r.begin(), r.end(), greater<pair<int,int>>());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for(int i = 1; i<= n; i++){
            q.push({i*s1,0});
            q.push({i*s2,1});
        }
        vector<int> a, b;
        pair<int,int> top;
        for(int i = 0; i < n; i++){
            top = q.top();
            q.pop();
            if(top.second)
                b.push_back(r[i].second);
            else
                a.push_back(r[i].second);
        }
        cout << a.size();
        for(auto it: a)
            cout << " " << it;
        cout << "\n" << b.size();
        for(auto it: b)
            cout << " " << it;
        cout << endl;
    }
}