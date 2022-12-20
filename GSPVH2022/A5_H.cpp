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

bool f[31][7][7][7][7][7][7], cango[33][16][16];
int s[35][35], aa[4], vc[3], vt[3];
int gx[4] = {0, 0, -1, 1};
int gy[4] = {1, -1, 0, 0};

int get(int x, int y, int u, int v)
{
	return s[u][v] - s[x-1][v] - s[u][y-1] + s[x-1][y-1];
}

void solve() 
{

    memset(f, 0, sizeof(f));
	int n, m, k, a, b, x, y, d;
	cin >> n >> m >> k;
	cin >> a >> b >> x >> y >> d;

	int nn;
	cin >> nn;
	for (int i = 1; i <= nn; i++)
	{
		for (int j = 1; j <= n; j++)
			for (int e = 1; e <= m; e++)
			{
				cin >> s[j][e];
				s[j][e] += s[j-1][e] + s[j][e-1] - s[j-1][e-1];
			}
		
		for (int j = 1; j <= n - a + 1; j++)
			for (int e = 1; e <= m - b + 1; e++)
				cango[i][j][e] =  1 - (get(j, e, j + a - 1, e + b - 1) > 0);
	}

	vt[0] = 1; vc[0] = 1; vt[1] = n - a + 1; vc[1] = m - b + 1;
	aa[0] = aa[1] = aa[2] = aa[3] = 1;
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) 
	if (x == vt[i] && y == vc[j])
	{
		aa[i*2 + j] = 0;
	}

	if (aa[0] > k || aa[1] > k || aa[2] > k || aa[3] > k || !cango[1][x][y])
	{
		cout << 0;
		return;
	}
	else
	{
		f[1][x][y][aa[0]][aa[1]][aa[2]][aa[3]] = true;
	}

	if (nn == 1)
	{
		cout << 1;
		return;
	}

	for (int i = 1; i < nn; i++)
	for (int j = 1; j <= n - a + 1; j++)
	for (int e = 1; e <= m - b + 1; e++)
	for (int w = 0; w <= k; w++)
	for (int ww = 0; ww <= k; ww++)
	for (int www = 0; www <= k; www++)
	for (int wwww = 0; wwww <= k; wwww++)
	if (f[i][j][e][w][ww][www][wwww])
	{
		for (int ss = 0; ss < 4; ss++) for (int qq = 0; qq <= d; qq++)
		{
			int nx = j + gx[ss]*qq, ny = e + gy[ss]*qq;
			if (nx >= 1 && nx <= n - a + 1 && ny >= 1 && ny <= m - b + 1 && cango[i+1][nx][ny])
			{
				aa[0] = w + 1; aa[1] = ww + 1; aa[2] = www + 1; aa[3] = wwww + 1;
				for (int adu = 0; adu < 2; adu ++) for (int vl = 0; vl < 2; vl++)
				if (nx == vt[adu] && ny == vc[vl])
				{
					aa[adu*2 + vl] = 0;
				}

				if (aa[0] > k || aa[1] > k || aa[2] > k || aa[3] > k)
				continue;

				f[i+1][nx][ny][aa[0]][aa[1]][aa[2]][aa[3]] = true;
				if (i + 1 == nn) 
				{
					cout << 1;
					return;
				}
			} 
		}
	}
	cout << 0;
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("skwthr.inp","r",stdin); freopen("skwthr.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
