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

long double c[205][205], d[205];

void solve() 
{	
	int n, m, s, t;
	vector<pair<pair<int,int>, long double>> ldk;
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		long double c;
		cin >> u >> v >> c;
		d[u]+= c; d[v]+= c;	
		ldk.pb({{u, v}, c});
	}

	for (int i = 1; i <= n; i++) c[i][i] = c[i][n + 1] = 1;

	c[t][n + 1] = 0;

	for (auto v : ldk)
	if (v.fi.se != t && v.fi.fi != t)
	{
		c[v.fi.fi][v.fi.se] = -v.se/d[v.fi.fi];
		c[v.fi.se][v.fi.fi] = -v.se/d[v.fi.se];
	}	

	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		if (c[j][i] != 0)
		{
			swap(c[j], c[i]);
			break;
		}
		for (int j = i + 1; j <= n; j++)
		{
			long double w = c[j][i]/c[i][i];
			for (int e = i; e <= n + 1; e++)
			{
				c[j][e] -= c[i][e]*w;
			}
		}
	}

	for (int i = n; i; i--)
	{
		c[i][n + 1] /= c[i][i];
		for (int j = i - 1; j; j--)
		{
			c[j][n + 1] -= c[i][n + 1]*c[j][i]; 
		}
	}

	cout << fixed << setp(9) << c[s][n + 1];
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
