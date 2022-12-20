#include<bits/stdc++.h>

using namespace std;

#define int long long
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


void solve() 
{
	int x, y, n;
	cin >> x >> y >> n;

	int t = __gcd(x, y);
	x /= t; y /= t;

	if (n >= y)
	{
		cout << x << "/" << y;
		return;
	}

	pair<int,int> re;
	long double ruu = 1005;

	for (int b = 1; b <= n; b++)
	{
		int t = (x*b)/y;

		for (int a = t - 5; a <= t + 5; a++)
		if (a >= 0)
		{

			long double we = (long double)x/y - (long double)a/b;
			if (we < 0) we = -we;
			if (we < ruu)
			{
				ruu = we;
				re = {a, b};
			}
		}
	}

	cout << re.fi << "/" << re.se;
}

signed main() 
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
