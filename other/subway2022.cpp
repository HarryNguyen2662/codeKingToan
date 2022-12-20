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

long long dp[100005][4], p[100005], cost[30][2];
vector<int> a[100005];
vector<int> dk;
bool ke[30][30];
int vit[100005], ty[100005], con[100005], spec[100005], cnt = 0, st[100005], ed[100005];
int sl = 0;
void dfs(int u, int par)
{
	if (spec[u] != -1)
	{
		if (st[cnt] == 0) st[cnt] = par;
		dk.pb(u); return;
	}
	
	sl++;
	vit[u] = cnt;

	for (auto v : a[u]) if (v != par)
	{
		dfs(v, u);
	}
}

void cal(int u, int par)
{
	ed[vit[u]] = u;
	if (par == 0)
	{
		dp[u][3] = p[u];
	}
	else
	{	// 0 : ko chon 1 ko  chon i
		// 1 : ko con 1 chon i
		// 2 : chon 1 k chon i
		//3 chon 1 chon i;
		dp[u][0] = max(dp[par][0], dp[par][1]);
		dp[u][1] = dp[par][0] + p[u];
		dp[u][2] = max(dp[par][2], dp[par][3]);
		dp[u][3] = dp[par][2] + p[u];
	}

	for (auto v : a[u]) if (vit[v] == vit[u] && v != par)
	{
		cal(v, u);
	}
}

vector<pair<int,int>> luu[20][20];

void solve() 
{
	int n, m;
	vector<int> ldk;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
		spec[i] = -1;
	}

	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u); 
		if ((int)a[u].size() >= 3) 
		{
			ldk.pb(u); 
		}

		if ((int)a[v].size() >= 3) 
		{
			ldk.pb(v);
		}
	}


	sort(ALL(ldk)); ldk.resize(unique(ALL(ldk)) - ldk.begin());

	if ((int)ldk.size() == 0)
	{
		spec[1] = 0; ldk.pb(1);
	}
	else for (int i = 0; i < (int)ldk.size(); i++) spec[ldk[i]] = i;

	for (int i = 1; i <= n; i++) 
	if (vit[i] == 0 && spec[i] == -1)
	{
		dk.clear();
		sl = 0;
		cnt++;
		dfs(i, 0);
		if ((int)dk.size() == 1) ty[cnt] = 1;
		else if (dk[0] == dk[1]) ty[cnt] = 2;
		else
		{
			luu[spec[dk[0]]][spec[dk[1]]].pb({cnt, sl}); luu[spec[dk[1]]][spec[dk[0]]].pb({cnt, sl});
			ty[cnt] = 3;
		} 
	}

	for (int i = 1; i <= cnt; i++) cal(st[i], 0); 

	for (auto v : ldk) 
	{
		for (auto vv : a[v]) if (vv == st[vit[vv]]) 
		{
			if (ty[vit[vv]] == 2)
			{
				cost[spec[v]][1] += dp[ed[vit[vv]]][0];
				cost[spec[v]][0] += max({dp[ed[vit[vv]]][0], dp[ed[vit[vv]]][1], dp[ed[vit[vv]]][2], dp[ed[vit[vv]]][3]});
			}
			else if (ty[vit[vv]] == 1)
			{
				cost[spec[v]][1] += max(dp[ed[vit[vv]]][0], dp[ed[vit[vv]]][1]);
				cost[spec[v]][0] += max({dp[ed[vit[vv]]][0], dp[ed[vit[vv]]][1], dp[ed[vit[vv]]][2], dp[ed[vit[vv]]][3]});
			}
		} 
		else if (spec[vv] != -1) ke[spec[v]][spec[vv]] = true;
		
		cost[spec[v]][1] += p[v];
	}


		
	long long res = 0;


	for (int msk = 0; msk < mask((int)ldk.size()); msk++)
	{
		bool duocko = true;
		long long cur = 0;
		for (int i = 0; i < (int)ldk.size(); i++)
		{
			cur += cost[i][ck(msk, i)];
			for (int j = 0; j < (int)ldk.size(); j++)
			{
				if (ke[i][j] && ck(msk, i) && ck(msk, j))
				{
					duocko = false;
				}
				for (auto q : luu[i][j])
				{
					int qq = ed[q.fi];
					if (ck(msk, i) && ck(msk, j))
					{
						cur += dp[qq][0];
					}
					else if (ck(msk, i) && !ck(msk, j) && q.se > 1)
					{
						cur += max(dp[qq][1], dp[qq][0]);
					}
					else if (!ck(msk, i) && ck(msk, j) && q.se > 1)
					{

						cur += max(dp[qq][2], dp[qq][0]);
					}
					else if (!ck(msk, i) && !ck(msk, j))
					{
						cur += max({dp[qq][0], dp[qq][1], dp[qq][2], dp[qq][3]});
					}
				}
			}
		}

		if (duocko) res = max(res, cur);
	}

	
	cout << res;

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
