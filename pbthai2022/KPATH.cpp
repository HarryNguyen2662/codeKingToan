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

int n, k, sz[100005], mx[100005];
long long dd[100005];
bool visit[100005];
long long res = oo15;
int mxx = 0;
vector<pair<int,int>> a[100005];

void cal(int u)
{
	visit[u] = true;
	sz[u] = 1;
	mx[u] = 0;
	for (auto v : a[u])
	if (visit[v.fi] == false)
	{
		cal(v.fi);
		sz[u] += sz[v.fi];
		if (sz[v.fi] > sz[mx[u]]) mx[u] = v.fi;
	}
	visit[u] = false;

}

int findroot(int u)
{
	int num = sz[u]/2;
	while(sz[mx[u]] > num) u = mx[u];
	return u;
}

void dfs1(int u, long long w, int hi)
{
	if (hi > k) return;
	mxx = max(mxx, hi);
	visit[u] = true;
	res = min(res, w + dd[k - hi]);
	for (auto v :a[u]) if (visit[v.fi] == false)
	{
		dfs1(v.fi, w + v.se, hi + 1);
	}
	visit[u] = false;

}

void dfs2(int u, long long w, int hi)
{
	if (hi > k) return;
	visit[u] = true;
	dd[hi] = min(dd[hi], w);
	for (auto v :a[u]) if (visit[v.fi] == false)
	{
		dfs2(v.fi, w + v.se, hi + 1);
	}
	visit[u] = false;

}

void centroid (int u)
{
	cal(u); u = findroot(u);
	visit[u] = true;
	mxx = 0;
	for (auto v : a[u])
	if (visit[v.fi] == false)
	{
		dfs1(v.fi, v.se, 1);
		dfs2(v.fi, v.se, 1);
	}
	for (int i = 1; i <= mxx; i++) dd[i] = oo15;
	for (auto v : a[u]) if (visit[v.fi] == false) centroid(v.fi);
}

void solve() 
{
	cin >> n >> k;
	for (int i = 1; i <= k; i++) dd[i] = oo15;
	for (int i =  1; i < n; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[u].pb({v, w});
		a[v].pb({u, w});
	}

	centroid(1);
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
