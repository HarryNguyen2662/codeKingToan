#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
#define fi first
#define se second
#define pb push_back
#define log 17
#define mask(i) (1ll << (i))
#define setp(x) setprecision(x)
#define ALL(v) v.begin(), v.end()
#define ck(n, i) (((n) >> (i)) & 1) 
#define getbit(x) __builtin_popcount(x)

const double PI = acos(-1);
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node
{
	int le, ri; ll sum;



	node(ll _sum = 0, int _le = 0, int _ri = 0)
	{
		le = _le; ri = _ri; sum = _sum;
	}
} sg[5000005];

int cnt = 0, ve[400005], a[100005], ans[100005];

vector<pair<pair<int,int>, pair<int,int>>> ldk[100005];

int update(int l, int r, int u, int val, int oid)
{
	if (l == r)
	{
		cnt++; sg[cnt] = node(sg[oid].sum + val, 0, 0);
		return cnt;
	}

	int mid = (l + r) >> 1; int cu = ++cnt;

	if (u <= mid)
	{
		sg[cu].le = update(l, mid, u, val, sg[oid].le);
		sg[cu].ri = sg[oid].ri;
		sg[cu].sum = sg[sg[cu].le].sum + sg[sg[cu].ri].sum;
	}	
	else
	{
		sg[cu].le = sg[oid].le;
		sg[cu].ri = update(mid + 1, r, u, val, sg[oid].ri);
		sg[cu].sum = sg[sg[cu].le].sum + sg[sg[cu].ri].sum;
	}

	return cu;
}

ll get(int id, int l, int r, int u, int v)
{
	if (id == 0) return 0;
	if (u > r || v < l) return 0;

	if (u <= l && r <= v)
	{
		return sg[id].sum;
	}

	int mid = (l + r) >> 1;

	return get(sg[id].le, l, mid, u, v) + get(sg[id].ri, mid + 1, r, u, v);
}

int find(int id, int id1, int l, int r, ll re)
{
	if (sg[id1].sum - sg[id].sum < re) return 0;

	if (l == r) return l;

	int mid = (l + r) >> 1;

	if (sg[sg[id1].ri].sum - sg[sg[id].ri].sum >= re) return find(sg[id].ri, sg[id1].ri, mid + 1, r, re);
	else return find(sg[id].le, sg[id1].le, l, mid, re - sg[sg[id1].ri].sum + sg[sg[id].ri].sum);
}

vector<int> diff, id[300005];
int n, q;

int cal(int st, int u, int v, int k)
{
	v = lower_bound(ALL(diff), v) - diff.begin() + 1;
	u = lower_bound(ALL(diff), u) - diff.begin() + 1;

	ll re = get(ve[v], 1, n, st, n) - get(ve[u], 1, n, st, n) - k;

	return max(0, find(ve[u], ve[v], 1, n, re) - st);
}

void solve() 
{
	vector<pair<pair<int,int>, pair<int,int>>> luu;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		diff.pb(a[i]);
	}
	n++; a[n] = 0; diff.pb(0); 

	for (int i = 1; i <= q; i++)
	{
		int l, u, v, k;
		cin >> l >> u >> v >> k; u--;
		luu.pb({{l, k}, {u, v}});
		diff.pb(u); diff.pb(v);
	}
	sort(ALL(diff)); diff.resize(unique(ALL(diff)) - diff.begin());


	for (int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(ALL(diff), a[i]) - diff.begin() + 1;
		id[a[i]].pb(i);
	}


	for (int i = 1; i <= (int)diff.size(); i++)
	{
		ve[i] = ve[i-1];
		for (auto v : id[i]) ve[i] = update(1, n, v, diff[i-1], ve[i]);
	}

	for (auto v : luu)
	{
		cout << cal(v.fi.fi, v.se.fi, v.se.se, v.fi.se) << "\n";
	}

}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("SHOPPING.inp","r",stdin); freopen("SHOPPING.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
