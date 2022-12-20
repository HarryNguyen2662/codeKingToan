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

long long a[1005][1005], d[1005][3][1005], dd[1005][3][1005], g[3], luu[10], gr[1005][1005];

void solve() 
{

	long long res = 0;
	for (int sl = 1; sl <= 5; sl++)
	{
		int n, m;
		cin >> n >> m;
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> a[i][j];
				a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];	
				d[i][0][0] = dd[j][0][0] = true;
			}
		}

		for (int i = 1; i <= n; i++)
		{
			g[0] = g[1] = g[2] = 0;
			for (int j = 1; j <= m; j++)
			{
				int w = a[i][j]%3;
				while(d[i][(w+2)%3][g[(w+2)%3]] || dd[j][(w+2)%3][g[(w+2)%3]]) g[(w+2)%3]++;
				gr[i][j] = g[(w+2)%3];
				d[i][w][gr[i][j]] = true;
				dd[j][w][gr[i][j]] = true;
			}
		}

		res ^= gr[n][m]; luu[sl] = gr[n][m];

		for (int i = 0; i <= max(n, m); i++)
		{
			for (int j = 0; j <= max(n, m); j++)
			{
				gr[i][j] = 0;
				d[i][0][j] = d[i][1][j] = d[i][2][j] = 0;
				dd[i][0][j] = dd[i][1][j] = dd[i][2][j] = 0;
			}
		}
	}
	//cout << res;
	for (int i = 1; i <= 5; i++)
	{
		cout << min(res^luu[i], 1ll) << "\n";
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
