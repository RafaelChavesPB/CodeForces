#include <bits/stdc++.h>
#define LIM 100000
using namespace std;

typedef long long ll;

namespace seg {
	ll array[LIM];
	ll segtree[4*LIM];
	void build(int idx, int l, int r){
		if(l == r){
			segtree[idx] = array[l];
			return ;
		}
		int m = (l+r)/2;
		build(2*idx, l, m);
		build(2*idx + 1, m+1, r);
		segtree[idx] = segtree[2*idx] + segtree[2*idx + 1];
	}

	ll query(int idx, int ql, int qr, int l, int r){
		
		if(ql <= l  and r <= qr){
			return segtree[idx];
		}

		if(r < ql or qr < l){
			return 0;
		}

		int m = (l + r)/2;
		return query(2*idx, ql, qr, l, m) + query(2*idx + 1, ql, qr, m + 1, r);
	}

	void update(int idx, int pos, int val, int l, int r){
		if(l == r){
			segtree[idx] = val;
			array[pos] = val;
			return;
		}

		int m = (l + r)/2;
		if(pos <= m)
			update(2*idx, pos, val, l, m);
		else 
			update(2*idx + 1, pos, val, m+1, r);

		segtree[idx] = segtree[2*idx] + segtree[2*idx + 1];
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> seg::array[i];
	seg::build(1, 1, n);
	while(m--){
		int op;
		cin >> op;
		if(op == 1){
			int pos, val;
			cin >> pos >> val;
			seg::update(1, ++pos, val, 1, n);
		}else{
			int ql, qr;
			cin >> ql >> qr;
			cout << seg::query(1, ++ql, qr, 1, n) << '\n';
		}
	}
}
