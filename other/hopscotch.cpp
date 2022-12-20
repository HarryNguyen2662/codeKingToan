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

inline long long ReadInt() 
{
    char c;
    bool negative = false;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') negative = true;
    long long x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (negative) return -x; else return x;
}

void WriteInt(long long x) 
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
void add(int &x, const int &y)
{
	x += y;
	if (x >= MOD) x -= MOD;
}
struct BIT
{
	vector<int> fen;
	int lim;

	void build(int n)
	{
		fen.assign(n + 2, 0);
		lim = n;
	}
	void update(int id, int val)
	{
		for (; id <= lim; id += (id&(-id))) add(fen[id], val);
	}
	
	int get(int id)
	{
		int res = 0;
		for (; id; id -= (id&(-id))) add(res, fen[id]);
		return res;
	}
};
BIT LQA[562510];
vector<int> diffrow[562510];
int id[800], f[800], sudp[765][765], a[765][765];
void solve() 
{
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			diffrow[a[i][j]].pb(j);
		}
	for (int i = 1 ; i <= k; i++)
	if ((int)diffrow[i].size() > 0)
	{
		sort(ALL(diffrow[i])); diffrow[i].resize(unique(ALL(diffrow[i])) - diffrow[i].begin());
		LQA[i].build((int)diffrow[i].size());
	}
	for (int j = 1; j <= m; j++) sudp[1][j] = 1;
	LQA[a[1][1]].update(1, 1);
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			id[j] = lower_bound(ALL(diffrow[a[i][j]]), j) - diffrow[a[i][j]].begin() + 1;
			f[j] = sudp[i-1][j-1] - LQA[a[i][j]].get(id[j] - 1);
			if (f[j] < 0) f[j] += MOD; if (f[j] >= MOD) f[j] -= MOD;
		}
		for (int j = 1; j <= m; j++)
		{
			sudp[i][j] = ((sudp[i-1][j] + sudp[i][j-1])%MOD - sudp[i-1][j-1] + MOD)%MOD + f[j];
			sudp[i][j] %= MOD;
			if (f[j] > 0)
			LQA[a[i][j]].update(id[j], f[j]);
		}
	}
	cout << f[m];
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
