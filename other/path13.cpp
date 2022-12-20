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

struct DATA
{
	int ver, status;
	long long ditt;
	bool operator < (const DATA &other) const
	{
		return ditt > other.ditt;
	}
};

bool vit[55][8200][15];
vector<pair<int,long long>> a[5005];
long long dist[5005], dit[55][8200][15];

int n, m;
long long path13()
{
	for (int i = 1; i <= n; i++)
	{
		dist[i] = oo18;
	}
	dist[1] = 0;
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push({0, 1});
	while(!pq.empty())
	{
		int u = pq.top().se; long long len = pq.top().fi; pq.pop();
		if (dist[u] != len) continue;
		for (auto v : a[u]) if (dist[v.fi] > len + v.se)
		{
			dist[v.fi] = len + v.se;
			pq.push({dist[v.fi], v.fi});
		}
	} 
	return (dist[n] == oo18 ? -1 : dist[n]);
}

void dfs(int u, int tt, int pre)
{
	vit[u][tt][pre] = true;
	for (auto v : a[u]) if (!ck(tt, (pre + v.se)%13))
	{
		int npre = (pre + v.se)%13;
		int ntt = tt^mask(npre);
		if (vit[v.fi][ntt][npre] == false)
		dfs(v.fi, ntt, npre);
		dit[u][tt][pre] = min(dit[u][tt][pre], dit[v.fi][ntt][npre] + v.se);
	}
}

long long notpath13()
{
	for (int i = 1; i <= n; i++) for (int j = 0;  j < mask(13); j++) for (int dm = 0; dm < 13; dm++)
	{
		vit[i][j][dm] = false;
		dit[i][j][dm] = oo18;
	}
	
	for (int i = 2; i < mask(13); i++) for (int dm = 0; dm < 13; dm++) dit[n][i][dm] = 0;
	dfs(1, 1, 0);
	return (dit[1][1][0] == oo18 ? -1 : dit[1][1][0]);
}

void solve() 
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) a[i].clear();
	for (int i = 1; i <= m; i++)
	{
		int u, v; long long w;
		cin >> u >> v >> w;
		a[u].pb({v, w});
	}

	string kt;
	cin >> kt;
	if (kt == "True") cout << notpath13() << "\n"; else cout << path13() << "\n";
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
