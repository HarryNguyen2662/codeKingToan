#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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

struct POINT
{
	int x, y;

	bool operator < (const POINT &other) const
	{
		return x < other.x;
	}

	int operator * (const POINT &other)
	{
		return x*other.y - other.x*y;
	}

	POINT operator - (const POINT &other)
	{
		return {x - other.x, y - other.y};
	}
};

int CCW(POINT o, POINT A, POINT B)
{
	A = A - o; B = B - o;
	int re = A*B;

	if (re == 0) return 0; else if (re < 0) return -1; else return 1;
}

POINT c[55], p[55];
int dp[55][55][55][55], n;

bool check(int l, int r, int sl, int sr, int id)
{
	if (p[id].y > min(p[sl].y, p[sr].y)) return false;

	if (CCW(c[l], p[sl], c[r - 1]) == CCW(c[l], p[sl], p[id]) || 
		CCW(c[r - 1], p[id], c[l]) == CCW(c[r - 1], p[id], p[sl])) 
	{
		if (CCW(c[r], p[sr], c[l + 1]) == CCW(c[r], p[sr], p[id]) || 
			CCW(c[l + 1], p[id], c[r]) == CCW(c[l + 1], p[id], p[sr])) return true;
	
	}
	

	return false;

}

int f(int l, int r, int sl, int sr)
{
	if (r - l == 1) return 1;

	if (dp[l][r][sl][sr] != -1) return dp[l][r][sl][sr];

	int &res = dp[l][r][sl][sr]; res = 0;

	int ps = -1;

	for (int i = 1; i <= n; i++)
	if (i != sl && i != sr && check(l, r, sl, sr, i))
	{
		ps = i;
		break;
	}

	// cout << l << " " << r << " " << sl << " " << sr << " " << ps << endl;

	if (ps == -1) return res;

	for (int i = l + 1; i <= r - 1; i++) 
	{
		res += 1ll*f(l, i, sl, ps)*f(i, r, ps, sr)%MOD; res %= MOD;
	}

	return res;
}

void solve() 
{	
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> c[i].x; c[i].y = 0;
	}

	c[0].x = -1; c[0].y = 0; c[n + 1].x = 10005; c[n + 1].y = 0;

	sort(c + 1, c + 1 + n);

	for (int i = 1; i <= n; i++)
	{
		cin >> p[i].x >> p[i].y;
	}
	p[0].x = -1; p[0].y = 10005; p[n + 1].x = 10005; p[n + 1].y = 10005;

	sort(p + 1, p + 1 + n, [](const POINT &u, const POINT &v)
		{
			return u.y > v.y;
		});

	for (int i = 0; i <= n + 1; i ++)
	for (int j = 0; j <= n + 1; j ++)
	for (int ii = 0; ii <= n + 1; ii ++)
	for (int jj = 0; jj <= n + 1; jj ++)
	dp[i][j][ii][jj] = -1;

	cout << f(0, n + 1, 0, n + 1);
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
