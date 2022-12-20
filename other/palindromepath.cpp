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


int dd[25][25];
vector<pair<int, char>> a[25];

void solve() 
{
	queue<pair<int,int>> inq;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
	if (i != j) dd[i][j] = -1; else inq.push({i, i});
	
	for (int i = 1; i <= m; i++)
	{
		int u, v; char x;
		cin >> u >> v >> x;
		a[u].pb({v, x}); a[v].pb({u, x});
		dd[u][v] = dd[v][u] = 1;
		inq.push({u, v});
	}

	while(!inq.empty())
	{
		pair<int,int> u = inq.front(); inq.pop();

		for (auto v : a[u.fi])
		for (auto vv : a[u.se])
		if (v.se == vv.se && dd[v.fi][vv.fi] == -1)
		{
			dd[v.fi][vv.fi] = dd[vv.fi][v.fi] = dd[u.fi][u.se] + 2;
			inq.push({v.fi, vv.fi});
		}

	}

	cout << dd[1][2];
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
