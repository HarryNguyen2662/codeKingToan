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


const int lim = 1e5;

vector<int> free_square, a[100005], lst[100005];
bool dd[100005];
int va[100005];
long long ans[100005];

void prepare()
{

	auto check = [&] (const int &val)
	{
		for (int i = 2; 1ll*i*i <= val; i++) if (val%(i*i) == 0) return false;
		return true;
	};

	free_square.pb(1);
	for (int i = 2; i <= lim; i++) if (check(i)) free_square.pb(i);
}

void add(const int &id)
{
	for (int i = 1; 1ll*i*i <= va[id]; i++) if (va[id]%i == 0)
	{
		lst[i].pb(id);
		if (va[id]/i != i) lst[va[id]/i].pb(id);
	}
}

void dfs(int u, int par)
{
	add(u);
	for (auto v : a[u]) if (v != par)
	{
		dfs(v, u);
	}
	add(u);
}

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> va[i];
	}

	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}

	dfs(1, 0);
	prepare();


	for (auto v : free_square)
	if ((int)lst[v].size())
	{
		int ti = 1;
		int val = v;
		for (int i = 2; 1ll*i*i <= val; i++) if (val%i == 0)
		{
			ti = 1 - ti; val /= i;
		}
		if (val > 1)
		{
			ti = 1 - ti; 
		}
		if (ti == 0) ti = -1;
		
		for (int i  = 0; i < (int)lst[v].size(); i++)
		{
			if (!dd[lst[v][i]])
			{
				ans[lst[v][i]] -= ti*(i - 1); dd[lst[v][i]] = true;
			}
			else ans[lst[v][i]] += ti*i;
		}
		
		for (auto id : lst[v]) dd[id] = false;
	}
	
	for (int i = 1; i <= n; i++) cout << ans[i]/2 << " ";
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
