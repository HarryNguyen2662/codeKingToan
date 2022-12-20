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

int n, q;
char s[100005];
long long dp[100005][3], ff[3], f[3][3][3];
long long cal(int l, int r)
{
	//cout << l << " " << r << endl;
	if (l == r)
	{
		return 0;
	}
	for (int i = l; i <= r; i++) for (int j = 0; j <= 2; j++) dp[i][j] = oo15;
	if (s[l] == '?')
	{
		for (int i = 0; i <= 2; i++) dp[l][i] = ff[i];
	} else dp[l][s[l]-'0'] = 0;
	for (int i = l + 1; i <= r; i++)
	if (s[i] != '?')
	{
		for (int j = 0; j <= 2; j++)
			for (int e = 0; e <= 2; e++)
				dp[i][e] = min(dp[i][e], dp[i-1][j] + f[j][s[i]-'0'][e]);
	}
	else
	{
		for (int j = 0; j <= 2; j++)
			for (int t = 0; t <= 2; t++)
				for (int e = 0; e <= 2; e++)
					dp[i][e] = min(dp[i][e], dp[i-1][j] + f[j][t][e] + ff[t]);
	}	
	return min({dp[r][0], dp[r][1], dp[r][2]});
}
void sol()
{
	int type;
	cin >> type;
	if (type == 1)
	{
		int vt; char x;
		cin >> vt >> x;
		s[vt] = x;
	}
	else 
	{
		int l, r;
		cin >> l >> r;
		cout << cal(l, r) << "\n";
	}
}
void solve() 
{
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 0; i <= 2; i++)
		for (int j = 0 ; j <= 2; j ++)
			for (int e = 0; e <= 2; e++) cin >> f[i][j][e];
	for (int i = 0; i <= 2; i++) cin >> ff[i];
	while(q--) sol();
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
