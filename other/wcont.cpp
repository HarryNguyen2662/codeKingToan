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

vector<int> a[500005];
int heigh[500005], dem[500005];
int mx = 0;

void dfs(int u, int par)
{
	heigh[u] = heigh[par] + 1;
	mx = max(mx, heigh[u]);

	for (auto v : a[u]) if (v != par) dfs(v, u);
}

void solve() 
{
	int n, q;
	cin >> n >> q;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}

	mx = 0;
	dfs(1, 0);

	for (int i = 1; i <= n; i++) 
	{
		heigh[i] = mx - heigh[i] + 1;
		dem[heigh[i]]++;
	}

	int res = 0;

	for (int i = 1; i <= q; i++)
	{
		int w;
		cin >> w;
	}

	for (int i = mx; i; i--) if (q >= dem[i])
	{
		q -= dem[i];
		res += dem[i];
	} else break;

	for (int i = 1; i <= n; i++)
	{
		a[i].clear(); dem[i] = 0;
	}

	cout << res << "\n";

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
