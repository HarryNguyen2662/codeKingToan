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

struct DATA
{
	int lx, uy, aa, bb;
};

int gx[4] = {0, 0, -1, 1};
int gy[4] = {1, -1, 0, 0};

DATA iq[10000003];
int f[1005], cs[1005];
int re[1005][1005];
int s[1005][1005];
bool ok[1001][1001][3][3];

bool cango(int x, int y, int a, int b)
{
	return (s[x + a - 1][y + b - 1] - s[x - 1][y + b - 1] - s[x + a - 1][y - 1] + s[x - 1][y - 1] == 0);
}


void solve() 
{
	int a, b, c, n, m, k, x, y;
	cin >> a >> b >> c >> n >> m >> k;
	int sum = a + b + c;

	f[a] = f[b] = f[c] = -1;
	int tet = 0;
	if (f[a] == -1)
	{
		f[a] = tet;
		cs[tet] = a;
		tet++;
	}
		
	if (f[b] == -1)
	{
		f[b] = tet;
		cs[tet] = b;
		tet++;
	}
	if (f[c] == -1)
	{
		f[c] = tet;
		cs[tet] = c;
		tet++;
	}	
	for (int i = 1; i <= k; i++)
	{
		int x, y;
		cin >> x >> y;
		s[x][y]++;
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
	{
		s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
	}



	ok[1][1][f[a]][f[b]] = true;
	int cnt = 0, cmt = 1;
	iq[++cnt] = {1, 1, f[a], f[b]};
	while(cmt <= cnt)
	{
		x = iq[cmt].lx;
		y = iq[cmt].uy;
		a = cs[iq[cmt].aa];
		b = cs[iq[cmt].bb];
		c = sum - a - b;
		cmt++;

		re[x][y]++; re[x + a][y + b]++; re[x][y + b]--; re[x + a][y]--;
		for (int i = 0; i < 4; i++)
		{
			int xx = x + gx[i], yy = y + gy[i];
			if (xx >= 1 && x <= n - a + 1 && yy >= 1 && yy <= m - b + 1 && cango(xx, yy, a, b) && ok[xx][yy][f[a]][f[b]] == 0)
			{
				ok[xx][yy][f[a]][f[b]] = true;
				iq[++cnt] = {xx, yy, f[a], f[b]};
			}
		}

		swap(b, c);
		int xx = x, yy = y - b;
		if (xx >= 1 && xx <= n - a + 1 && yy >= 1 && yy <= m - b + 1 && cango(xx, yy, a, b) && ok[xx][yy][f[a]][f[b]] == 0)
		{
			ok[xx][yy][f[a]][f[b]] = true;
			iq[++cnt] = {xx, yy, f[a], f[b]};
		}
		yy = y + c;
		if (xx >= 1 && xx <= n - a + 1 && yy >= 1 && yy <= m - b + 1 && cango(xx, yy, a, b) && ok[xx][yy][f[a]][f[b]] == 0)
		{
			ok[xx][yy][f[a]][f[b]] = true;
			iq[++cnt] = {xx, yy, f[a], f[b]};
		}
		swap(b, c);

		swap(a, c);
		xx = x - a; yy = y;
		if (xx >= 1 && xx <= n - a + 1 && yy >= 1 && yy <= m - b + 1 && cango(xx, yy, a, b) && ok[xx][yy][f[a]][f[b]] == 0)
		{
			ok[xx][yy][f[a]][f[b]] = true;
			iq[++cnt] = {xx, yy, f[a], f[b]};
		}
		xx = x + c;
		if (xx >= 1 && xx <= n - a + 1 && yy >= 1 && yy <= m - b + 1 && cango(xx, yy, a, b) && ok[xx][yy][f[a]][f[b]] == 0)
		{
			ok[xx][yy][f[a]][f[b]] = true;
			iq[++cnt] = {xx, yy, f[a], f[b]};
		}
		swap(a, c);

	}
	int res = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
	{
		re[i][j] += re[i-1][j] + re[i][j-1] - re[i-1][j-1];
		res += (re[i][j] > 0);
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
    //freopen("blgame.inp","r",stdin); freopen("blgame.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
