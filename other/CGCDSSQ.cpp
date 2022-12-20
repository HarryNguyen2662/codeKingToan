//huydichepcode
#include<bits/stdc++.h>

typedef long long ll;
typedef float fl;

using namespace std;

const int BASE = 20060529;
const int MOD = 1e9 + 7;

struct Node {
    ll lazy; // giá trị T trong phân tích trên
    ll val; // giá trị lớn nhất.
} nodes[20005];

ll n,i,j,k,res,m,a,b,c,x,y,t,val,N[10005];

void build(ll id, ll l, ll r) {
    if (l == r) {
    	nodes[id].val = N[l];
        return ;
    }
    ll mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid+1, r);

    nodes[id].val = nodes[id*2].val + nodes[id*2+1].val;
}

void down(ll id, ll l, ll r) {
    ll mid = (l + r)/2;
    ll t = nodes[id].lazy;
    nodes[id*2].lazy += t;
    nodes[id*2].val += t*(mid - l + 1);

    nodes[id*2+1].lazy += t;
    nodes[id*2+1].val += t*(r - mid);

    nodes[id].lazy = 0;
}

void update(ll id, ll l, ll r, ll u, ll v, ll val) {
    if (v < l || r < u) {
        return ;
    }
	if (u <= l && r <= v) {
        nodes[id].val += val*(r - l + 1);
        nodes[id].lazy += val;
        return ;
    }
    ll mid = (l + r) / 2;
    down(id, l, r); 
    update(id*2, l, mid, i, v, val );
    update(id*2 + 1, mid+1, r, i, v, val);
    nodes[id].val = nodes[id*2].val + nodes[id*2+1].val;
}

ll get(ll id, ll l, ll r, ll u, ll v) {
    if (v < l || r < u) {
        return 0;
    }
	if (u <= l && r <= v) {
        return nodes[id].val;
    }
    ll mid = (l + r) / 2;  
	down(id, l , r);
    return (get(id*2, l, mid, u, v) + get(id*2 + 1, mid+1, r, u, v));
} 


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	cout.tie(NULL);
//	freopen("input.txt","r", stdin);
//	freopen("output.txt","w", stdout);
	cin >> n >> t;
	for (i = 1; i <= n; i ++ ){
		cin >> N[i];
	}
	build(1, 1, n);
	
	for (i = 1; i <= t; i ++ ){
		cin >> k;
		if (k == 2){
			cin >> x >> y;
			cout << get(1, 1, n, x, y) << "\n";
		}
		else{
			cin >> x >> y >> val;
			update(1, 1, n, x, y, val);
		}
	}
	return 0;
}

//mision completed

