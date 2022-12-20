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

int par[100005];
ll c[100005];
bool ok[100];

int findpar(int u )
{
	return par[u] < 0 ? u : par[u] = findpar(par[u]);
}

bool merge(int u, int v)
{
	u = findpar(u); v = findpar(v);
	if (u == v) return false;

	if (par[u] > par[v]) swap(u, v);
	par[u] += par[v];
	par[v] = u;

	return true;
}

void solve() 
{
	int n, m, k;
	cin >> n >> m >> k;	

	for (int i = 1; i <= n; i++)
	{
		par[i] = -1;
	}

	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
	}

	vector<pair<pair<ll, bool>,pair<int,int>>> ldk(m);

	for (int i = 1; i <= m; i++)
	{
		int t;
		ldk[i-1].fi.fi = 0; ldk[i-1].fi.se = 0;
		cin >> ldk[i-1].se.fi >> ldk[i-1].se.se >> t;
		for (int j = 1; j <= t; j++)
		{
			ll x;
			cin >> x;
			ldk[i-1].fi.fi |= mask(x-1);
		}
	}

	sort(ALL(ldk));

	ll ans = 3*oo18;

	for (int j = 1; j <= n; j++) par[j] = -1;
	ll status = 0;

	for (auto v : ldk)
	{
		if (merge(v.se.fi, v.se.se)) 
		{
			status |= v.fi.fi;
		}
	}

	ll curr = 0;
	for (int j = 0; j < k; j++) if (ck(status, j)) curr += c[j + 1];

	if (-par[findpar(1)] == n)
	ans = min(ans, curr);


	
	for (int i = 0; i < k; i++)
	{
		for (int j = 1; j <= n; j++) par[j] = -1;
		status = 0;

		for (auto v : ldk)
		{
			if (!ck(v.fi.fi, i) && merge(v.se.fi, v.se.se)) 
			{
				status |= v.fi.fi;
			}
		}

		if (-par[findpar(1)] != n) continue;

		ll cur = 0;
		for (int j = 0; j < k; j++) if (ck(status, j)) cur += c[j + 1];

		ans = min(ans, cur);
		
	}

	if (ans == 3*oo18)
	{
		cout << -1; return;
	}

	cout << ans;

}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    // //
    freopen("MINCOST.inp","r",stdin); freopen("MINCOST.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
