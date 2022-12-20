#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
#define fi first
#define se second
#define pb push_back
#define log 60
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

bool f[105][105];
ll su[105];

void solve() 
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> su[i];
		su[i] += su[i-1];
	}

	ll ans = 0;

	for (int e = log; e >= 0; e--)
	{
		for (int i = 0; i <= n; i++) for (int j = 0; j <= min(i, k); j++) f[i][j] = false;
		f[0][0] = true;

		ans += mask(e);	

		for (int i = 0; i < n; i++)
		for (int j = 0; j <= min(i, k); j++)
		if (f[i][j])
		{
			for (int ii = i + 1; ii <= n; ii++) if (((su[ii] - su[i])&ans) == ans) f[ii][j + 1] = true;
		}

		if (f[n][k] == false) ans -= mask(e);
	}

	cout << ans;
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
