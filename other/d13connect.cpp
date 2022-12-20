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
int idx[4] = {0, 0, 1, -1};
int idy[4] = {1, -1, 0, 0};
queue<pair<pair<int,int>, int>> QA[9005];
queue<pair<int,int>> LDK[4505];
int n, m, f[505][505][4], le[505][505], ri[505][505], s[505][505];
bool check(int x, int y)
{
	if (x >= 1 && x <= n && y >= 1 && y <= m) return  true;
}
void cal(int k)
{
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) le[i][j] = ri[i][j] = oo;

	for (int i = 1; i <= n; i++) le[i][1] = abs(s[i][1] - k), LDK[le[i][1]].push({i, 1});
	int len = 0;
	while(true)
	{
		while(LDK[len].empty() && len < 4501) len++;
		if (len == 4501) break;
		int x, y;
		while(!LDK[len].empty())
		{
			x = LDK[len].front().fi;
			y = LDK[len].front().se;
			if (le[x][y] != len) LDK[len].pop();
			else break;
		}
		if (LDK[len].empty()) continue;
		LDK[len].pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + idx[i], ny = y + idy[i];
			if (!check(nx, ny)) continue;
			if (le[nx][ny] > le[x][y] + abs(s[nx][ny] - k))
			{
				le[nx][ny] = le[x][y] + abs(s[nx][ny] - k);
				LDK[le[nx][ny]].push({nx, ny});
			}
		}
	}
	len = 0;
	//cout << m << n << endl;
	for (int i = 1; i <= n; i++) ri[i][m] = abs(s[i][m] - k), LDK[ri[i][m]].push({i, m});
	//cout << LDK[0].empty() << endl;
	while(true)      
	{       
		//cout << len << endl;
		while(LDK[len].empty() && len < 4501) len++;
		if (len == 4501) 
		{
			 break;
		}
		//cout << len << endl;
		int x, y;
		while(!LDK[len].empty())
		{
			x = LDK[len].front().fi;
			y = LDK[len].front().se;
			if (ri[x][y] != len) LDK[len].pop();
			else break;
		}

		if (LDK[len].empty()) continue;
		LDK[len].pop();
		//cout << "do " << x << " " << y << endl;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + idx[i], ny = y + idy[i];
			if (!check(nx, ny)) continue;
			//cout << nx << " " << ny << endl;
			if (ri[nx][ny] > ri[x][y] + abs(s[nx][ny] - k))
			{
				ri[nx][ny] = ri[x][y] + abs(s[nx][ny] - k);
				LDK[ri[nx][ny]].push({nx, ny});
			}
		}
	}

}

void cal1(int k)
{
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
	for (int e = 0; e < 4; e++) f[i][j][e] = oo;

	for (int i = 1; i <= m; i++)
	{
		int e = 0;
		if (i == 1) e ^= mask(0);
		if (i == m) e ^= mask(1);
		f[1][i][e] = abs(s[1][i] - k);
		QA[f[1][i][e]].push({{1, i}, e});
	}
	//cout << f[1][2][0] << endl;
	int len = 0;
	while(true)
	{
		while(QA[len].empty() && len < 9001) len++;
		if (len == 9001) break;

		int x, y, e;
		while(!QA[len].empty())
		{
			x = QA[len].front().fi.fi;
			y = QA[len].front().fi.se;
			e = QA[len].front().se;
			if (f[x][y][e] != len) QA[len].pop();
			else break;
		}
		if (QA[len].empty()) continue;
		QA[len].pop();

		if (!ck(e, 0) && f[x][y][e^mask(0)] > f[x][y][e] + le[x][y] - abs(s[x][y] - k))
		{
			f[x][y][e^mask(0)] = f[x][y][e] + le[x][y] - abs(s[x][y] - k);
			QA[f[x][y][e^mask(0)]].push({{x, y}, e^mask(0)});
		}
		if (!ck(e, 1) && f[x][y][e^mask(1)] > f[x][y][e] + ri[x][y] - abs(s[x][y] - k))
		{
			f[x][y][e^mask(1)] = f[x][y][e] + ri[x][y] - abs(s[x][y] - k);
			QA[f[x][y][e^mask(1)]].push({{x, y}, e^mask(1)});
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + idx[i], ny = y + idy[i];
			if (!check(nx, ny)) continue;
			if (f[nx][ny][e] > f[x][y][e] + abs(s[nx][ny] - k))
			{
				f[nx][ny][e] = f[x][y][e] + abs(s[nx][ny] - k);
				QA[f[nx][ny][e]].push({{nx, ny}, e});
			}
			
		}
	}
}

void solve() 
{
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			char ktu;
			cin >> ktu;
			s[i][j] = ktu - '0';
			//cout << s[i][j] << endl;
		}

	int res = oo;

	for (int k = 0; k <= 9; k++)
	{
		cal(k); cal1(k);
		for (int i = 1; i <= m; i++) res = min(res, f[n][i][3]);
		//if (res == 2) cout << k << endl;
	}
	//cout << f[2][2][0] << endl;
	//cout << le[2][2] << " " << ri[2][2] << endl;
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
