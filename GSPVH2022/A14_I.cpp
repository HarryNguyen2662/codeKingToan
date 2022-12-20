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

vector<pair<int,int>> a[505];
int n, m, pe[505][505], id[505][505], dem[500005];
ll dist[505][505], cnt[505][505];
bool ok[505];

void dij(int st)
{
	for (int i = 1; i <= n; i++)
	{
		dist[st][i] = oo15;
		pe[st][i] = -1;
		ok[i] = false;
	}

	dist[st][st] = 0; cnt[st][st] = 1;
	for (int i = 1; i <= n; i++)
	{
		int v = -1;
		for (int j = 1; j <= n; j++)
		if (!ok[j] && (v == -1 || dist[st][j] < dist[st][v])) v = j;

		if (dist[st][v] == oo15) break;

		ok[v] = true;

		for (auto e : a[v])
		if (dist[st][e.fi] > dist[st][v] + e.se)
		{
			cnt[st][e.fi] = cnt[st][v];
			dist[st][e.fi] = dist[st][v] + e.se;
			pe[st][e.fi] = v;
		}
		else if (dist[st][e.fi] == dist[st][v] + e.se) cnt[st][e.fi] += cnt[st][v];
	}
}

void solve() 
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[u].pb({v, w}); a[v].pb({u, w});
		id[u][v] = id[v][u] = i;
	}

	for (int i = 1; i <= n; i++) dij(i);


	for (int i = 1; i <= n; i++)
	for (int j = i + 1; j <= n; j++)
	{
		int cur = j;
		while(pe[i][cur] != -1)
		{
			int ncur = pe[i][cur];
			if (cnt[i][ncur]*cnt[j][cur] == cnt[i][j]) dem[id[cur][ncur]]++;
			cur = ncur;
		}
	}



	for (int i = 1; i <= m; i++) cout << dem[i] << "\n";
	
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("candy.inp","r",stdin); freopen("candy.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
