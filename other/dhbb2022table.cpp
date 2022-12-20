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

int n, m, q;
long long fen[4][505][505];

void upd(int x, int y, long long val)
{

	long long val1 = 1ll*x*val, val2 = 1ll*y*val, val3 = 1ll*x*y*val;
	for (; x <= n; x += (x&(-x)))
		for (int i = y; i <= m; i += (i&(-i)))
		{
			fen[0][x][i] += val;
			fen[1][x][i] += val1;
			fen[2][x][i] += val2;
			fen[3][x][i] += val3;
		}
}

long long sum(int x, int y)
{
	long long cs = 1ll*(x + 1)*(y + 1), cs1 = y + 1, cs2 = x + 1;
	long long su = 0;
	for (; x; x -= (x&(-x)))
		for (int i = y; i; i -= (i&(-i))) 
			su += cs*fen[0][x][i] - cs1*fen[1][x][i] - cs2*fen[2][x][i] + fen[3][x][i];

	return su;
}

void update(int x, int y, int u, int v, long long val)
{
	upd(x, y, val); upd(u + 1, v + 1, val);
	upd(x, v + 1, -val); upd(u + 1, y, -val);
}

long long getsum(int x, int y, int u, int v)
{
	return sum(u, v) - sum(x - 1, v) - sum(u, y - 1) + sum(x - 1, y - 1);
}

void solve() 
{	
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	{
		long long x;
		cin >> x;
		update(i, j, i, j, x);
	}


	while(q--)
	{
		int ti;
		cin >> ti;
		if (ti == 1)
		{
			int x, y, u, v; long long val;
			cin >> x >> y >> u >> v >> val;
			update(x, y, u, v, val);
		}
		else
		{
			int x, y, u, v;
			cin >> x >> y >> u >> v;
			cout << getsum(x, y, u, v) << "\n";
		}
	}
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
