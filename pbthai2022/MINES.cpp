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

long long power(long long x, long long y)
{
	if (y == 0) return 1;
	long long xx = power(x, y/2);
	if (y%2) return xx*xx%MOD*x%MOD; else return xx*xx%MOD;
}

int ans = 0;
bitset<10001> be[10001];
int f[10005];

void add(int id)
{

	for (int i = 0; i <= 10000; i++)
	if (be[id][i] == 1)
	{
		if (f[i] == -1)
		{
			f[i] = id;
			ans++;
			return;
		}
		be[id] ^= be[f[i]];
	}
}

void solve() 
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		int w;
		cin >> w;
		if (w == -1) continue;
		
		be[i*m + j][n*m] = w;

		if (i > 0) be[i*m + j][(i - 1)*m + j] = 1;
		if (j > 0) be[i*m + j][i*m + j - 1] = 1;
		if (i + 1 < n) be[i*m + j][(i + 1)*m + j] = 1;
		if (j + 1 < m) be[i*m + j][i*m + j + 1] = 1;
	}


	for (int i = 0; i <= 10000; i++) f[i] = -1;

	for (int i = 0; i < n*m; i++)
	{
		add(i);

		for (int j = 0; j <= n*m; j++)
			cout << be[i][j];

		cout << endl;
	}


	cout << power(2, n*m - ans);
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
