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

int n, k;
int dem[305];
char s[306];
int dp[305][305][305];

int f(int l, int r, int sl)
{

	if(dp[l][r][sl] != -1) return dp[l][r][sl];
 
	if (sl == k)
	{
		return dp[l][r][sl] = 0;
	}

	if (dem[l-1] + dem[n] - dem[r] - sl == k)
	{
		return dp[l][r][sl] = 1;
	}

	dp[l][r][sl] = 0;

	if ((r - l + 1)%2 == n%2)
	{
		if (s[l] == 'B') dp[l][r][sl] = f(l + 1, r, sl + 1); else dp[l][r][sl] = f(l + 1, r, sl);
		if (s[r] == 'B') dp[l][r][sl] = max(dp[l][r][sl], f(l, r - 1, sl + 1)); 
		else dp[l][r][sl] = max(dp[l][r][sl], f(l, r - 1, sl));
	}	
	else
	{
		dp[l][r][sl] = f(l + 1, r, sl);
		dp[l][r][sl] = min(dp[l][r][sl], f(l, r - 1, sl));
	}

	 return dp[l][r][sl];
}

void solve() 
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		if (s[i] == 'B') dem[i]++;
		dem[i] += dem[i-1];
	}
	for (int i =1; i <= n; i++) for (int j = 1; j <= n; j++) for (int e = 0; e <= n; e++) dp[i][j][e] = -1;

	if (f(1, n, 0) == 1) cout << "YES\n"; else cout << "NO";
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
