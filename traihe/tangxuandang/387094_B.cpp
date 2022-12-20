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

int par[100005];
pair<int,int> a[103005];
bool ti[103905];

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
}

void solve() 
{
	int n, m;
	vector<int> diff;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].fi >> a[i].se >> ti[i];
		a[i].fi--;
		diff.pb(a[i].fi); diff.pb(a[i].se);
	}
	sort(ALL(diff)); diff.resize(unique(ALL(diff)) - diff.begin());
	n = (int)diff.size();
	for (int i = 1; i <= 2*n; i++) par[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int l = lower_bound(ALL(diff), a[i].fi) - diff.begin() + 1;
		int r = lower_bound(ALL(diff), a[i].se) - diff.begin() + 1;
		if (!ti[i])
		{
			merge(l, r); merge(l + n, r + n);
		}
		else
		{
			merge(l, r + n); merge(l + n, r);
		}
		if (findpar(l) == findpar(l + n) || findpar(r) == findpar(r + n))
		{
			cout << i - 1;
			return;
		}
	}
	cout << m;
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
