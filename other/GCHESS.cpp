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
struct DATA
{
	int ver1, ver2, status;
};
int xx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int yy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dist[1005][1005][2];
int n, m, k;
int xt, yt;
bool diduocnecauoi(int dich, int val)
{
	if (dich >= xt)
	{
		val -= (dich - xt);
		if (val < 0) return false;
		val %= (2*n - 2);
		if (dich == n)
		{
			return val%(2*dich - 2) == 0;
		}
		return val%(2*n - 2*dich) == 0;
	}
	else
	{
		val -= (n - dich + n - xt);
		if (val < 0) return false;
		val %= (2*n - 2);
		if (dich == 1)
		{
			return val%(2*n - 2*dich) == 0;
		}
		return val%(2*dich - 2) == 0;
	}
}
void solve() 
{

	cin >> n >> m >> k;
	cin >> xt >> yt;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) for (int t = 0; t < 2; t ++)
	dist[i][j][t] = oo;
	queue<DATA> inq;
	for (int i = 1; i <= k; i++)
	{
		int x, y;
		cin >> x >> y;
		inq.push({x, y, 0}); 
	}
	while(!inq.empty())
	{
		int  x = inq.front().ver1, y = inq.front().ver2, t = inq.front().status;
		//cout << x << " " << y << " " << t << endl;
		inq.pop();
		for (int i = 0 ; i < 8; i ++)
		{
			int nx = x + xx[i], ny = y + yy[i];

			if (nx < 1 || nx > n || ny < 1 || ny > m || dist[nx][ny][1-t] != oo) continue;
			dist[nx][ny][1-t] = ((dist[x][y][t] == oo) ? 0 : dist[x][y][t]) + 1;
			inq.push({nx, ny, 1-t});
		}
	}
	//cout << n << endl;
	int res = oo;
	if (k == 1)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 4000; j++)
				if (diduocnecauoi(i, j) && dist[i][yt][abs(i-xt)%2] <=j)
				{
					res = min(res, j);
				}
	}
	else
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 4000; j++)
			if (diduocnecauoi(i, j) && (dist[i][yt][abs(i-xt)%2] <=j || dist[i][yt][1 - abs(i-xt)%2] + 1 <=j))
			{
				res = min(res, j);
			}
	}
	if (res == oo)
	{
		cout << -1;
		return;
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
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
