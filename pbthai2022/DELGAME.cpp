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

int cnt = 0, cmt = 0;
vector<int> a[100005];
bool visit[100005];

void dfs(int u)
{
	visit[u] = true;
	cmt++;
	for (auto v : a[u])
	{
		cnt++;
		if (visit[v] == false) dfs(v);
	}
}

void solve() 
{
	int n, m, k;
	cin >> n >> m >> k; k++;

	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}

	int res = 0;

	for (int i = 1; i <= n; i++) if (visit[i] == false)
	{
		cnt = 0; cmt = 0;
		dfs(i);
		res = res^((cnt/2 - cmt + 1)%k);
	}

	cout << min(res, 1) << "\n";

	for (int i = 1; i <= n; i++)
	{
		a[i].clear();
		visit[i] = false;
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
    int testcase = 4;
    //cin >> testcase;
    while(testcase--)
        solve();
}
