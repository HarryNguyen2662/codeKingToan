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
const long long MOD = 998244353;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long dp[28][300005];
const int lim = 300000;
vector<int> a[30];
int r[30], l[30];
bool vit[30];

void dfs(int u)
{
	vit[u] = true;

	
	
	for (int i = (l[u] == 0 ? 1 : l[u]); i <= (r[u] == 0 ? lim : r[u]); i++) dp[u][i] = 1;

	for(auto v : a[u]) 
	{
		if (!vit[v])
		dfs(v);

		for (int i = (l[u] == 0 ? 1 : l[u]); i <= (r[u] == 0 ? lim : r[u]); i++)
		if (l[v] == 0)
		{
			if (r[v] >= i)
			dp[u][i] = (dp[u][i] * ((dp[v][r[v]] - dp[v][i - 1] + MOD)%MOD))%MOD;
			else dp[u][i] = 0;
		}
		else
		{
			dp[u][i] = (dp[u][i] * dp[v][i])%MOD;
		}
	}

	for (int i = (l[u] == 0 ? 1 : l[u]); i <= (r[u] == 0 ? lim : r[u]); i++) dp[u][i] = (dp[u][i] + dp[u][i-1])%MOD;
}

void solve() 
{
	int n;
	cin >> n >> n;

	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		if ((int)s.size() == 1 && s[0] >= 'a' && s[0] <= 'z')
		{
			a[s[0] - 'a' + 1].pb(i);
			cin >> r[i];
			continue;
		}
		
		for (int e = 0; e < (int)s.size(); e++) l[i] = l[i]*10 + s[e] - '0';

		cin >> s;
		if ((int)s.size() == 1 && s[0] >= 'a' && s[0] <= 'z')
		{
			a[s[0] - 'a' + 1].pb(i);
		}
		else
		{
			for (int e = 0; e < (int)s.size(); e++) r[i] = r[i]*10 + s[e] - '0';
		}

	}

	long long res = 1;

	for (int i = 1; i <= n; i++) 
	if (vit[i] == false) 
	{	
		dfs(i);
		if (l[i] && r[i]) res = res*(dp[i][r[i]])%MOD;
	}	


	cout << res;
} 

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("funkcija.inp","r",stdin); freopen("funkcija.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
