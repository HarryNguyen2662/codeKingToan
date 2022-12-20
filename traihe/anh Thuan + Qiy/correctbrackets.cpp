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

vector<int> a[300005];
int sz[300005], s[300005], mx[300005], dem[300005], dd[300005], dem1[300005], dd1[300005], tt = 0;
bool visit[300005];
long long res = 0;

void update(int id, int val, int tt)
{
	if (dd[id] != tt)
	{
		dem[id] = val; dd[id] = tt;
		return;
	}
	dem[id] += val;
}

void update1(int id, int val, int tt)
{
	if (dd1[id] != tt)
	{
		dem1[id] = val; dd1[id] = tt;
		return;
	}
	dem1[id] += val;
}

void calsize(int u)
{
	sz[u] = 1;
	mx[u] = 0;
	visit[u] = true;
	for (auto v : a[u])
	if (visit[v] == false)
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

void dfs1(int u, int t, int mn, int mx)
{
	visit[u] = true;
	t = t + s[u];
	mn = min(mn, t);
	mx = max(mx, t);
	if (s[u] == -1 && t <= 0 && -t + mn >= 0)
	{
		update(-t, 0, tt);
		res += dem[-t];
	}
	else if (s[u] == 1 && t >= 0 && t - mx >= 0)
	{
		update1(t, 0, tt);
		res += dem1[t];
	}
	for (auto v : a[u])
	if (visit[v] == false)
	{
		dfs1(v, t, mn, mx);
	}
	visit[u] = false;
}

void dfs2(int u, int t, int mn, int mx)
{
	visit[u] = true;
	t = t + s[u];
	mn = min(mn, t);
	mx = max(mx, t);
	if (s[u] == 1 && t >= 0 && t - mx >= 0)
	{
		update(t, 1, tt);
	}
	else if (s[u] == -1 && t <= 0 && -t + mn >= 0)
	{
		update1(-t, 1, tt);
	}
	for (auto v : a[u])
	if (visit[v] == false)
	{
		dfs2(v, t, mn, mx);
	}
	visit[u] = false;
}

int centroid(int u)
{
	tt++;
	calsize(u); u = findpar(u);
	visit[u] = true;
	//cout << u << endl;
	if (s[u] == 1) update(1, 1, tt);
	else update1(1, 1, tt);
	//cout << dem[1] << endl;
	for (auto v : a[u]) if (visit[v] == false)
	{
		dfs1(v, 0, 0, 0);
		dfs2(v, s[u], min(0, s[u]), max(s[u], 0));
	}
	//cout << u <<
	for (auto v : a[u]) if (visit[v] == false)
	centroid(v);
}

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		char x; cin >> x;
		if (x == '(') s[i] = 1; else s[i] = -1;
	}
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		//cout << u << " " << v << endl;
		a[u].pb(v);
		a[v].pb(u);
	}
	// calsize(1);
	// findpar(1);
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
    //freopen("tests.inp","r",stdin); freopen("tests.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
