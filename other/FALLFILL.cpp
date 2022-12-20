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

ll dp[1000005], dp1[1000005], a[1000005], b[1000005];

void solve() 
{
	int n;
	ll mx = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
		mx = max(mx, a[i]);
	}
	ll x, y, z, f;
	cin >> x >> y >> z >> f;

	cout << 1ll*y*n + 1ll*mx*(x + z) << " ";

	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1];
		dp[i] += max(0ll, a[i - 1] - a[i]);
		a[i] = max(a[i], a[i-1]);
	}

	for (int i = n - 1; i; i--)
	{
		dp1[i] = dp1[i + 1];
		dp1[i] += max(0ll, b[i + 1] - b[i]);
		b[i] = max(b[i], b[i + 1]);
	}	

	ll ans = min(dp[n], dp1[1]);

	for (int i = 1; i < n; i++) ans = min(ans, dp[i] + dp1[i + 1]);

	cout << f*ans;

}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
