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
const long long MOD = 20030101;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pair<int,int> dp[1005][1005];
int d[50], dd[50], nxt[1005][50], nxtt[1005][50];

void solve() 
{
	string s, t;
	cin >> s >> t;
	int n = (int)s.size(), m = (int)t.size();
    for (int i = 0; i < 26; i++) d[i] = dd[i] = 0;

	for (int i = n; i >= 0; i--)
	{
        for (int j = 0; j < 26; j++) nxt[i][j] = d[j];
        if (i)
        d[s[i-1] - 'a'] = i;
	}



    for (int i = m; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++) nxtt[i][j] = dd[j];
        if (i)
        dd[t[i-1] - 'a'] = i; 
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) dp[i][j] = {0, 0};

    dp[0][0] = {0, 1};

    int mxlen = 0;

    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    if (dp[i][j].se != 0)
    {
        for (int e = 0; e < 26; e++) if (nxt[i][e] && nxtt[j][e])
        {
            int ni = nxt[i][e], nj = nxtt[j][e];
            if (dp[i][j].fi + 1 > dp[ni][nj].fi)
            {
                dp[ni][nj] = {dp[i][j].fi + 1, dp[i][j].se};
                mxlen = max(mxlen, dp[i][j].fi + 1);
            }
            else if (dp[i][j].fi + 1 == dp[ni][nj].fi)
            {
                dp[ni][nj].se += dp[i][j].se; if (dp[ni][nj].se >= MOD) dp[ni][nj].se -= MOD;
            }
        }
    }


    int res = 0;

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (dp[i][j].fi == mxlen) 
    {
        res += dp[i][j].se; if (res >= MOD) res -= MOD;
    }

    cout << mxlen << " "<< res << "\n";

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
    cin >> testcase;
    while(testcase--)
        solve();
}
