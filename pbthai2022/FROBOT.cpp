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
const long long oo15 = 1e18, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int gx[4][2] = {{0, 1}, {1, 1}, {0, -1}, {-1, -1}};
int gy[4][2] = {{1, 1}, {0, -1}, {-1, -1}, {0, 1}}; 
char s[105][105];
int trace[105][105][4];

long long dist[105][105][4];

struct DATA
{
	long long dai; int verx, very, status;

	bool operator < (const DATA &other) const
	{
		return dai > other.dai;
	}
};

void solve() 
{		

	int n, m, x, y, z, t; long long k[2]; long long turnright, turnleft;
	cin >> n >> m >> x >> y >> z >> t >> k[0] >> k[1] >> turnright >> turnleft;

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	{
		cin >> s[i][j];
		for (int e = 0; e < 4; e++) dist[i][j][e] = oo15;
	}

	dist[x][y][0] = 0;

	priority_queue<DATA> pq;
	pq.push({0, x, y, 0});

	while(!pq.empty())
	{
		long long len = pq.top().dai;
		x = pq.top().verx; y = pq.top().very; int tt = pq.top().status; pq.pop();
		//cout << len << " " << x << " " << y << " " << tt << endl;
		if (len != dist[x][y][tt]) continue;

		int ntt = (tt + 1)%4; 
		if (dist[x][y][ntt] > len + turnright)
		{
			trace[x][y][ntt] = 3;
			dist[x][y][ntt] = len + turnright;
			pq.push({dist[x][y][ntt], x, y, ntt});
		}

		ntt = (tt + 3)%4;
		if (dist[x][y][ntt] > len + turnleft)
		{
			trace[x][y][ntt] = 4;
			dist[x][y][ntt] = len + turnleft;
			pq.push({dist[x][y][ntt], x, y, ntt});
		}

		for (int i = 0; i < 2; i++)
		{
			int nx = x + gx[tt][i], ny = y + gy[tt][i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && s[nx][ny] == '0' && dist[nx][ny][tt] > len + k[i])
			{
				trace[nx][ny][tt] = i + 1;
				dist[nx][ny][tt] = len + k[i];
				pq.push({dist[nx][ny][tt], nx, ny, tt});
			}
		}
	}
	long long res = oo15; int tt = 0;
	for (int i = 0; i < 4; i++) if (dist[z][t][i] < res)
	{
		res = dist[z][t][i]; tt = i;
	}

	if (res == oo15)
	{
		cout << "-1"; return;
	}

	cout << res << "\n";

	vector<int> cs;

	while(trace[z][t][tt])
	{
		int w = trace[z][t][tt];
		cs.pb(w);
		if (w <= 2)
		{
			w--;
			z -= gx[tt][w]; t -= gy[tt][w];
		}
		else if (w == 3)
		{
			tt = (tt + 3)%4;
		}
		else
		{
			tt = (tt + 1)%4;
		}
	}

	reverse(ALL(cs)); cout << (int)cs.size() << "\n";
	for (auto v : cs) cout << v << " ";

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
