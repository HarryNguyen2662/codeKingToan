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

int gx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int gy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

char s[55][55];

void solve() 
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	{
		cin >> s[i][j];
	}

	int res = 0, mx = 0;

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	if (s[i][j] == 'o')
	{
		for (int e = 0; e < 4; e++)
		if (i + gx[e] >= 1 && i + gx[e] <= n && j + gy[e] >= 1 && j + gy[e] <= m && s[i + gx[e]][j + gy[e]] == 'o')
		{
			res++;
		}
	}
	else
	{
		int re = 0;
		for (int e = 0; e < 8; e++)
		if (i + gx[e] >= 1 && i + gx[e] <= n && j + gy[e] >= 1 && j + gy[e] <= m && s[i + gx[e]][j + gy[e]] == 'o')
		{
			re++;
		}
		mx = max(mx, re);
	}

	cout << res + mx;

}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("misa.inp","r",stdin); freopen("misa.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
