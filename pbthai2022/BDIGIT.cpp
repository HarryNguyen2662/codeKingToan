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
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll add;
bool dd[20];
ll dp[11][2050][12][2];
bool ok[2050];
int n, k, len;
ll l, r;
vector<int> s;

void change(ll val)
{
	s.clear();

	while(val)
	{
		s.pb(val%10);
		val /= 10;
	}

	reverse(ALL(s)); len = (int)s.size();
}

void f(int d, int msk, int dif, bool ti, int id, int cnt)
{
	if (id == len)
	{
		// cout << d << " " << msk << " " << dif << " " << ti << " " << id << " " << cnt << endl;
		if (dd[cnt])
		{
			dp[d][msk][dif][ti] += add;
		}
		return;
	}

	if (ck(msk, id))
	{
		f(d, msk, dif, ti, id + 1, cnt);
		return;
	}

	f(d, msk, dif, ti, id + 1, cnt);
	
	if (d != 0 || msk%mask(id))
	{
		if ((dif == 0 || id + 1 < dif) && s[id] != d)
			f(d, msk^mask(id), id + 1, (d > s[id]), min(id + k, len), cnt + 1);
		else
			f(d, msk^mask(id), dif, ti, min(id + k, len), cnt + 1);
	}
}

void solve() 
{
	cin >> n >> k >> l >> r;
	for (int i = 1; i <= n; i++)
	{
		int val;
		cin >> val;
		dd[val] = true;
	}
	dd[0] = true;

	for(int i = 1; i <= 11; i++) ok[mask(i) - 1] = true;

	change(r);
	dp[10][0][0][0] = 1;

	for(int digit = 9; digit >= 0; digit--)
	{
		for(int msk = 0; msk < mask(len); msk++)
		for (int i = 0; i <= len; i++)
		for (int e = 0; e < 2; e++)
		if (dp[digit + 1][msk][i][e])
		{
			add = dp[digit + 1][msk][i][e];
			f(digit, msk, i, e, 0, 0);
		}
	}

	ll ansr = 0;

	// cout << dp[2][0][0][0] << endl;

	for (int msk = 0; msk < mask(len); msk++)
	for (int i = 0; i <= len; i++)
	for (int e = 0; e < 2; e++)
	if (ok[msk] && dp[0][msk][i][e])
	{
		if (getbit(msk) < len) ansr += dp[0][msk][i][e];
		else if (!e) ansr += dp[0][msk][i][e];
	} 

	change(l - 1);


	for (int d = 0; d <= 9; d++)
	for(int msk = 0; msk < mask(len); msk++)
	for (int i = 0; i <= len; i++)
	for (int e = 0; e < 2; e++)
	dp[d][msk][i][e] = 0;
	

	for(int digit = 9; digit >= 0; digit--)
	{
		for(int msk = 0; msk < mask(len); msk++)
		for (int i = 0; i <= len; i++)
		for (int e = 0; e < 2; e++)
		if (dp[digit + 1][msk][i][e])
		{
			add = dp[digit + 1][msk][i][e];
			f(digit, msk, i, e, 0, 0);
		}
	}


	for (int msk = 0; msk < mask(len); msk++)
	for (int i = 0; i <= len; i++)
	for (int e = 0; e < 2; e++)
	if (ok[msk] && dp[0][msk][i][e])
	{
		if (getbit(msk) < len) ansr -= dp[0][msk][i][e];
		else if (!e) ansr -= dp[0][msk][i][e];
	} 

	cout << ansr;

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
