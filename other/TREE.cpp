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

int n, par[50005];
int findpar(int x)
{
	return par[x] < 0 ? x : par[x] = findpar(par[x]);
}
bool merge(int u, int v)
{
	u = findpar(u); v = findpar(v);
	if (u == v) return false;
	if (par[u] > par[v]) swap(u, v);
	par[u] += par[v];
	par[v] = u;
	return true;
}
vector<pair<int,pair<int,int>>> ldk;
void sol()
{
	int u, v, c;
	cin >> u >> v >> c;
	ldk.pb({c, {u, v}});
	sort(ALL(ldk));
	for (int i = 1; i <= n; i++) par[i] = -1;
	long long res = 0;
	for (auto v : ldk) if (merge(v.se.fi, v.se.se)) res = res + v.fi;
	cout << res << "\n";
}
void solve() 
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		ldk.pb({c, {u, v}});
	}
	int query;
	cin >> query;
	while(query--) sol();
}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
