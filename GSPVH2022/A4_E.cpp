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

bool minimize(int &x, const int &y)
{
	if (x > y)
	{
		x = y; 
		return true;
	}
	return false;
}

int dp[200005][27][2];
pair<int,int> tv[200005][27][2];

void solve() 
{
	string s;
	cin >> s;
	int n = (int)s.size();
	for (int i = 1; i <= n; i++)
	for (int j = 0; j < 26; j++) dp[i][j][0] = dp[i][j][1] = oo; 
	s = "@" + s;

	for (int i = 0; i < 26; i++) dp[1][i][1] = abs(s[1] - 'A' - i);

	for (int i = 2; i <= n; i++)
	{
		int lu = 0;
		for (int j = 0; j < 26; j++)
		{
			if (dp[i-1][j][0] < dp[i-1][lu][0])
			{
				lu = j;
			}
			for (int t = 0; t < 2; t++)
			{
				
				if (minimize(dp[i][j][0], dp[i-1][j][t] + abs(s[i] - 'A' - j)))
				{
					tv[i][j][0] = {j, t};
				}
			}
		}
		//cout << lu << " " << dp[i-1][lu][0] << endl;
		for (int j = 0; j < 26; j++)
		if (j != lu)
		{
			dp[i][j][1] = dp[i-1][lu][0] + abs(s[i] - 'A' - j);
			tv[i][j][1] = {lu, 0};
		}
	}
	int re = 0;
	for (int i = 1; i < 26; i++)
	if (dp[n][i][0] < dp[n][re][0]) re = i;

	cout << dp[n][re][0] << "\n";

	int tt = 0;
	vector<int> ldk;
	while(n)
	{
		ldk.pb(re);
		//cout << re << " " << tt << endl;
		if (tt == 0) tt = tv[n][re][0].se;
		else
		{
			re = tv[n][re][1].fi;
			tt = 0;
		}
		n--;
	}
	reverse(ALL(ldk));
	for (auto v : ldk) cout << (char)('A' + v);
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("letters.inp","r",stdin); freopen("letters.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
