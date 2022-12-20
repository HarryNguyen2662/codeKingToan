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

bool check(char x, char y)
{
    if (x == ']')
        return (y == '['||y =='?');
    if (x == '}')
        return (y == '{'||y =='?');
    if (x == ')')
        return (y == '('||y =='?');
    if (x == '?')
    {
        if (y == '[' || y == '(' || y == '{'||y =='?') return true;
    }
    return false;
}

long long dp[505][505];

void solve() 
{
	string s;
	cin >> s;
	int n = (int)s.size();
	s = "@" + s;
	for (int i = 2; i <= n; i++)
	for (int j = i - 1; j; j--)
	if (i - j  == 1)
	{
		if (check(s[i], s[j]))
		dp[j][i] = 1 + 2*(s[i] == s[j]);
	}
	else
	{
		if (check(s[i], s[j])) dp[j][i] = 1ll*(1 + 2*(s[i] == s[j]))*dp[j + 1][i-1]%MOD;
		if (check(s[i], s[i-1])) dp[j][i] =(dp[j][i] + 1ll*(1 + 2*(s[i] == s[i-1]))*dp[j][i-2]%MOD)%MOD;
		for(int e = j + 1; e < i-1; e++)
        if (check(s[i], s[e]))
        {
            dp[j][i] = (dp[j][i] + 1ll*(1 + 2*(s[i] == s[e]))*dp[e+1][i-1]%MOD*dp[j][e-1]%MOD)%MOD;
        }
	}
	//cout << s[6] << endl;
	//cout << dp[1][6] << endl;
	cout << dp[1][n];
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
