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

int dp[1005][50002], a[1005], su[1005];
void solve() 
{
	int n;
	int sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		su[i] = su[i-1] + a[i];
		sum += a[i];
	}
	sum/=2;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= sum; j++) dp[i][j] = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i][a[i]] = max(dp[i][a[i]], i);
		for (int j = 1; j <= min(sum, su[i]); j++)
		{
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
			if (j >= a[i]) dp[i][j] = max(dp[i][j], dp[i-1][j-a[i]]);
		}
	}
	//cout << dp[4][8] << endl;
	vector<int> ans;
	for (int i = 2; i <= n; i++)
	{
		bool kt = true;
		for (int j = 1; j <= n - i + 1; j++) if ((su[j + i - 1] - su[j-1])%2 
			|| dp[j+i-1][(su[j + i - 1] - su[j-1])/2] < j)
		{
			kt = false; break;
		}
		if (kt) ans.pb(i);
	}
	cout << (int)ans.size() << " ";
	for (auto v : ans) cout << v << " ";
	cout << "\n";
}

int main() 
{   
   	#ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
