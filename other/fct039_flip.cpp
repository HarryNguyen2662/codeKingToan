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
const long long MOD = 1e9 + 5277;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll BASE = 9012005;

ll f[1005][1005], pw[1005];
int g[1005][1005];
char s[1005][1005];

ll get(int ti, int x, int y)
{
	return (f[ti][y] - f[ti][x - 1]*pw[y - x + 1] + MOD*MOD)%MOD;
}

int ge(int ti, int x, int y)
{
	return g[ti][y] - g[ti][x-1];
}

void solve() 
{
	int n, m, q;
	cin >> n >> m >> q;

	pw[0] = 1;
	for (int i = 1; i <= m; i++)
	{
		pw[i] = pw[i-1]*BASE%MOD;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> s[i][j];
			int cur = 1;
			if (s[i][j] == '*') cur = 2;
			
			g[i][j] = g[i][j-1] + (cur == 2);
			f[i][j] = 1ll*f[i][j-1]*BASE%MOD + cur; if (f[i][j] >= MOD) f[i][j] -= MOD;
		}
	}


	while(q--)
	{
		int x, y, u, v;
		cin >> x >> y >> u >> v;
		
		ll ans1 = get(x, y, v);
		ll ans2 = 0;
		
		int w1 = ge(x, y, v);
		int w2 = v - y + 1 - w1;
 		
 		for (int i = y; i <= v; i++)
		{
			ans2 = ans2*BASE%MOD + 1 + (s[x][i] == '.'); if (ans2 >= MOD) ans2 -= MOD;
		}


		bool kt = true;

		for (int i = x + 1; i <= u; i++) 
		{
			ll cur = get(i, y, v); int w = ge(i, y, v);

			if ((cur != ans1 || w != w1) && (cur != ans2 || w != w2))
			{
				kt = false; break;
			}
		}

		if (kt) cout << "YES\n"; else cout << "NO\n";
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
