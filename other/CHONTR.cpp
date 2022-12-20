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

int a[2000005];

void solve() 
{
	int n, x, y, z; ll ans1 = 0, ans2 = 0, ans3 = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	cin >> x >> y >> z;

	for (int i = 1; i <= n; i++)
	{
		ll e = ans1, ee = ans2;
		if (a[i] == x)
		{
			ans1++;
		}
		if (a[i] == y)
		{
			ans2 += e;
		}
		if (a[i] == z)
		{
			ans3 += ee;
		}
	}

	cout << ans3;
}

int main() 
{   
    freopen("CHONTR.inp","r",stdin); freopen("CHONTR.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
