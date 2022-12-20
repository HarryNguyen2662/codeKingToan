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

int par[200005], dem[200005];
vector<int> ldk[200005];

int findpar(int u)
{
	return par[u] < 0 ? u : par[u] = findpar(par[u]);
}

bool merge(int u, int v)
{
	u = findpar(u); v= findpar(v);
	if (u == v) return false;
	if (par[u] > par[v]) swap(u, v);
	par[u] += par[v];
	par[v] = u;
	return true;
}
void solve() 
{
	int n;
	bool kt = false;
	cin >> n;
	vector<pair<int,int>> a(n);
	for (int i = 1; i <= n; i++)
	{
		ldk[i].clear(); dem[i] = 0;
		par[i] = -1;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].fi >> a[i].se;
		if (a[i].fi > a[i].se) swap(a[i].fi, a[i].se);
		dem[a[i].fi]++; dem[a[i].se]++;
		if (dem[a[i].fi] > 2 || dem[a[i].se] > 2 || a[i].fi == a[i].se)
		{
			kt = true;
		}
	}
	if (kt)
	{
		cout << "NO\n";
		return;
	}
	sort(ALL(a)); a.resize(unique(ALL(a)) - a.begin());
	int cnt = 0;
	for (auto v : a)
	{
		cnt++;
		cout << v.fi << " " << v.se << endl;
		ldk[v.fi].pb(cnt); ldk[v.se].pb(cnt);
	}
	for (int i = 1; i <= cnt; i++)
	if ((int)ldk[i].size() == 2)
	{
		if (!merge(ldk[i][0], ldk[i][1]))
		{
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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
    cin >> testcase;
    while(testcase--)
        solve();
}
