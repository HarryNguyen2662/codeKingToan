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
const long long oo15 = 1e15, oo18 = 2e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, k; long long p;
vector<pair<int,int>> ldk[105];
int d[65539][105];
long long dp[105][65539];

long long f(int id, int MASK)
{
	if (dp[id][MASK] != -1) return dp[id][MASK];
	if (id == n)
	{
		return dp[id][MASK] = 1;
	}

	long long &res = dp[id][MASK]; res = 0;

	if (id >= 16)
	{
		res = f(id + 1, MASK/2) + f(id + 1, MASK/2 + mask(15));
	}
	else
	{ 
		res = f(id + 1, MASK) + f(id + 1, MASK + mask(id));
	}

	res = min(res, oo18);

	return res;
}

void solve() 
{
	cin >> n >> k >> p;
	for (int i = 1; i <= n; i++)
	{
		ldk[i].clear();
	}
	for (int i = 1; i <= k; i++) 
	{
		int l, r, x;
		cin >> l >> r >> x;
		ldk[r].pb({l, x});
	}
	for (int j = 0; j < mask(16); j++)
		for (int e = 1; e <= 16; e++)
		{
			d[j][e] = d[j][e - 1] + ck(j, e - 1);
		}

	for (int i = 0; i <= n; i++)
	for (int j = 0; j < mask(16); j++)
	{
		dp[i][j] = -1;

		for (auto v : ldk[i])
		{
		if (d[j][min(i, 16)] - d[j][v.fi - max(0, i - 16) - 1] != v.se)
		{
			dp[i][j] = 0; break;
		}
	}
	}

	f(0, 0); 

	int curmask = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i >= 17)
		{
			if (p <= dp[i][curmask/2])
			{
				curmask /= 2;
				cout << "0";
			}
			else
			{
				p -= dp[i][curmask/2];
				curmask = curmask/2 + mask(15);
				cout << "1";
			}
		}
		else 
		{
			if (p <= dp[i][curmask])
			{
				cout << "0";
			}
			else
			{
				p -= dp[i][curmask];
				curmask = curmask + mask(i-1);
				cout << "1";
			}
		}

	}

	cout << "\n";
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
    cin >> testcase;
    while(testcase--)
        solve();
}
