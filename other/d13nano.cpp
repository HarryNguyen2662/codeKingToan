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

const long double pi = 3.14159265358979323846264338327950288419716939;
long double dthtron = (long double)1/4*pi;
long double dtgoc = (long double)(1 - dthtron)/4;
vector<pair<int, int>> luu;
vector<int> diff, ldk[1005];
pair<int,int> a[1005];
int xx[5][5]; 
int yy[5][5];
int sl[5] = {4, 2, 2, 2, 2};
int mnx, mny, mxx, mxy;
bool dd[1005][1005], vit[505][505][5], spec[1005][1005];
struct DATA
{
	int vx, vy, te;
} iq[1000005];

void dfs(int x, int y)
{
	luu.pb({diff[x], ldk[x][y]});
	mnx = min(mnx, diff[x]); mny = min(mny, ldk[x][y]);
	mxx = max(mxx, diff[x]); mxy = max(mxy, ldk[x][y]);
	dd[x][y] = true;

	if (y > 0 && ldk[x][y] == ldk[x][y-1] + 1 && dd[x][y-1] == false)
	{
		dfs(x, y-1);
	}

	if (y + 1 < (int)ldk[x].size() && ldk[x][y + 1] == ldk[x][y] + 1 && dd[x][y+1] == false)
	{
		dfs(x, y+1);
	}

	if (x > 0 && diff[x] == diff[x-1] + 1)
	{
		int id = lower_bound(ALL(ldk[x-1]), ldk[x][y]) - ldk[x-1].begin();
		if (id < (int)ldk[x-1].size() && ldk[x-1][id] == ldk[x][y] && dd[x-1][id] == false)
		{
			dfs(x - 1, id);
		}
	}

	if (x + 1 < (int)diff.size() && diff[x + 1] == diff[x] + 1)
	{
		int id = lower_bound(ALL(ldk[x+1]), ldk[x][y]) - ldk[x+1].begin();
		if (id < (int)ldk[x+1].size() && ldk[x+1][id] == ldk[x][y] && dd[x+1][id] == false)
		{
			//cout << x << " " <<  ldk[x+1][id] << " " << ldk[x][y] << endl;
			dfs(x + 1, id);
		}
	}


}

void solve() 
{

	xx[0][0] = 0; xx[0][1] = 0; xx[0][2] = 1; xx[0][3] = -1;
	yy[0][0] = 1; yy[0][1] = -1; yy[0][2] = 0; yy[0][4] = 0;
	
	xx[1][0] = 0; xx[1][1] = -1; 
	yy[1][0] = -1; yy[1][1] = 0;
	
	xx[2][0] = 0; xx[2][1] = -1; 
	yy[2][0] = 1; yy[2][1] = 0;
	
	xx[3][0] = 0; xx[3][1] = 1; 
	yy[3][0] = 1; yy[3][1] = 0; 

	xx[4][0] = 0; xx[4][1] = 1;
	yy[4][0] = -1; yy[4][1] = 0; 
	int n;
	cin >> n ;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].fi >> a[i].se;
		diff.pb(a[i].fi);
	}

	sort(ALL(diff)); diff.resize(unique(ALL(diff)) - diff.begin());
	for (int i = 1; i <= n; i++)
	{
		a[i].fi = lower_bound(ALL(diff), a[i].fi) - diff.begin(); 
		ldk[a[i].fi].pb(a[i].se);
	}
	for (int i = 0; i < (int)diff.size(); i++)
	{
		sort(ALL(ldk[i])); ldk[i].resize(unique(ALL(ldk[i])) - ldk[i].begin());
	}
	for (int i = 1; i <= n; i++)
	{
		a[i].se = lower_bound(ALL(ldk[a[i].fi]), a[i].se) - ldk[a[i].fi].begin();
	}

	long double re = 0;
	int slgoc = 0;
	for (int ii = 1; ii <= n; ii++) 
	if (dd[a[ii].fi][a[ii].se] == false)
	{
		luu.clear();
		mnx = mny = oo; mxx = mxy = 0;
		dfs(a[ii].fi, a[ii].se);
		for (int j = 0; j <= mxx - mnx + 2; j++)
		for (int e = 0; e <= mxy - mny + 2; e++)
		{
			vit[j][e][0] = vit[j][e][1] = vit[j][e][2] = vit[j][e][3] = vit[j][e][4] = spec[j][e] = 0;
		}

		for (auto v : luu)
		{
			spec[v.fi - mnx + 1][v.se -  mny + 1] = true;
		}
		mxx = mxx - mnx + 2; mxy = mxy - mny + 2;

		re += (mxx+1)*(mxy+1);
//		cout << re << endl;

		vit[0][0][0] = true;
		int cnt = 1, cmt = 1;
		iq[cnt] = {0, 0, 0};
		while(cmt <= cnt)
		{
			int x = iq[cmt].vx;
			int y = iq[cmt].vy;
			int tt = iq[cmt].te;
			//cout << x << " " << y << " " << tt << endl;
			cmt++;
			if (tt == 0) re --; else slgoc++;

			for (int i = 0; i < sl[tt]; i++)
			{
				int nx = x + xx[tt][i], ny = y + yy[tt][i];
				if (nx < 0 || nx > mxx || ny < 0 || ny > mxy) continue;
				if (!spec[nx][ny] && vit[nx][ny][0] == false)
				{
					vit[nx][ny][0] = true;
					iq[++cnt] = {nx, ny, 0};
				}
				else if (spec[nx][ny])
				{
					if (x + 1 == nx)
					{
						if ((tt == 0 || tt == 4) && vit[nx][ny][1] == false)
						{
							 //cout << i << endl;
							// cout << "af " << x << " " << y << " " <<  tt << endl;
							// cout << "du " << nx << " " << ny << " " << yy[tt][i] << endl;
							vit[nx][ny][1] = true;
							iq[++cnt] = {nx, ny, 1};
						}
						if ((tt == 0 || tt == 3) && vit[nx][ny][2] == false)
						{
							vit[nx][ny][2] = true;
							iq[++cnt] = {nx, ny, 2};
						}
					} 
					if (x - 1 == nx)
					{
						if ((tt == 0 || tt == 2) && vit[nx][ny][3] == false)
						{
							vit[nx][ny][3] = true;
							iq[++cnt] = {nx, ny, 3};
						}
						if ((tt == 0 || tt == 1) && vit[nx][ny][4] == false)
						{
							//cout << "af " << x << " " << y << " " << tt << endl;
							vit[nx][ny][4] = true;
							iq[++cnt] = {nx, ny, 4};
						}
					}

					if (y - 1 == ny)
					{
						if ((tt == 0 || tt == 1) && vit[nx][ny][2] == false)
						{
							vit[nx][ny][2] = true;
							iq[++cnt] = {nx, ny, 2};
						}
						if ((tt == 0 || tt == 4) && vit[nx][ny][3] == false)
						{
							vit[nx][ny][3] = true;
							iq[++cnt] = {nx, ny, 3};
						}
					}

					if (y + 1 == ny)
					{
						if ((tt == 0 || tt == 2) && vit[nx][ny][1] == false)
						{
							
							vit[nx][ny][1] = true;
							iq[++cnt] = {nx, ny, 1};
						}
						if ((tt == 0 || tt == 3) && vit[nx][ny][4] == false)
						{
							
							vit[nx][ny][4] = true;
							iq[++cnt] = {nx, ny, 4};
						}
					}

				}
			}
		}

	}

	re -= (long double)n*dthtron + (long double)slgoc*dtgoc;
	cout << fixed << setp(5) << re;
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
