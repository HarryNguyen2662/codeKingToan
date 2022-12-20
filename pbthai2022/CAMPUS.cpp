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

int xx[4] = {-1, 1, 0, 0};
int yy[4] = {0, 0, -1, 1};

bool visit[1005][1005];
char s[1005][1005];
int u, v;
int n, m;

void dfs(int x, int y)
{
	visit[x][y] = true;
	if ((x + y)%2 == (u + v)%2)
	{
		s[x][y] = 'B';
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + xx[i], ny = y + yy[i];
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visit[nx][ny] && s[nx][ny] == 'F')
		{
			dfs(nx, ny);
		}
	}
}

void solve() 
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	{
		cin >> s[i][j];
	}

	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (s[i][j] == 'F' && !visit[i][j])
	{
		u = i; v = j;
		dfs(i, j);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) cout << s[i][j];
		cout << "\n";
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
