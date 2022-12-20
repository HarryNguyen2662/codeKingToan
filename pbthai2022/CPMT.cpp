#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define fi first
#define se second
#define pb push_back
#define log 7
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

int gcd(int x, int y)
{
	if (y == 0) return x;

	return gcd(y, x%y);
}

int a[205][205], gc[202][202][202][8], lg[205];
long long su[205][205];

void solve() 
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	for(int j = 1; j <= m; j++)
	{
		cin >> a[i][j];
		su[i][j] = su[i-1][j] + su[i][j-1] + a[i][j] - su[i-1][j-1];
	}

	for (int e = 1; e <= m; e++)
	{
		for (int i = 1; i <= n; i++)
		{
			gc[e][i][i][0] = a[i][e];
			for (int j = i + 1; j <= n; j++)
			{
				gc[e][i][j][0] = gcd(gc[e][i][j-1][0], a[j][e]);
			}
		}
	}

	long long res = oo18;

	for (int i = 1; i <= m; i++)
	{
		lg[i] = lg[i-1];
		while(mask(lg[i]) <= i) lg[i]++; lg[i]--;
	}

	auto getsum = [&](const int &x, const int &y, const int &u, const int &v)
	{
		return su[u][v] - su[x-1][v] - su[u][y-1] + su[x-1][y-1];
	};


	auto getgcd = [&](const int &i, const int &j, const int &l, const int &r)
	{
		int k = lg[r - l + 1];
		return gcd(gc[l][i][j][k], gc[r - mask(k) + 1][i][j][k]);
	};

	for (int i = 1; i <= n; i++)
	for (int j = i; j <= n; j++)
	{
		for (int ii = 1; ii <= log; ii++)
		for (int e = 1; e <= m - mask(ii) + 1; e++)
			gc[e][i][j][ii] = gcd(gc[e][i][j][ii-1], gc[e + mask(ii - 1)][i][j][ii-1]);
		
		int l = 1;
		for (int e = 1; e <= m; e++)
		{
			while(l < e && getgcd(i, j, l + 1, e) == 1) l++;
			
			if(getgcd(i, j, l, e) == 1) res = min(res, getsum(i, l, j, e));
		}
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
