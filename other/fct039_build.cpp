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

int par[100005], cs[100005];
pair<int,int> a[100005];

int findpar(int u)
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
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].fi >> a[i].se;
		cs[i] = i;
		par[i] = -1;
	}

	vector<pair<int, pair<int, int>>> ldk;

	sort(cs + 1, cs + 1 + n, [](const int &x, const int &y)
	{
		return a[x].fi < a[y].fi;
	});

	for (int i = 2; i <= n; i++)
	{
		ldk.pb({a[cs[i]].fi - a[cs[i-1]].fi, {cs[i], cs[i-1]}});
	}


	sort(cs + 1, cs + 1 + n, [](const int &x, const int &y)
	{
		return a[x].se < a[y].se;
	});

	for (int i = 2; i <= n; i++)
	{
		ldk.pb({a[cs[i]].se - a[cs[i-1]].se, {cs[i], cs[i-1]}});
	}

	sort(ALL(ldk));

	ll ans = 0;

	for (auto v : ldk) if (merge(v.se.fi, v.se.se)) ans += v.fi;

	cout << ans;
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
