#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
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

int lazy[1000005], sg[1000005], pa[100005], cs[100005], id[100005], cnt, cmt;
int in[100005], out[100005], child[100005], st[100005], c[100005], w[100005], mx[100005];

vector<int> a[100005];
long long p[100005];


class fenwicktree {
private:
    int len;
    vector<int> fen;
 
public:
    void reset(int sz) {
    	fen.assign(sz + 3, 0);
        len = sz;
    }
 
    void update(int id, int val)
    {
    	for (; id <= len; id += (id&(-id))) fen[id] += val;
    }

	int get(int id)
	{
		int res = 0;
		for (; id; id -= (id&(-id))) res += fen[id];
		return res;
	}
};

void dolazy(int id)
{
	for (int i =id*2; i <= id*2 + 1; i++)
	{
		sg[i] += lazy[id];
		lazy[i] += lazy[id];
	}

	lazy[id] = 0;
}

void upd(int id, int l, int r, int u, int v, int val)
{
	if (l > v || r < u) return;

	if (u <= l && r <= v)
	{
		sg[id] += val;
		lazy[id] += val;
		return;
	}

	dolazy(id);

	int mid = (l + r)/2;

	upd(id*2, l, mid, u, v, val); upd(id*2+1, mid + 1, r, u, v, val);

	sg[id] = min(sg[id*2], sg[id*2 + 1]);
}


int get(int id, int l, int r, int u, int v)
{
	if (l > v || r < u) return 2*oo;

	if (u <= l && r <= v)
	{
		return sg[id];
	}

	dolazy(id);

	int mid = (l + r)/2;

	return min(get(id*2, l, mid, u, v), get(id*2+1, mid + 1, r, u, v));
}

void dfs(int u)
{
	child[u] = 1;
	in[u] = ++cnt;

	for (auto v : a[u]) 
	{
		dfs(v);

		if (child[v] > child[mx[u]]) mx[u] = v;

		child[u] += child[v];
	}

	out[u] = ++cnt;
}

void hld(int u)
{

	if (st[cnt] == 0) st[cnt] = u;

	id[u] = cnt;

	cs[u] = ++cmt;

	if (mx[u]) hld(mx[u]);

	for (auto v : a[u]) if (v != mx[u])
	{
		cnt++;
		hld(v);
	}
}

void update(int u, int v, int val)
{
	if (id[u] != id[v])
	{
		upd(1, 1, cmt, cs[st[id[u]]], cs[u], val);
		update(pa[st[id[u]]], v, val);
		return;
	}

	upd(1, 1, cmt, cs[v], cs[u], val);
}

int getmin(int u, int v)
{
	if (id[u] != id[v])
	{
		int val = get(1, 1, cmt, cs[st[id[u]]], cs[u]);

		return min(val, getmin(pa[st[id[u]]], v));
	}

	return get(1, 1, cmt, cs[v], cs[u]);
}


void solve() 
{
	int n, t;
	int root;
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
	{
		int u;
		cin >> p[i] >> u >> w[i];
		if (u == 0) root = i;
		else a[u].pb(i);

		pa[i] = u;

		c[i] = i;
	}

	sort(c + 1, c + 1 + n, [](const int &x, const int &y)
		{
			return p[x] < p[y];
		});
		
	fenwicktree dk;
	dfs(root);
	dk.reset(cnt);
	cnt = 1;

	hld(root);

	for (int i = 1; i <= n; i++)
	{
		update(i, i, w[i]);
	}

	long long res = 0;

	for (int i = n; i; i--) 
	{
		int id = c[i];

		if (dk.get(out[id]) - dk.get(in[id] - 1)) continue;

		int cur = getmin(id, root);

		res += 1ll*cur*p[id];

		t -= cur; if (t == 0) break;

		update(id, root, -cur);
		dk.update(in[id], 1); dk.update(out[id] + 1, -1);
	}

	cout << res;
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
