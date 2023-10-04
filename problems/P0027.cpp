#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t >> n;
    while(t--){
      int zeros = 0;
      int par = 0;
      int impar = 0;
      for(int i = 0; i < n; i++){
        int a ;
        cin >> a;
        if(a%2)
          impar++;
        else if(a)
          par++;
        else
          zeros++;
      }
      bool A = zeros and !par and impar;
      bool B = par > 1;
      if(A or B){
        cout << "=-(\n";
      }else{
        cout << "=-)\n";
      }
    }
    return 0;
}
