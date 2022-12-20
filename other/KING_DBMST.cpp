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
struct edge
{
	int ver1, ver2, wei;
};
edge ed[30];
int qa = 1;
int dem = 0;
int high[20];
vector<int> a[20];
bool block[30];
void dfs(int u)
{
	dem++;
	if (high[u] > high[qa]) qa = u;
	for (auto v : a[u])
	if (block[v])
	{
		int vv = (u^ed[v].ver1^ed[v].ver2);
		if (high[vv] == 0) high[vv] = high[u] + 1, dfs(vv);
	}
}
void solve() 
{
	int n, m, k;
	cin >> n >> m >> k;
	k++;
	for (int i = 1; i <= m; i++)
	{
		cin >> ed[i].ver1 >> ed[i].ver2 >> ed[i].wei;
		a[ed[i].ver1].pb(i);
		a[ed[i].ver2].pb(i);
	}
	if (n > m)
	{
		cout << -1;
		return;
	}
	int res = oo;
	for (int i = mask(n)-1; i < mask(m); i++)
	if (getbit(i) == n - 1)
	{
		int re = 0;
		qa = 1;
		for (int j = 0; j < m; j++)
		{
			block[j+1] = ck(i, j);
			if (block[j+1])
			{
				re += ed[j+1].wei;
			}
		}
		if (re > res) continue;
		//cout << re <<endl;
		for (int j = 1; j <= n; j++) high[j] = 0;
		high[qa] = 1; dem = 0;
		dfs(qa);
		//if (high[qa] <= 3) cout << qa << endl;
		if (dem == n && high[qa] <= k)
		{
			//cout << re << endl;
			for (int j = 1; j <= n; j++) high[j] = 0;
			high[qa] = 1;
			dfs(qa);
			if (high[qa] <= k)
			{
			//	cout << i << " " << re << endl;
				res = min(res, re);
			}
			//cout << "alo\n";
		}
	}

	cout << (res == oo ? -1 : res);
}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
