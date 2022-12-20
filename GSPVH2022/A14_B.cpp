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

struct DATA
{
	int ver1, ver2, cost, id;

	bool operator < (const DATA &other) const
	{
		if (cost == other.cost)
		{
			return id < other.id;
		}
		return cost < other.cost;
	}
};

int par[300005];
bool moji[300005];

int findpar(int u)
{
	return par[u] < 0 ? u : par[u] = findpar(par[u]);
}

bool merge(int u, int v)
{
	u = findpar(u); v = findpar(v);
	if (u == v || (moji[u] && moji[v])) return false;

	if (par[u] > par[v]) swap(u, v);
	par[u] += par[v];
	par[v] = u;
	if (moji[v]) moji[u] = true;

	return true;
}

void solve() 
{
	ll T, res = 0;
	cin >> T;

	int n; vector<DATA> ldk;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		par[i] = -1;
	}

	int nn;

	cin >> nn;

	for (int i = 1; i <= nn; i++)
	{
		int u;
		cin >> u;
		moji[u] = true;
	}

	int m; vector<int> ans;
	cin >> m;

	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		ldk.pb({u, v, w, i});
	}

	sort(ALL(ldk));
	

	reverse(ALL(ldk));

	for (auto v : ldk) if (!merge(v.ver1, v.ver2)) 
	{
		ans.pb(v.id);
		res += v.cost;
	}
	ldk.clear();


	int mm; vector<int> ans1;
	cin >> mm;

	for (int i = 1; i <= mm; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		ldk.pb({u, v, w, i});
	}

	sort(ALL(ldk));


	for (auto v : ldk) if (merge(v.ver1, v.ver2)) 
	{
		ans1.pb(v.id);
		res += v.cost;
	}

	cout << res*T << "\n";

	cout << (int)ans.size() << "\n";
	sort(ALL(ans)); for (auto v : ans) cout << v << " "; cout << "\n";

	cout << (int)ans1.size() << "\n";
	sort(ALL(ans1)); for (auto v : ans1) cout << v << " "; cout << "\n";
	
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("moji.inp","r",stdin); freopen("moji.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
