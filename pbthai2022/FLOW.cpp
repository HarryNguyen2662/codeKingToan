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

vector<pair<int,int>> a[1005];
int cc[1005], c[1005][1005], dd[1005][1005], pa[1005];

int findpar(int u)
{
	return pa[u] < 0 ? u : pa[u] = findpar(pa[u]);
}

bool merge(int u, int v)
{
	u = findpar(u); v = findpar(v);
	if (u == v)  return false;
	if (pa[u] > pa[v]) swap(u, v);
	pa[u] += pa[v];
	pa[v] = u;
	return true;
}

void dfs(int u, int par)
{
	for (auto v : a[u]) if (v.fi != par)
	{
		cc[v.fi] = v.se;
		if (cc[u]) cc[v.fi] = min(cc[v.fi], cc[u]);
		dfs(v.fi, u);
	}
}

void solve() 
{
	vector<pair<int,pair<int,int>>> ldk;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		pa[i] = -1;
		for (int j = 1; j <= n; j++)
		{
			int x;
			cin >> x;
			if (x)
			{
				ldk.pb({x, {i, j}});
			}
			c[i][j] = x;
		}
	}

	sort(ALL(ldk)); reverse(ALL(ldk));
	for (auto v : ldk)
	if (merge(v.se.fi, v.se.se))
	{
		dd[v.se.fi][v.se.se] = dd[v.se.se][v.se.fi] = v.fi;
		a[v.se.fi].pb({v.se.se, v.fi});
		a[v.se.se].pb({v.se.fi, v.fi});
	}

	for (int i = 1; i <= n; i++)
	{
		dfs(i, 0);
	 	for (int j = 1; j <= n; j++)
	 	{
	 		if (c[i][j] != cc[j])
	 		{
	 			cout << "-1";
	 			return;
	 		}
	 		cc[j] = 0;
	 	}
	}

	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= n; j++) cout << dd[i][j] << " ";
		cout << "\n";
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
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
