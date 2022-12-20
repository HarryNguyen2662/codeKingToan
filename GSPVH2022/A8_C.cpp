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
char s[55][55], du[55][55];
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};

void dfs(int x, int y, char vu)
{
	du[x][y] = vu;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + xx[i], ny = y + yy[i];
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && du[nx][ny] == '@' && s[nx][ny] != 'X') 
		dfs(nx, ny, vu);
	}
}


void solve() 
{
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> s[i][j];
			du[i][j] = '@';
		}

	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (du[i][j] == '@' && s[i][j] <= '9' && s[i][j] >= '0')
	dfs(i, j, s[i][j]);

	bool kt = false;
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		if (du[x][y] != '@') 
		{
			kt = true;
			cout << du[x][y];
		}
	}
	if (!kt) cout << "Empty";
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("keyboard.inp","r",stdin); freopen("keyboard.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
