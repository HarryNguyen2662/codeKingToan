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

int par[200005];
pair<int,int> ed[300005], query[500005];
set<int> s[200005];
bool block[300005], dd[200005];

int findpar(int u)
{
	return par[u] < 0 ? u : findpar(par[u]);
}

void merge(int u, int v)
{
	u = findpar(u); v = findpar(v);
	if (u == v) return;
	if (par[u] > par[v]) swap(u, v);
	par[u] += par[v];
	par[v] = u;
	s[u].insert(s[v].begin(), s[v].end());
}

void solve() 
{
	vector<pair<pair<int,int>, pair<int,int>>> dk;
	int n, m, q;
	cin >> n >> m >> q;

	for (int i = 1; i <= n; i++) 
	{
		int x;
		cin >> x;
		par[i] = -1;
		s[i].insert(x);
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> ed[i].fi >> ed[i].se;
	}

	for (int i = 1; i <= q; i++)
	{
		cin >> query[i].fi >> query[i].se;
		if (query[i].fi == 2)
		{
			block[query[i].se] = true;
		}
	}
	
	for (int i = 1; i <= m; i++) if (!block[i])
	{
		merge(ed[i].fi, ed[i].se);
	}

	for (int i = q; i; i--) if (query[i].fi == 2)
	{
		int u = ed[query[i].se].fi, v = ed[query[i].se].se;
		u = findpar(u); v = findpar(v);
		if (u == v)
		{
			dk.pb({{-1, -1}, {-1, -1}});
		}
		else
		{
			if (par[u] > par[v]) swap(u, v);
			dk.pb({{u, par[u]}, {v, par[v]}});
			par[u] += par[v];
			par[v] = u;
			s[u].insert(s[v].begin(), s[v].end());
		}
	}

	for (int i = 1; i <= q; i++)
	if (query[i].fi == 1)
	{
		int u = findpar(query[i].se);

		while((int)s[u].size() && dd[*s[u].rbegin()]) 
			s[u].erase(*s[u].rbegin());

		if ((int)s[u].size()) 
		{
			cout << *s[u].rbegin() << "\n";
			dd[*s[u].rbegin()] = true;
		} else cout << "0\n";
	}
	else
	{
		int u = dk.back().fi.fi, uu = dk.back().fi.se;
		int v = dk.back().se.fi, vv = dk.back().se.se;
		dk.pop_back();
		if (u != -1)
		{
			par[v] = vv; par[u] = uu;
			for (auto ve : s[v]) s[u].erase(ve);
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
