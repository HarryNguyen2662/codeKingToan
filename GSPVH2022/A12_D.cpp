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

ll dist[505][505], mn[505][505], mx[505];
vector<int> ldk[505];

void solve() 
{
	int n, m, q;
	cin >> n >> m >> q;

	for (int i = 1; i <= n; i++)
	{
		mx[i] = oo15;
		for (int j = i + 1; j <= n; j++) dist[i][j] = dist[j][i] = mn[i][j] = mn[j][i] = oo15;
	}

	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		dist[u][v] = min(dist[u][v], 1ll*w);
		dist[v][u] = dist[u][v];
	}

	for (int k = 1; k <= n; k++)
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	dist[i][j] = min(dist[i][j], dist[k][i] + dist[k][j]);


	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= n; k++)
		for (int j = 1; j <= n; j++)
		if (j != k && dist[i][j] == dist[k][i] + dist[k][j]) 
		{
			mn[i][j] = min(mn[i][j], dist[k][j]);
		}
	}


	while(q--)
	{
		int sz;
		cin >> sz;

		for (int i = 1; i <= sz; i++)
		{
			int u;
			cin >> u;
			for (int j = 1; j <= n; j++)
			{
				if (mx[j] > dist[j][u])
				{
					mx[j] = dist[j][u];
					ldk[j].clear(); ldk[j].pb(u);
				}
				else if (mx[j] == dist[j][u]) ldk[j].pb(u);
			}
		}

		ll ans = 0;

		for (int i = 1; i <= n; i++)
		{
			mx[i] = oo15;
			ll ok = oo15;
			
			for (auto v : ldk[i]) ok = min(ok, mn[v][i]);


			if (ok < oo15) ans += ok;

			ldk[i].clear();
		}

		cout << ans << " ";
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
    //freopen("giaohang.inp","r",stdin); freopen("giaohang.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
