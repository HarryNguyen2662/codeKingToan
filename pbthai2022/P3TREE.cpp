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

class fenwicktree {
private:
    int len;
    vector<int> fen;
 
public:
    void reset(int sz) {
    	fen.assign(sz + 3, 0);
        len = sz;
    }
 
    void updup(int id, int val)
    {
    	for (; id <= len; id += (id&(-id))) fen[id] += val;
    }

	int getdown(int id)
	{
		int res = 0;
		for (; id; id -= (id&(-id))) res += fen[id];
		return res;
	}

	void upddown(int id, int val)
    {
    	for (; id; id -= (id&(-id))) fen[id] += val;
    }

	int getup(int id)
	{
		int res = 0;
		for (; id <= len; id += (id&(-id))) res += fen[id];
		return res;
	}
};

fenwicktree ldk;

vector<int> a[100005];
int child[100005];
int n;
ll ans1[100005], ans2[100005], ans3[100005];

void dfs(int u, int par)
{
	child[u] = 1;
	int su = 0;

	for (auto v : a[u])
	if (v != par)
	{
		int cur = ldk.getdown(u - 1);
		dfs(v, u);
		
		child[u] += child[v];

		cur = ldk.getdown(u - 1) - cur;
		int cur1 = child[v] - cur;

		// cout << u << " " << v << " " << cur << " " << cur1 << endl;
		su += cur;

		ans1[u] -= 1ll*cur*cur;
		ans2[u] -= 1ll*cur*cur1;
		ans3[u] -= 1ll*cur1*cur1; 
	}

	int su1 = child[u] - su - 1;
	su = u - 1 - su;; su1 = (n - u) - su1;

	ans1[u] -= 1ll*su*su;
	ans2[u] -= 1ll*su*su1;
	ans3[u] -= 1ll*su1*su1;

	su = u - 1; su1 = n - u;

	ans1[u] += 1ll*su*su;
	ans2[u] += 1ll*su*su1;
	ans3[u] += 1ll*su1*su1;

	ldk.updup(u, 1);
}

void solve() 
{
	int p1, p2, p3;
	cin >> n;
	cin >> p1 >> p2 >> p3;

	ldk.reset(n);

	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}

	dfs(1, 0);

	ll ans = 0;

	if (p2 > max(p1, p3)) 
	{
		for (int i = 1; i <= n; i++)
		{
			ans += ans1[i];
		}
		ans /= 2;
	}
	else if (p2 < min(p1, p3))
	{
		for (int i = 1; i <= n; i++)
		{
			ans += ans3[i];
		}
		ans /= 2;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			ans += ans2[i];
		}
	}

	cout << ans;
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
