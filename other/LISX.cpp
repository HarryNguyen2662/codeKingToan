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
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long dp[11][12][11][2][2];

void solve() 
{
	string l, r;
	int x; cin >> x; x--; l = to_string(x);
	cin >> x; x++; r = to_string(x);
	while((int)l.size() < (int)r.size()) l = "0" + l;

	int n = (int)r.size();

	for (int i = 0; i <= n; i++)
	for (int dai = 0; dai <= 0; dai++)
	for (int pre = 0; pre <= 9; pre++)
	for (int ok = 0; ok < 2; ok++)
	for (int ok1 = 0; ok1 < 2; ok1++) dp[i][dai][pre][ok][ok1] = 0;

	dp[0][0][0][0][0] = 1;

	for (int i = 0; i < n; i++)
	for (int dai = 0; dai <= 0; dai++)
	for (int pre = 0; pre <= 9; pre++)
	for (int ok = 0; ok < 2; ok++)
	for (int ok1 = 0; ok1 < 2; ok1++)
	for (int digit = (ok == 0 ? l[i] - '0' : 0); digit <= (ok1 == 1 ? r[i] - '0' : 9); digit++)
	{
		int newok = 0, newok1 = 0;
		if (digit == r[i] - '0') newok1 = ok1; 
		if (ok || digit > l[i] - '0') newok = 1;
		(dp[i + 1][dai + (digit > pre)][digit][newok][newok1] += dp[i][dai][pre][ok][ok1] ) %= MOD;
	}

	for (int i = 10; i; i--)
	{
		long long res = 0;
		for (int j = 9; j >= 0; j--) res = (res + dp[n][i][j][1][0])%MOD;
		if (res > 0)
		{
			cout << i << " " << res << "\n";
			return;
		}
	}

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
