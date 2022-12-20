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
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807, oo13 = 1e13;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> lu[1005];
vector<pair<int,int>> luu[1005];
long long dp[1005][1005][12];
pair<int,int> a[1005];
int cost[1005];

long long dist(int i, int j)
{
	return abs(a[i].fi - a[j].fi) + abs(a[i].se - a[j].se);
}

void solve() 
{
	int n, W, P;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].fi >> a[i].se >> cost[i];
	}

	cin >> W;
	cin >> P;

	for (int i = 1; i <= n; i++)
	{	
		lu[i].pb(0); luu[i].pb({W, 0});
		for (int j = 1; j <= n; j++) if (i != j)
		{
			long long ij = dist(i, j);
			if (ij <= W)
			{
				lu[i].pb(W - ij);
				luu[i].pb({ij, j});
			}
		}
		sort(ALL(lu[i])); lu[i].resize(unique(ALL(lu[i])) - lu[i].begin());
		sort(ALL(luu[i])); luu[i].resize(unique(ALL(luu[i])) - luu[i].begin());

		for (int j = 0; j < (int)lu[i].size(); j++)
		for (int e = 0; e <= P; e++) dp[i][j][e] = oo15;
		
	}
	dp[1][0][0] = 0;

	for (int e = 0; e < P; e++)
	for (int i = 1; i <= n; i++)
	{
		long long re = oo15;
		int l = -1;

		for (int j = 0; j < (int)luu[i].size(); j++)
		{
			while(l + 1 < (int)lu[i].size() && lu[i][l+1] <= luu[i][j].fi)
			{
				l++;
				re = min(re, dp[i][l][e] + -1ll*cost[i]*lu[i][l]);
			}
			dp[luu[i][j].se][0][e + 1] = min(dp[luu[i][j].se][0][e + 1], re + 1ll*cost[i]*luu[i][j].fi);
		}

		for (int j = 0; j + 1 < (int)luu[i].size(); j++)
		{
			int id = lower_bound(ALL(lu[luu[i][j].se]), W - luu[i][j].fi) - lu[luu[i][j].se].begin();
			
			dp[luu[i][j].se][id][e + 1] = min(dp[luu[i][j].se][id][e + 1], re + 1ll*W*cost[i]);			
		}
	}
	long long res = oo15;

	for (int e = 1; e <= P; e++) res = min(res, dp[2][0][e]);

	cout << (res >= oo13 ? -1 : res);
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
