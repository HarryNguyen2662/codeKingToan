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

int a[100005];
int par[100005];
long long mn[100005];

int findpar(int u)
{
	return par[u] < 0 ? u : par[u] = findpar(par[u]);
}

void merge(int u, int v)
{
	u = findpar(u); v = findpar(v);
	if (u == v) return;
	if (par[u] > par[v]) swap(u, v);
	par[u] += par[v];
	par[v] = u;
	mn[u] = min(mn[u], mn[v]);
}

void solve() 
{
	vector<long long> diff;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		diff.pb(a[i]);
	}
	sort(ALL(diff)); diff.resize(unique(ALL(diff)) - diff.begin());
	for (int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(ALL(diff), a[i]) - diff.begin() + 1;
		par[i] = -1;
		mn[i] = diff[a[i]];
	}
	long long res = 0;
	for (int i = 1; i <= n; i++)
	if (a[i] != i)
	{
		res += diff[a[i]];
		merge(a[i], a[a[i]]);
	}
	for (int i = 1; i <= n; i++)
	if (par[i] < -1)
	{
		long long w = -par[i];
		res += min((w - 2)*mn[i], (w + 1)*diff[0] + mn[i]);
	}
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
