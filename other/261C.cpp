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

long long dp[60][60][2];

void solve() 
{	
	long long n, t;
	cin >> n >> t;

	int dem = 0;
	while(t > 1)
	{
		dem++;
		if (t%2)
		{
			cout << "0"; return;
		}
		t /= 2;
	}

	n++;
	dem++;
	dp[55][0][1] = 1;
	for (int i = 55; i > 0; i--)	
	for (int j  = 0; j <= dem; j++)
	for (int ti = 0; ti <= 1; ti++)
	for (int cur = 0; cur <= 1; cur++)
	if (ti == 0 || (ti == 1 && cur <= ck(n, i - 1)))
	{
		int nti = 0; if (ti && cur == ck(n, i - 1)) nti = 1;

		dp[i - 1][j + cur][nti] += dp[i][j][ti];
	}
	if (dem == 1) cout << dp[0][dem][0] + dp[0][dem][1] - 1;
	else cout << dp[0][dem][0] + dp[0][dem][1];
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
