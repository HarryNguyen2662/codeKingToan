#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

int sz[100005], high[100005], lca[100005][log + 3], dd[100005], id[100005], ed[100005];
vector<int> a[100005];

class segmentree {
private:
    int len;
    vector<int> sg, lazy;

    void dolazy(int id)
    {
    	for (int i = id*2; i <= id*2 + 1; i++)
    	{
    		sg[i] += lazy[id];
    		lazy[i] += lazy[id];
    	}
    	lazy[id] = 0;
    }

    void uptt(int id, int l, int r, int u, int v, int val)
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

 		uptt(id*2, l, mid, u, v, val); uptt(id*2 + 1, mid + 1, r, u, v, val);

 		sg[id] = max(sg[id*2], sg[id*2 + 1]);
    }

    int getmaxx(int id, int l, int r, int u, int v)
	{
		if (l > v || r < u) return 0;

		if (u <= l && r <= v)
		{
			return sg[id];
		}

		dolazy(id);
		int mid = (l + r)/2;

		return max(getmaxx(id*2, l, mid, u, v), getmaxx(id*2+1, mid + 1, r, u, v));
	} 	

public:

	void reset(int _len = 0)
	{
		lazy.assign(4*_len + 2, 0);
		sg.assign(4*_len + 2, 0);
		len = _len;
	}

	void upt(int l, int r, int val)
	{
		uptt(1, 1, len, l, r, val);
	}

	int getmax()
	{
		return sg[1];
	}
    
 
};

int cnt = 0, cmt = 0;
segmentree ma[100005];

void dfs(int u, int par)
{
	int mx = 0;
	sz[u] = 1;
	lca[u][0] = par;
	high[u] = high[par] + 1;

	for (auto v : a[u])
	if (v != par)
	{
		dfs(v, u);
		sz[u] += sz[v];
		if (sz[v] > sz[mx]) mx = v;
	}

	if (mx == 0)
	{
		cnt++;
		dd[u] = cnt;
		id[u] = 1;
	}
	else
	{
		dd[u] = dd[mx];
		id[u] = id[mx] + 1;
	}

	for (auto v : a[u]) if (v != par && v != mx)
	{	
		ed[dd[v]] = v;
	}
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

multiset<int> st;

void update(int u, int v, int val)
{
	if (dd[u] != dd[v])
	{
		st.erase(st.find(ma[dd[u]].getmax()));
		ma[dd[u]].upt(id[u], id[ed[dd[u]]], val);
		st.insert(ma[dd[u]].getmax());
		
		u = ed[dd[u]]; 
		u = lca[u][0];
		update(u, v, val);
	}
	else
	{
		st.erase(st.find(ma[dd[u]].getmax()));
		ma[dd[u]].upt(id[u], id[v], val);
		st.insert(ma[dd[u]].getmax());
	}
}


void solve() 
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}


	dfs(1, 0);

	ed[dd[1]] = 1;
	for (int i = 1; i <= log; i++) for (int j = 1; j <= n; j++) 
	lca[j][i] = lca[lca[j][i-1]][i-1];

	for (int i = 1; i <= cnt; i++) 
	{
		st.insert(0);
		ma[i].reset(id[ed[i]]);
	}

	while(m--)
	{
		int ti; cin >> ti; ti = 1 - ti; if (ti == 0) ti = -1;
		
		int u, v;
		cin >> u >> v;

		if (high[u] < high[v]) swap(u, v);
			
		int uv = findlca(u, v);

		if (uv != v)
		{
			update(u, uv, ti); update(v, uv, ti); update(uv, uv, -ti);
		}
		else update(u, v, ti);

		cout << *st.rbegin() << "\n";
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
