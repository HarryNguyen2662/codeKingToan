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

ll a[405][405];
int x[405], y[405];

ll get(int i, int ii, int j)
{
	return a[ii][j] - a[i-1][j];
}

void solve() 
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= m; i++) cin >> y[i];

	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) 
	{
		cin >> a[i][j];
		a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
	}

	ll res = 0;

	for (int i = 1; i <= n; i++) 
	for (int ii = i; ii <= n; ii++)
	{
		ll heigh = x[ii] - x[i];
		ll mn = -heigh*1ll*y[1];

		for (int j = 1; j <= m; j++)
		{
			res = max(res, -heigh*1ll*y[j] + get(i, ii, j) - mn);
			mn = min(mn, -heigh*1ll*y[j + 1] + get(i, ii, j));
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
