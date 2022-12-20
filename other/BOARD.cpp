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
//long long res = 0;
int n, m, k;
int s[1500][1500];
// void trau(int x, int y)
// {
// 	if (x == 1 && y == m + 1)
// 	{
// 		for (int i = 1; i <= n - 1; i++)
// 		for (int j = 1; j <= m - 1; j++)
// 		{
// 			int dem = 0;
// 			if (s[i][j] == 0) dem++; if (s[i+1][j] == 0) dem++; if (s[i][j+1] == 0) dem++; if (s[i+1][j+1] == 0) dem++;
// 			if (dem%2) return;			
// 		}
// 		res++; res %= MOD1;
// 		return;
// 	}
// 	if (s[x][y] == -1)
// 	{
// 		s[x][y] = 0;
// 		if (x == n) trau(1, y+1); else trau(x + 1, y);
// 		s[x][y] = 1;
// 		if (x == n) trau(1, y+1); else trau(x + 1, y);
// 		s[x][y] = -1;
// 	}
// 	else
// 	{
// 		if (x == n) trau(1, y+1); else trau(x + 1, y);
// 	}
// }
// void solve1()
// {
// 	for (int i = 1; i <= n; i++)
// 	for (int j = 1; j <= m; j++) s[i][j] = -1;
// 	for (int i = 1; i <= k; i++)
// 	{
// 		int x, y, c;
// 		cin >> x >> y >> c;
// 		s[x][y] = c;
// 	}
// 	trau(1, 1);
// 	cout << res;
// }
vector<int> ldk[2500], ld[2500];
long long dp[2500][2500];
void solve2()
{
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) s[i][j] = -1;
	for (int i = 1; i <= k; i++)
	{
		int x, y, c;
		cin >> x >> y >> c;
		s[x][y] = c;
	}
	int lim = mask(n) - 1; 
	for (int i = 1; i <= m; i++) for (int j = 0; j <= lim; j++)
	{
		bool kt = true;
		for (int e = 1; e <= n; e++) if (s[e][i] != -1 && ck(j, e - 1) != s[e][i])
		{
			kt = false;
			break;
		}
		if (kt) ldk[i].pb(j);
	}
	for (auto j : ldk[1]) dp[1][j] = 1;
	
	for (int i = 0; i <= lim; i++) 
	for (int j = 0; j <= lim; j++) 
	{
		if (((i^j) == 0) || ((i^j) == mask(n)-1)) 
		{
			ld[i].pb(j);
			//cout << i << " " << j << endl;
		}
	}
	
	//for (auto i : ldk[3]) cout << i << endl;
	for (int i = 2; i <= m; i++)
	for (auto j : ldk[i])
	{
		for (auto e : ld[j]) 
		{
			dp[i][j] = (dp[i][j] + dp[i-1][e])%MOD1;
			//cout << i << " " << j << " " << e << endl;
		}
		//cout << dp[i][j] << endl;
	}
	
	long long res = 0;
	//for (auto i : ldk[m]) cout << dp[m][i] << endl;
	for (auto i : ldk[m]) res = (res + dp[m][i])%MOD1;
	cout << res;
}

void solve() 
{
	cin >> n >> m >> k;
	//if (n*m <= 20) solve1();
	if (n <= 11 && m <= 2000)
	solve2();
	else cout << 0;
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
