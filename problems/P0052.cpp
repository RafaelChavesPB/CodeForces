#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    for(char i = 'a'; i < 'z'; i++){
      for(char j = i+1; j <= 'z'; j++){
        int acc = 0;
        for(auto c: s){
          if(c == i or c == j){
            ans = max(ans, ++acc);
          }else{
            acc = 0;
          }
        }
      }
    }
    cout << ans << '\n';
    return 0;
}
