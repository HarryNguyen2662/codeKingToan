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

const int MAXN = 200000;

bool visit[MAXN + 5];
int sz[MAXN + 5], mx[MAXN + 5];
ll w[MAXN + 5];
vector<int> a[MAXN + 5];
vector<ll> diff;
vector<pair<ll, ll>> ldk;

ll ANS = 0;

class fenwicktree {
private:
    int len;
    vector<int> fen;
 
public:
    void reset(int sz) {
    	fen.assign(sz + 3, 0);
        len = sz;
    }
 
    void update(int id, int val)
    {
    	for (; id; id -= (id&(-id))) fen[id] += val;
    }

	int get(int id)
	{
		int res = 0;
		for (; id <= len; id += (id&(-id))) res += fen[id];
		return res;
	}
};

fenwicktree dk;

void calc(int u)
{
	visit[u] = true;

	sz[u] = 1; mx[u] = 0;

	for (auto v : a[u]) if (visit[v] == false)
	{
		calc(v);

		if (sz[v] > sz[mx[u]]) mx[u] = v;
		
		sz[u] += sz[v];
	}

	visit[u] = false;
}

int findroot(int u)
{
	int num = sz[u]/2;
	
	while(sz[mx[u]] > num) u = mx[u];

	return u;
}

void process(int factor , int root)
{
	sort(ALL(diff)); sort(ALL(ldk)); diff.resize(unique(ALL(diff)) - diff.begin());

	dk.reset((int)diff.size());

	int i = 0, n = (int)ldk.size();

	for (auto v : ldk)
	{
		ll cur = 2*v.fi - v.se + 1;
		int id = lower_bound(ALL(diff), cur) - diff.begin() + 1;

		ANS += factor*dk.get(id);


		id = lower_bound(ALL(diff), v.se - w[root]) - diff.begin() + 1;

		dk.update(id, 1);
	}


	diff.clear(); ldk.clear();
}

void dfs(int u, ll mx, ll dist, int root)
{
	diff.pb(dist - w[root]); ldk.pb({mx, dist});

	visit[u] = true;

	for (auto v : a[u]) if (visit[v] == false)
	{
		dfs(v, max(mx, w[v]), dist + w[v], root);
	}

	visit[u] = false;
}

void centroid(int u)
{
	calc(u); u = findroot(u);


 	dfs(u, w[u], w[u], u); process(1, u);

	visit[u] = true;

	for (auto v : a[u]) if (visit[v] == false)
	{
		dfs(v, max(w[v], w[u]), w[v] + w[u], u); process(-1, u);
	}

	for (auto v : a[u]) if (visit[v] == false) centroid(v);
}

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}

	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;

		a[u].pb(v); a[v].pb(u);
	}

	centroid(1);

	cout << ANS;

}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    // //
    freopen("TREE.inp","r",stdin); freopen("TREE.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
