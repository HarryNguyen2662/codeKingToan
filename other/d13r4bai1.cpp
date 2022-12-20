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

int s[1005][1005], a[1005][1005];
bool dd[1000005];
pair<int,int> vt[1000005];

void solve() 
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	{
		cin >> a[i][j];
		s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i-1][j-1];
		if (vt[a[i][j]].fi == 0)
		{
			s[i][j]++;
			vt[a[i][j]] = {i, j};
		}
	}

	int q;
	cin >> q;
	while(q--)
	{
		int x, y, u, v;
		cin >> x >> y >> u >> v;
		int res = s[u][v] - s[x-1][v] - s[u][y-1] + s[x-1][y-1];
		// cout << x << " " << y << " " << u << " " << v << endl; 
		for (int i = x; i <= u; i++)
		for (int j = y; j <= v; j += v - y)
		{
			if (dd[a[i][j]] == false)
			{
				// cout << i << " " << j << endl;
				// cout << vt[a[i][j]].fi << " " << vt[a[i][j]].se << endl;
				dd[a[i][j]] = true;
				if (vt[a[i][j]].fi < x || vt[a[i][j]].fi > u || vt[a[i][j]].se < y || vt[a[i][j]].se > v) res++;
			}
			if (v == y) break;
		}
		for (int i = x; i <= u; i += u - x)
		{
			for (int j = y; j <= v; j++)
			if (dd[a[i][j]] == false)
			{
				dd[a[i][j]] = true;
				if (vt[a[i][j]].fi < x || vt[a[i][j]].fi > u || vt[a[i][j]].se < y || vt[a[i][j]].se > v) res++;
			}
			if (x == u) break;
		}

		for (int i = x; i <= u; i++)
		{
			for (int j = y; j <= v; j += v - y)
			{
				dd[a[i][j]] = false;
				if (y == v) break;
			}
		}
		for (int i = x; i <= u; i += u - x)
		{
			for (int j = y; j <= v; j ++)
			{
				dd[a[i][j]] = false;
			}
			if (x == u) break;
		}
		cout << res << "\n";
	}
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
