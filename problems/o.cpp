#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, idx_counter = 0; 
        char s;
        string a, b;
        vector<int> mask(30, -1);
        cin >> n >> k;

        cin >> a >> b;
        for(auto c: a)
            if(mask[c-'a']== - 1)
                mask[c-'a'] = 1 << idx_counter++;

        long long ans = 0;
        for(int SET = 0; SET < (1 << (idx_counter)); SET++){
            long long  acc = 0;
            if(__builtin_popcount(SET) > k)
                continue;
            long long  seq_size = 0;
            for(int i = 0; i < n; i++){
                s = a[i];
                if(b[i] == s || mask[s-'a'] & SET){
                    seq_size++;
                }else{
                    acc += ((seq_size + 1)*seq_size)/2;
                    seq_size = 0;
                }
            }
            acc += ((seq_size + 1)*seq_size)/2;
            ans = max(acc, ans);
        }
        cout << ans << '\n';
        
    }
}