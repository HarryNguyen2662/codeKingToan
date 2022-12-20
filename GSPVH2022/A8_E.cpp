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

vector<int> ldk[1000005];
int n, m, dem = 0, divi[10000005];
bool vit[1000005][12];
int a[1000005];
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
const int lim = 10000000;

void dfs(int x, int y, int val)
{
	dem++; 
	for (int i = 0; i < 4; i++)
	{
		int nx = x + xx[i], ny = y + yy[i];

		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[(nx - 1)*m + ny]%val == 0)
		{
			int id = lower_bound(ALL(ldk[(nx - 1)*m + ny]), val) - ldk[(nx - 1)*m + ny].begin();
			if (vit[(nx - 1)*m + ny][id] == true) continue;
			vit[(nx - 1)*m + ny][id] = true;
			dfs(nx, ny, val);
		}
	}
}

void solve() 
{
	cin >> n >> n >> m;

	for (int i = 1; i <= lim; i++) divi[i] = i;

	for (int i = 2; i <= lim; i++) if (divi[i] == i)
		for (int j = 2*i; j <= lim; j += i) divi[j] = i;

	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= m; j++) 
		{
			cin >> a[(i - 1)*m + j];
			int val = a[(i - 1)*m + j];
			while(val > 1)
			{
				if (!(int)ldk[(i - 1)*m + j].size() || ldk[(i - 1)*m + j].back() != divi[val]) ldk[(i - 1)*m + j].pb(divi[val]);
				val /= divi[val];
			}
			reverse(ALL(ldk[(i - 1)*m + j]));
		}
	}

	int res = 0;

	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
	for (int e = 0; e < (int)ldk[(i - 1)*m + j].size(); e++)
	if (vit[(i - 1)*m + j][e] ==  false)
	{
		dem = 0;
		vit[(i - 1)*m + j][e] =  true;
		dfs(i, j, ldk[(i - 1)*m + j][e]);
		res = max(res, dem);
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
    //freopen("numtable.inp","r",stdin); freopen("numtable.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
