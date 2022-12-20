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

struct DATA
{
	ll len; int ver, free;

	bool operator < (const DATA &other) const
	{
		return len > other.len;
	}
};

vector<pair<int,ll>> a[1000005];
ll dist[1000005][11];

void solve() 
{
	int n, m, k, s, t;
	cin >> n >> m >> k >> s >> t;

	for (int i = 1; i <= m; i++)
	{
		int u, v; ll w;
		cin >> u >> v >> w;
		a[u].pb({v, w}); a[v].pb({u, w});
	}

	for (int i = 1; i <= n; i++) for (int j = 0; j <= k; j++) dist[i][j] = oo18;

	dist[s][0] = 0; 
	priority_queue<DATA> qe; qe.push({0, s, 0});

	while(!qe.empty())
	{
		int u = qe.top().ver, sl = qe.top().free; ll len = qe.top().len; qe.pop();
		if (dist[u][sl] != len) continue;

		for (auto v : a[u])
		{
			if (dist[v.fi][sl] > len + v.se)
			{
				dist[v.fi][sl] = len + v.se;
				qe.push({dist[v.fi][sl], v.fi, sl});
			}
			if (sl + 1 <= k && dist[v.fi][sl + 1] > len)
			{
				dist[v.fi][sl + 1] = len;
				qe.push({dist[v.fi][sl + 1], v.fi, sl + 1});
			}
		}
	}

	ll ans = oo18;
	for (int i = 0; i <= k; i++) ans = min(ans, dist[t][i]);

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
    //
    // 
    freopen("TINHPHI.inp","r",stdin); freopen("TINHPHI.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
