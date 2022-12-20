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

int n, cnt = 0, cmt = 0, mn[55], cw[55], c[55], w[55], dem[55], a[55], b[55];
long long dp[55][55], res = 0;
bool kt[55];

void sol()
{
	int dem_ = 0;
	for (int i = 0; i < cnt; i++)
	{
		mn[i] = cw[i] = 0;
		for (int j = a[i] + 1; j < a[i+1]; j++)
		{
			dem_ += w[c[j]]; cw[i] += w[c[j]];
			mn[i] = min(mn[i], cw[i]);
			if (dem_ + i < 0) return;
		}
	}
	//cout << "hello" << endl;
	for (int i = 0; i < cnt; i++) for (int j = 0; j <= min(a[i], n - a[i]); j++) dp[i][j] = 0;

	dp[0][0] = 1;
	
	for (int i = 0; i < cnt; i++)
	{
		int lim = min(a[i], n - a[i]);
		//cout << cw[i] << endl;
		for (int j = lim; j + mn[i] >= 0; j--)
		{
			//cout << a[i] << " " << j << " " << dp[i][j] << endl;
			if (j + cw[i] - 1 >= 0) dp[i+1][j + cw[i] - 1] = (dp[i+1][j + cw[i] - 1] + dp[i][j]);
			dp[i+1][j + cw[i] + 1] = (dp[i+1][j + cw[i] + 1] + dp[i][j]); 
		}
	}
	//cout << cw[cnt - 1] << " " << mn[cnt-1] << endl;
	if (a[cnt-1] == n) res = (res + dp[cnt-1][0]);
	else if (cw[cnt-1] <= 0)
	{
		if (-cw[cnt-1] + mn[cnt-1] < 0) return;
		res = (res + dp[cnt-1][-cw[cnt-1]]);
	}
}

int cnt_open = 0, cnt_close = 0;

void back_track(int id)
{
	if (id == cmt + 1)
	{
		sol();
		return;
	}
	if (dem[b[id]] + cnt_open <= n/2)
	{
		cnt_open += dem[b[id]];
		w[b[id]] = 1;
		back_track(id+1);
		cnt_open -= dem[b[id]];
	}
	if (dem[b[id]] + cnt_close <= n/2)
	{
		cnt_close += dem[b[id]];
		w[b[id]] = -1;
		back_track(id+1);
		cnt_close -= dem[b[id]];
	}
}

void solve() 
{	
	int x = 0;
	n = 0;
	while(cin >> x)
	{
		c[++n] = x; x = 0;
		dem[c[n]]++;
	}
	//cout << n << endl;
	
	for (int i = 1; i <= n; i++)
	if (dem[c[i]]  == 1)
	{
		a[++cnt] = i;
	}
	else
	{
		if (kt[c[i]] == false)
		{
			kt[c[i]] = true;
			b[++cmt] = c[i];
		}
	}
	//cout << a[cnt] << endl;
	a[++cnt] = n + 1;
	back_track(1);
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
    //freopen("parentheses.inp","r",stdin); freopen("parentheses.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
