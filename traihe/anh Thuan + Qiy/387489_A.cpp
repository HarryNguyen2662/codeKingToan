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

long long res = 0;
int dem[100005], dd[100005], sz[100005], mx[100005], tt = 0;
bool visit[100005];
vector<int> a[100005];
int n, k;

void calsize(int u)
{
	visit[u] = true;
	sz[u] = 1;
	mx[u] = 0;

	for(auto v : a[u]) if (visit[v] == false)
	{
		calsize(v);
		if (sz[v] > sz[mx[u]]) mx[u] = v;
		sz[u] += sz[v];
	}
	visit[u] = false;
}

int findpar(int u)
{
	int num = sz[u]/2;
	while(sz[mx[u]] > num) u = mx[u];
	return u;
}

void update(int id, int val)
{
	if (dd[id] != tt)
	{
		dem[id] = val; dd[id] = tt;
		return;
	}
	dem[id] += val;
}

void dfs1(int u, int high)
{

	visit[u] = true;
	if (high <= k)
	{
		update(k - high, 0);
		res += dem[k - high];
	}

	for (auto v : a[u]) if (visit[v] == false)
	{
		dfs1(v, high + 1);
	}

	visit[u] = false;
}

void dfs2(int u, int high)
{
	visit[u] = true;
	if (high <= k)
	{
		//cout << u << " " << high << endl;
		update(high, 1);
	}

	for (auto v : a[u]) if (visit[v] == false)
	{
		dfs2(v, high + 1);
	}
	
	visit[u] = false;
}

void centroid(int u)
{
	calsize(u); u = findpar(u);
	//cout << u << endl;
	visit[u] = true; tt++;

	update(1, 1);

	for (auto v : a[u]) if (visit[v] == false)
	{
		dfs1(v, 0);
		//cout << "ua " << dem[2] << endl;
		dfs2(v, 2);
	}
	for (auto v : a[u]) if (visit[v] == false)
	centroid(v);
}

void solve() 
{
	cin >> n >> k;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
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
