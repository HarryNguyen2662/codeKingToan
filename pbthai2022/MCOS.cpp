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

int a[100], dp[72][524290];

void solve() 
{

	vector<int> prime;

	auto check = [&](const int &x)
	{
		for (int i = 2; i*i <= x; i++) if (x%i == 0) return false;

		return true;
	};

	for (int i = 2; i <= 70; i++)
		if (check(i)) prime.pb(i);


	int res = 0;
	int re = 0;
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x == 1) res++;
		else 
		{
			cnt++;
			for (int j = 2; j*j <= x; j++)
			if (x%j == 0)
			{
				a[cnt] += mask(lower_bound(ALL(prime), j) - prime.begin());
				while(x%j == 0) x/=j;
			}
			if (x > 1) a[cnt] += mask(lower_bound(ALL(prime), x) - prime.begin());
		}
	}

	n = cnt;

	for (int i = 1; i <= n; i++)
	for (int j = 0; j < mask((int)prime.size()); j++)
	{
		dp[i][j] = max(dp[i-1][j], dp[i][j]);
		if ((j&a[i]) == a[i])
		dp[i][j] = max(dp[i-1][j^a[i]] + 1, dp[i][j]);
		re = max(re, dp[i][j]);
	}

	cout << re + res;
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
