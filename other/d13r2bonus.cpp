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

vector<ll> g[2][5005], f[2][5005];

vector<int> de[2][5005], dee[2][5005];

ll a[5005][5005];

bool cmp(const pair<int,int> &x, const pair<int,int> &y)
{
	return x.fi*x.fi + x.se*x.se < y.fi*y.fi + y.se*y.se;
}


bool maximize(ll &x, const ll &y)
{
	if (x < y)
	{
		x = y; 
		return true;
	}
	return false;
}

bool minimize(ll &x, const ll &y)
{
	if (x > y)
	{
		x = y; 
		return true;
	}
	return false;
}
void solve() 
{
	vector<pair<int,int>> diff;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		g[0][i].resize(m + 1); f[0][i].resize(m + 1);
		g[1][i].resize(m + 1); f[1][i].resize(m + 1); 

		de[0][i].resize(m + 1); dee[0][i].resize(m + 1);
		de[1][i].resize(m + 1); dee[1][i].resize(m + 1); 
		
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if (i - 1 + j - 1 != 0)
			diff.pb({i - 1, j - 1});
			f[0][i][j] = -oo18; f[1][i][j] = a[i][j];
			g[0][i][j] = oo18; g[1][i][j] = a[i][j];
			de[1][i][j] = 1; de[0][i][j] = 0;
			dee[1][i][j] = 1; dee[0][i][j] = 0;
		}
	}
	sort(ALL(diff), cmp);

	auto check = [&](const int &x, const int &y)
	{
		return (x >= 1 && x <= n && y >= 1 && y <= m);
	};

	for (int e = 0; e < (int)diff.size(); e++)
	{

		auto v = diff[e];

		int val = v.fi*v.fi + v.se*v.se;
		// cout << v.fi << " " << v.se << " " << val << endl;
		if (e > 0 && val > diff[e-1].fi*diff[e-1].fi + diff[e-1].se*diff[e-1].se)
		{
			for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
			{
				if (n == 1)
				{
					maximize(f[1][i][j], f[0][i][j]);
					minimize(g[1][i][j], g[0][i][j]);
				}
				else
				{
					f[1][i][j] = f[0][i][j];
					g[1][i][j] = g[0][i][j];
				}
				de[1][i][j] = de[0][i][j];
				dee[1][i][j] = dee[0][i][j];
			}
		}

		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (check(i + v.fi, j + v.se)) 
			{
				if (minimize(g[0][i][j], g[1][i + v.fi][j + v.se] + a[i][j]))
				{
					de[0][i][j] = de[1][i + v.fi][j + v.se] + 1;
				}
				if  (maximize(f[0][i][j], f[1][i + v.fi][j + v.se] + a[i][j]))
				{
					dee[0][i][j] = dee[1][i + v.fi][j + v.se] + 1;
				}
			}
			if (check(i - v.fi, j + v.se)) 
			{
				if (minimize(g[0][i][j], g[1][i - v.fi][j + v.se] + a[i][j]))
				{
					de[0][i][j] = de[1][i - v.fi][j + v.se] + 1;
				}
				if  (maximize(f[0][i][j], f[1][i - v.fi][j + v.se] + a[i][j]))
				{
					dee[0][i][j] = dee[1][i - v.fi][j + v.se] + 1;
				}
			}
			if (check(i + v.fi, j - v.se))
			{
				if (minimize(g[0][i][j], g[1][i + v.fi][j - v.se] + a[i][j]))
				{
					de[0][i][j] = de[1][i + v.fi][j - v.se] + 1;
				}
				if  (maximize(f[0][i][j], f[1][i + v.fi][j - v.se] + a[i][j]))
				{
					dee[0][i][j] = dee[1][i + v.fi][j - v.se] + 1;
				}
			}
			if (check(i - v.fi, j - v.se)) 
			{
				if (minimize(g[0][i][j], g[1][i - v.fi][j - v.se] + a[i][j]))
				{
					de[0][i][j] = de[1][i - v.fi][j - v.se] + 1;
				}
				if  (maximize(f[0][i][j], f[1][i - v.fi][j - v.se] + a[i][j]))
				{
					dee[0][i][j] = dee[1][i - v.fi][j - v.se] + 1;
				}
			}
			// if (f[0][i][j] == 12) cout << dee[i][j] << endl;
		}
	}

	ll res = -oo18;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			// cout << i << " " << j << " " << f[0][i][j] << " " << g[0][i][j] << endl;
			if (de[0][i][j] >= 3) res = max(res, -g[0][i][j]);
			if (dee[0][i][j] >= 3) res = max(res, f[0][i][j]);	
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
