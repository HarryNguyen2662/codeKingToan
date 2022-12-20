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

vector<pair<int,int>> a[100005], ldk;
long long res = 0;
int sz[100005], mx[100005], fen[100005], n, L, W;
bool visit[100005];

void calsize(int u)
{
	visit[u] = true;
	sz[u] = 1;
	mx[u] = 0;
	for (auto v : a[u])
	if (visit[v.fi] == false)
	{
		calsize(v.fi);
		if (sz[v.fi] > sz[mx[u]]) mx[u] = v.fi;
		sz[u] += sz[v.fi];
	}
	visit[u] = false;
}

int findpar(int u)
{
	int num = sz[u]/2;
	while(sz[mx[u]] > num) u = mx[u];
	return u;
}

void dfs(int u, int high = 0, int weight = 0)
{
	if (weight <= W && high <= L) ldk.pb({weight, high});
	else return;

	visit[u] = true;

	for (auto v : a[u]) if (visit[v.fi] == false)
	dfs(v.fi, high + 1, weight + v.se);
	
	visit[u] = false;
}

void update(int id, int val)
{
	if (!id)
	{
		fen[id] += val;
		return;
	}
 
	for (; id <= n; id += (id&(-id))) fen[id] += val;
}

int get(int id)
{
	int ress = fen[0];
	//cout << ress << endl;

	for (; id; id -= (id&(-id))) ress += fen[id];

	return ress;
}


void process(int factor)
{
	sort(ALL(ldk));

	int l = -1, lim = (int)ldk.size();
	for (int i = lim - 1; i >= 0; i--)
	{
		while(l + 1 < lim && ldk[l + 1].fi + ldk[i].fi <= W)
		{
			l++; 
			update(ldk[l].se, 1);
		}
		//update(1, 1);
		res += factor*get(L - ldk[i].se);
	}

	for (; l >= 0; l--) update(ldk[l].se, -1);

	ldk.clear();
}

void centroid(int u)
{
	calsize(u); u = findpar(u);
	
	dfs(u); process(1);
	res--;
	
	visit[u] = true; 
	
	for (auto v : a[u]) if (visit[v.fi] == false)
	{
		dfs(v.fi, 1, v.se); process(-1);
	}
	
	for (auto v : a[u]) if (visit[v.fi] == false)
	centroid(v.fi);
}

void solve() 
{

	cin >> n >> L >> W;
	//cout << n << endl;
	for (int i = 1; i < n; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[u].pb({v, w}); a[v].pb({u, w});
	}

	centroid(1); cout << res/2;
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
