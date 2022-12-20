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

struct NODE
{
	int sum, le, re;

	NODE(int _sum = 0, int _le = 0, int _re = 0)
	{
		sum = _sum; le = _le; re = _re;
	}
};

NODE seg[3500000];
int ri[100005], li[100005], cnt = 0, ver[100005];
vector<int> ldk[100005];

int update(int l, int r, int u, int val, int oid)
{
	if (l == r)
	{
		++cnt;
		seg[cnt] = NODE(seg[oid].sum + val, 0, 0);
		return cnt;
	}

	int cur = ++cnt;
	int mid = (l + r) >> 1; 

	if (u <= mid)
	{
		seg[cur].re = seg[oid].re;
		seg[cur].le = update(l, mid, u, val, seg[oid].le);
		seg[cur].sum = seg[seg[cur].le].sum + seg[seg[cur].re].sum;
	}
	else
	{
		seg[cur].le = seg[oid].le;
		seg[cur].re = update(mid + 1, r, u, val, seg[oid].re);
		seg[cur].sum = seg[seg[cur].le].sum + seg[seg[cur].re].sum;
	}

	return cur;
}

int get(int id, int l, int r, int u, int v)
{
	if (id == 0 || l > v || r < u) return 0;

	if (u <= l && r <= v)
	{
		return seg[id].sum;
	}

	int mid = (l + r) >> 1;

	return get(seg[id].le, l , mid, u, v) + get(seg[id].re, mid + 1, r, u, v);
}

int cmt = 0, vit[100005];
vector<int> a[100005];

void dfs(int u)
{
	vit[u] = ++cmt;

	for (auto v : a[u]) if (vit[v] == 0)
	{
		dfs(v);
	}
}

void solve() 
{
	int n, m, q, s;

	cin >> n >> m >> q >> s;

	for (int i = 1; i <= n; i++)
	{
		ri[i] = oo;
	}

	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}

	for (int i = 1; i <= n; i++) if (vit[i] == 0)
	{
		dfs(i);
	}

	for (int i = 1; i <= n; i++) for (auto j : a[i])
	if (vit[j] < vit[i])
	{
		if (j < i) li[i] = max(li[i], j);
		else ri[i] = min(ri[i], j);
	}

	for (int i = 1; i <= n; i++)
	{
		// cout << li[i] << " " << i << " " << ri[i] << "\n";

		if (li[i]) ldk[i].pb(li[i]);
		
		if (ri[i] < oo) ldk[ri[i]].pb(i);

		if (li[i] && ri[i] < oo) ldk[ri[i]].pb(-li[i]);
		// else if (li[i]) ldk[i].pb(-li[i]); 
		// else if (ri[i] < oo) ldk[ri[i]].pb(-i);
	}

	for (int i = 1; i <= n; i++)
	{
		ver[i] = ver[i-1];
		for (auto v : ldk[i])
		{
			if (v < 0)
			ver[i] = update(1, n, -v, -1, ver[i]);
			else
			ver[i] = update(1, n, v, 1, ver[i]);
		}
	}
	int ans = 0;
	while(q--)
	{
		int l, r;
		cin >> l >> r;
		l = (l + s*ans - 1)%n; if (l < 0) l += n; l++;
		r = (r + s*ans - 1)%n; if (r < 0) r += n; r++;

		if (l > r) swap(l, r);

		// cout << l << " " << r << endl;
		ans = r - l + 1 - get(ver[r], 1, n, l, r);
		cout << ans << "\n";
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
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
