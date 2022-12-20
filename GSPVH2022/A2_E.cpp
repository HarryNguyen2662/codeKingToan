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

int vt[22];
long long dist[505][505], dp[1048580][22];
void solve() 
{
	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> dist[i][j];
		}
	
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	vt[0] = 1;
	for (int i = 1; i <= k; i++)
	{
		cin >> vt[i];
	}
	int lim = mask(k); 
	for (int i = 0; i < lim; i++) for (int j = 1; j <= k; j++) dp[i][j] = oo15;
	dp[0][0] = 0;
	for (int i = 1; i < lim; i++)
	for (int j = 1; j <= k; j++)
	if (ck(i, j - 1))
	{
		int newtt = (i^mask(j-1));
		if (newtt == 0)
		{
			dp[i][j] = dist[1][vt[j]];
		}
		for (int id = newtt; id >= 1; id ^= id & -id)
		{
			int w = __builtin_ctz(id) + 1;
			//cout << w << endl;
			dp[i][j] = min(dp[i][j], dp[newtt][w] + dist[vt[w]][vt[j]]);
		}
		//if (lim == i + 1) cout << dp[i][j] <<endl;
		//cout << i << " " << newtt << " " << vt[j] << " " << dp[i][j] << endl;
	}
	long long res = oo15;
	for (int i = 1; i <= k; i++) res =  min(res, dp[lim-1][i] + dist[vt[i]][1]);
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
    //freopen("banhkhuc.inp","r",stdin); freopen("banhkhuc.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
