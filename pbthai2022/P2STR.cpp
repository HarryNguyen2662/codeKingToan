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

int f[5002][5002], g[5002][5002];

void solve() 
{
	string s, st;
	cin >> s;
	int n = (int)s.size();
	st = s;
	reverse(ALL(st));
	st = "@" + st;
	s = "@" + s;

	for (int i = 1; i <= n; i++) 
	for (int j = 1; j <= n; j++)
	{
		if (s[i] == st[j])
		{
			f[i][j] = f[i - 1][j - 1] + 1; 
		}

		int e = j + n - i;
		if (e <= n)
		{
			if (s[j] == s[e])
			{
				g[j][e] = g[j - 1][e + 1] + 1;
			}
		}
	}


	ll ans = 0;

	for (int i = 1; i <= n; i++)
	{
		int dem = 1;
		for (int j = i + 1; j <= n; j++)
		{

			 // cout << i << " " << j << " " << g[i][j] << " " << dem << endl;
			ans += 1ll*g[i][j]*dem;
			if (f[j][n - (i + 1) + 1] >= j - i) dem++;
		}
		// cout << endl;
		dem = 0;
		for (int j = i - 1; j; j--)
		{
			ans += 1ll*g[j][i]*dem;
			if (f[i - 1][n - j + 1] >= i - j) dem++;
			 // cout << j << " " << i << " " << g[j][i] << " " << dem << endl;
		}
		// cout << endl;
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
