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

int s[1005][1005], dist[1005][1005];
bool go[1005][1005];
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
int n, m, a, b;

int get(int x, int y)
{
	return s[x + a - 1][y + b - 1] - s[x-1][y + b -1] - s[x + a -1][y -1] + s[x-1][y-1];
}

void solve() 
{
	int x, y, u, v;
	cin >> n >> m >> a >> b >> x >> y >> u >> v;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m ;j++) 
	{
		cin >> s[i][j];
		s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
	}
	n = n - a + 1; m = m - b + 1;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
	{
		dist[i][j] = -1;
		go[i][j] = (get(i, j) > 0);
	}
	if (go[x][y])
	{
		cout << "-1";
		return;
	}
	queue<pair<int,int>> iq;
	iq.push({x, y}); dist[x][y] = 0;
	while(!iq.empty())
	{
		x = iq.front().fi; y = iq.front().se; iq.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + xx[i], ny = y + yy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && dist[nx][ny] == -1 && !go[nx][ny])
			{
				dist[nx][ny] = dist[x][y] + 1;
				iq.push({nx, ny});
			}
		}
	}
	cout << dist[u][v];
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
