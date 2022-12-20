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

int tt, ty[55], con[55], t;
int visit[55];
vector<int> a[55];
vector<int> ldk[3];

bool dfs(int u)
{
	if (visit[u] != t)
	{
		visit[u] = t;
	} else return false;

	for (auto v : a[u]) if (ck(tt, ty[v]))
	{
		if (!con[v] || dfs(con[v]))
		{
			con[v] = u;
			//cout << ty[v] << " " << ty[u] << endl; 
			return true;
		}
	}
	return false;
}

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		char x;
		cin >> x;
		if (x == 'G') ty[i] = 1; else if (x == 'B') ty[i] = 2; 
		ldk[ty[i]].pb(i);
	}
	int m; 
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v; 
		if (ty[u] == 2 || ty[v] == 0) swap(u, v);
		a[u].pb(v); 
	}
	//cout << ldk[0].size() << " " << ldk[1].size() << " " << ldk[2].size() << endl;
	int res = n;
	for ( tt = 3; tt <= 6; tt++) if (getbit(tt) == 2)
	{
			//cout << tt << endl;
		int dem = 0;
		t = 0;
		for (int i = 1; i <= n; i++) con[i] = visit[i] = 0;
		if (tt%2)
		{
			for (auto v : ldk[0])
			{
				t++;
				dem += dfs(v);
			}
		}
		else 
		{
			for (auto v : ldk[1])
			{
				t++;
				dem += dfs(v);
			}
		}
		//cout << endl;
		res = min(res, dem);
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
	//freopen("voi.inp","r",stdin); freopen("voi.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
