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

ll dp[100005][3], b[100005];
vector<int> a[100005];

void dfs(int u, int par)
{
	dp[u][2] = b[u];
	ll su = 0;
	vector<ll> luu;
	for (auto v : a[u]) if (v != par)
	{
		dfs(v, u);
		dp[u][2] += max({dp[v][1], dp[v][0] + b[v], dp[v][2]});
		dp[u][0] += max(dp[v][0], dp[v][1]);
		su += max({dp[v][0], dp[v][1], dp[v][2]});
		luu.pb(b[u] + dp[v][2] - max({dp[v][0], dp[v][1], dp[v][2]}));
	}


	if ((int)luu.size())
	dp[u][1] = luu.back() + su;
	for (auto v : luu) dp[u][1] = max(dp[u][1], v + su);

	// cout << u << " " << dp[u][0] << " " << dp[u][1] << " " << dp[u][2] << endl;
}

void solve() 
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		dp[i][0] = dp[i][2] = 0;
		dp[i][1] = -oo18;
	}

	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;

		a[u].pb(v); a[v].pb(u);
	}

	dfs(1, 0);
	cout << max({dp[1][0], dp[1][1], dp[1][2]}) << "\n";

	for (int i = 1; i <= n; i++) 
	{
		a[i].clear();
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
    cin >> testcase;
    while(testcase--)
        solve();
}
