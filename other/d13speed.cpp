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

int par[1005];

int findpar(int u)
{
	return par[u] < 0 ? u : par[u] = findpar(par[u]);
}

void merge(int u, int v)
{
	u = findpar(u); v = findpar(v);
	if (u == v) return;

	if (par[u] > par[v]) swap(u, v);

	par[u] += par[v];
	par[v] = u;
}

void solve() 
{
	int n, m;
	vector<pair<int,pair<int,int>>> ldk;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		ldk.pb({w, {u,v}});
	}

	sort(ALL(ldk));

	int nn = (int)ldk.size();

	int st = 0, ed = oo + 5;

	for (int i = 0; i < nn; i++)
	{
		int u = ldk[i].fi, v = 0;

		bool kt = false;

		for (int j = 1; j <= n; j++) par[j] = -1;

		for (int j  = i; j < nn; j++) 
		{
			merge(ldk[j].se.fi, ldk[j].se.se);
			if (-par[findpar(ldk[j].se.fi)] == n)
			{
				v = ldk[j].fi;
				kt = true;
				break;
			}
		}

		if (kt && v - u < ed - st) 
		{
			st = u; ed = v;
		}
	}
	cout << st << " " << ed;
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
