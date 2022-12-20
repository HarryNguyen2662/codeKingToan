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

int n, k, child[300005], dem[300005];
long long res = 0;
vector<int> ldk[300005], adu[300005];
int cnt = 0;
vector<pair<int, long long>> a[300005];
bool ok[300005];

void dfs(int u, int par)
{
	child[u] += dem[u];
	ok[u] = true;
	for (auto v : a[u]) if (v.fi != par)
	{
		dfs(v.fi, u);
		if (child[v.fi] > k/2) ok[u] = false; 
		child[u] += child[v.fi];

	}
}

void dfs1(int u, int par, long long hei = 0)
{
	
	for (auto v : adu[u]) ldk[cnt].pb(v);
	res += 1ll*dem[u]*hei;

	for (auto v : a[u])
	if (v.fi != par)
	{
		dfs1(v.fi, u, hei + v.se);
	}
}

void solve() 
{
	cin >> n >> n >> k >> k;

	for (int i = 1 ; i < n; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[u].pb({v, w}); a[v].pb({u, w});
	}

	for (int i = 1; i <= k; i++)
	{
		int u;
		cin >> u;
		adu[u].pb(i);
		dem[u]++;
	}


	dfs(1, 0);
	
	int root = 1;
	priority_queue<pair<int,int>> pq;
	vector<pair<int,int>> match;

	
	for (int i = 1; i <= n; i++) 
	{

		if (ok[i] && child[i] >= k/2)
		{
			root = i;
			
			if (dem[root])
			{
				cnt++;
				for (auto v : adu[root]) ldk[cnt].pb(v);
				pq.push({(int)ldk[cnt].size(), cnt});
			}

			for (auto v : a[root])
			{
				cnt++;
				dfs1(v.fi, root, v.se);
				if ((int)ldk[cnt].size()) pq.push({(int)ldk[cnt].size(), cnt});
			}
			break;
		}
	}
	


	while(!pq.empty())
	{
		int id = pq.top().se; pq.pop();
		int id1 = pq.top().se; pq.pop();
		
		int u = ldk[id].back(); ldk[id].pop_back();
		if ((int)ldk[id].size()) pq.push({(int)ldk[id].size(), id});

		int v = ldk[id1].back(); ldk[id1].pop_back();
		if ((int)ldk[id1].size()) pq.push({(int)ldk[id1].size(), id1});

		match.pb({u, v});

	}

	cout << res << "\n";

	for (auto v : match) cout << v.fi << " " << v.se << "\n"; 

}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("partner.inp","r",stdin); freopen("partner.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
