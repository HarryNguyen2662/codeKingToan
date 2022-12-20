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

int x0, y0, d;

long long su[300005];
pair<long long, int> a[300005];

void gd(int u, int v)
{
	if (v == 0)
	{
		d = u; x0 = 1; y0 = 0;
		return;
	}
	gd(v, u%v);
	int t = x0;
	x0 = y0;
	y0 = t - u/v*y0;
}

void solve() 
{
	int n;
	long long sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].fi >> a[i].se;
		a[i].fi -= a[i].se;
	}


	sort(a + 1, a + 1 + n); reverse(a + 1, a + 1 + n);

	int p = 0;

	for (int i = 1; i <= n; i++)
	{
		su[i] = su[i - 1] + a[i].fi;
		sum += a[i].se;
		if (a[i].fi > 0) p = i;
	}
	int q;
	//cout << su[6] << endl;
	cin >> q;
	while(q--)
	{		
		int u, v;
		cin >> u >> v;

		gd(u, v);
		if (n%d)
		{
			cout  << "-1\n";
			continue;
		}

		int step = ceil(-(long double)(n/d*x0)/(v/d));
		//cout << step << endl; 
 		int x = (n/d)*x0 + (v/d)*step;
		if (x*u > n)
		{
			cout << "-1\n";
			continue;
		}

		//cout << x << endl;
		if (x*u > p)
		{
			cout << su[x*u] + sum << "\n";
			continue;
		}


		step = (p/u - (n/d)*x0)/(v/d);

		long long re = -1;		
			
		for (int i = step - 5; i <= step + 5; i++)
		{
			x = (n/d)*x0 + (v/d)*i;
			if (1ll*x*u >= 0 && 1ll*x*u <= n)
			re = max(re, su[x*u] + sum);
		}

		cout << re << "\n";
	}

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
