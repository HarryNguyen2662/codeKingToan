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

vector<int> a[100005];
int cnt = 0, high[100005], lca[100005][log + 5], n, q, in[100005], out[100005];
long long fen[200005], fen1[200005], fen2[100005];

void dfs(int u, int par)
{
	in[u] = ++cnt;
	high[u] = high[par] + 1;
	lca[u][0] = par;
	for (auto v : a[u]) if (v != par) dfs(v, u);
	out[u] = ++cnt;
}

int findlca(int u, int v)
{
	if (high[u] < high[v]) swap(u, v);

	for (int i = log; i >= 0; i--) if (high[lca[u][i]] >= high[v]) u = lca[u][i];

	if (u == v) return u;

	for (int i = log; i >= 0; i--) if (lca[u][i] != lca[v][i])
	{
		u = lca[u][i]; v = lca[v][i];
	}

	return lca[u][0];
}

void update(int id, int val)
{
	for (; id <= cnt; id += (id&(-id))) fen[id] += val;
}

long long get(int id)
{
	long long res = 0;
	for (; id; id -= (id&(-id))) res += fen[id];
	return res;
}

void update1(int id, int val)
{
	if (id == 0) return;
	for (; id <= cnt; id += (id&(-id))) fen1[id] += val;
}

long long get1(int id)
{
	long long res = 0;
	for (; id; id -= (id&(-id))) res += fen1[id];
	return res;
}

void update2(int id, int val)
{
	for (; id <= n; id += (id&(-id))) fen2[id] += val;
}

long long get2(int id)
{
	long long res = 0;
	for (; id; id -= (id&(-id))) res += fen2[id];
	return res;
}

void solve() 
{
	cin >> n >> q;
	
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}

	dfs(1, 0);

	for (int i = 1; i <= log; i++) for (int j = 1; j <= n; j++) lca[j][i] = lca[lca[j][i-1]][i-1];

	long long su = 0, susu = 0, sususu = 0;

	while(q--)
	{
		int type;
		cin >> type;

		if (type <= 2)
		{
			int u, val;
			cin >> u >> val;
			if (type == 2)
			{
				su += val;
				val = -val;
			}
			update(in[u], val); update(out[u] + 1, -val);
		}
		else if (type <= 4)
		{
			int u, v, val;
			cin >> u >> v >> val;
			int uv = findlca(u, v);
			if (type == 4)
			{
				susu += val;
				val = -val;
			}
			//cout << in[u] << " " << in[v] << " " << in[uv] << endl;
			//cout << in[4] << endl;
			update1(in[u], val); update1(in[v], val); update1(in[uv], -2*val); 
			update2(uv, val); update2(uv + 1, - val);

		}
		else if (type <= 6)
		{
			int u, v, val;
			cin >> u >> v >> val;
			if (type == 6)
			{
				sususu += val;
				val = -val;
			}
			update2(u, val); update2(v + 1, -val);
		}
		else
		{
			int u;
			cin >> u;
			cout << su + susu + sususu + get(in[u]) + get1(out[u]) - get1(in[u] - 1) + get2(u) << "\n"; 
		}	

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
