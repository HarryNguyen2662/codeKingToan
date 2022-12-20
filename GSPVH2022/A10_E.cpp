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
int cnt = 0, cs[600005];
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
} ldk;

void dfs(int u, int par)
{
	cs[++cnt] = u;

	for (auto v : a[u]) if (v != par)
	{
		dfs(v, u);
	}

	cs[++cnt] = -u;
}

void solve() 
{
	int n, root;
	cin >> n >> n >> root;

	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}

	ldk.reset(n);

	dfs(root, 0);

	long long res = 0;

	for (int i = 1; i <= cnt; i++)
	if (cs[i] > 0)
	{
		res += ldk.get(cs[i] + 1);
		ldk.update(cs[i], 1);
	}
	else ldk.update(-cs[i], -1);

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
    //freopen("treeinv.inp","r",stdin); freopen("treeinv.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
