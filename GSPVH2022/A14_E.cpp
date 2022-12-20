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

ll cnt[1505], dem[1505], dist[1505], ans[5005], cst[5005];
pair<int, int> edge[5005];
vector<pair<int, ll>> a[1505], ok[1505];
int n, m;

void dij(int st)
{
	vector<int> ldk;
	for (int i = 1; i <= n; i++) 
	{
		cnt[i] = dem[i] = 0;
		dist[i] = oo15;
	}

	dist[st] = 0; cnt[st] = 1;
	
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> qe;

	qe.push({0, st});

	while(!qe.empty())
	{
		ll len = qe.top().fi; int u = qe.top().se; qe.pop();

		if (len != dist[u]) continue;
		ldk.pb(u);

		for (auto v : a[u])
		if (dist[v.fi] > len + v.se)
		{
			dist[v.fi] = len + v.se;
			cnt[v.fi] = cnt[u];
			qe.push({dist[v.fi], v.fi});
		}
		else if (dist[v.fi] == len + v.se)
		{
			cnt[v.fi] += cnt[u]; if (cnt[v.fi] >= MOD1) cnt[v.fi] -= MOD1;
		}
	}
		// if (st == 6 || st == 8 || st == 9 || st == 10) cout << "adf aof \n";

	reverse(ALL(ldk)); 
	for (auto u : ldk) 
	{
		dem[u]++;
		for (auto v : ok[u]) 
		if (dist[u] == dist[v.fi] + v.se)
		{
			dem[v.fi] += dem[u]; if (dem[v.fi] >= MOD1) dem[v.fi] -= MOD1;
		}
	}

	// cout << "dau " << st << endl;

	for (int i = 1; i <= m; i++)
	if (dist[edge[i].fi] + cst[i] == dist[edge[i].se])
	{
		// if (i == 1)
		// cout << st << " " << cnt[edge[i].fi] << " " << dem[edge[i].se] << endl;
		ans[i] += cnt[edge[i].fi]*dem[edge[i].se]%MOD1;
		if (ans[i] >= MOD1) ans[i] -= MOD1;
	}

}

void solve() 
{
	cin >> n >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
	
		a[u].pb({v, w});
		ok[v].pb({u, w});

		edge[i] = {u, v};
		cst[i] = w;
	}

	for (int i = 1; i <= n; i++) dij(i);

	for (int i = 1; i <= m; i++) cout << ans[i] << "\n";
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("CAULUONG.inp","r",stdin); freopen("CAULUONG.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
