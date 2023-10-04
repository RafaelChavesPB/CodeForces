#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a;
    cin >> n;
    vector<int> arr(n);
    vector<int> mem(512, -1);
    mem[0] = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        for (int j = 0; j < 512; j++)
        {
            int last = mem[j];
            if (last != -1 and curr > last)
            {
                int curr_xor = curr ^ j;
                if (mem[curr_xor] == -1)
                    mem[curr_xor] = curr;
                else
                    mem[curr_xor] = min(curr, mem[curr_xor]);
            }
        }
    }
    cout << 512 - count(mem.begin(), mem.end(), -1) << endl;
    for (int i = 0; i < 512; i++){
        if(mem[i] != -1)
            cout << i << " ";
    }
    cout << endl;
    return 0;
}