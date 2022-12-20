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
int readInt () {
	int result = 0;
	char ch;
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	return result;
}
pair<pair<int,int>, pair<int,int>> lu, luu;
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
char id[4] = {'R', 'L', 'D', 'U'};
int row[1005][1005], col[1005][1005];
int dd[1005][1005], ddd[1005][1005][2];
char s[10005][10005];
void go(int x, int y, int u, int v)
{
	if (x < u)
	{
		for (int i = x; i <= u - 1; i++) cout << 'D';
	}
	else
	{
		for (int i = u; i <= x - 1; i++) cout << 'U';
	}
	if (y < v)
	{
		for (int i = y; i <= v - 1; i++) cout << 'R';
	}
	else
	{
		for (int i = v; i <= y - 1; i++) cout << 'L';
	}
}

void solve() 
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
	{
		cin >> s[i][j];
		row[i][j] = row[i-1][j];
		col[i][j] = col[i][j-1];
		if (s[i][j] == 'W') 
		{
			row[i][j]++; col[i][j]++;
		}
		else
		{
			row[i][j]--; col[i][j]--;
		}
		if (i > 1)
		{
			if (s[i][j] == s[i-1][j])
			{
				if (s[i][j] == 'W')
				{
					lu = {{i-1, j}, {i, j}};
				}
				else
				{
					luu = {{i-1, j}, {i, j}};
				}
			}
		}
		if (j > 1)
		{
			if (s[i][j] == s[i][j-1])
			{
				if (s[i][j] == 'W')
				{
					lu = {{i, j-1}, {i, j}};
				}
				else
				{
					luu = {{i, j-1}, {i, j}};
				}
			}
		}
	}
	// cout << lu.fi.fi << " " << lu.fi.se << endl;
	// cout << luu.se.fi << " " << luu.se.se << endl;
	int q;
	int www = abs(lu.se.fi - luu.fi.fi) + abs(lu.se.se - luu.fi.se) + 1;
	cin >> q;
	while(q--)
	{

		int x, y, u ,v;
		cin >> x >> y >> u >> v;
		if ((abs(u - x) + abs(v - y) + 1)%2)
		{
			cout << "-1\n";
			continue;
		}

		if (lu.fi.fi != 0 && luu.fi.fi != 0)
		{
			int cl = max(lu.fi.fi, x), cc = min(lu.fi.fi, x);
			int ww = row[cl][y] - row[cc-1][y];
			
			cl = max(lu.fi.se, y), cc = min(lu.fi.se, y);
			
			ww += col[lu.fi.fi][cl] - col[lu.fi.fi][cc-1];
			ww -= (s[lu.fi.fi][y] == 'W' ? 1 : -1);
			//cout <<cl << " " << lu.fi.fi << endl;
			cl = max(lu.se.fi, luu.fi.fi), cc = min(lu.se.fi, luu.fi.fi);
			//cout << cl << " " << cc << endl;
			ww += row[cl][lu.se.se] - row[cc-1][lu.se.se];
			
			cl = max(lu.se.se, luu.fi.se), cc = min(lu.se.se, luu.fi.se);
			ww += col[luu.fi.fi][cl] - col[luu.fi.fi][cc-1];
			ww -= (s[luu.fi.fi][lu.se.se] == 'W'  ? 1 : -1);	

			cl = max(luu.se.fi, u), cc = min(luu.se.fi, u);
			ww += row[cl][luu.se.se] - row[cc-1][luu.se.se];
			
			cl = max(luu.se.se, v), cc = min(luu.se.se, v);
			ww += col[u][cl] - col[u][cc-1];
			ww -= (s[u][luu.se.se] == 'W' ? 1 : -1);
			cout << abs(lu.fi.fi - x) + abs(lu.fi.se - y) + 1 + www + abs(luu.se.fi - u) + abs(luu.se.se - v) + 1 + abs(ww) << " ";
			go(x, y, lu.fi.fi, lu.fi.se);
			go(lu.fi.fi, lu.fi.se, lu.se.fi, lu.se.se);
			if (ww < 0)
			{
				for (int i = 1; i <= abs(ww)/2; i++) 
				{
					go(lu.se.fi, lu.se.se, lu.fi.fi, lu.fi.se);
					go(lu.fi.fi, lu.fi.se, lu.se.fi, lu.se.se);
				}
				ww = 0;
			}
			go(lu.se.fi, lu.se.se, luu.fi.fi, luu.fi.se);
			go(luu.fi.fi, luu.fi.se, luu.se.fi, luu.se.se);
			if (ww > 0)
			{
				for (int i = 1; i <= ww/2; i++) 
				{
					go(luu.se.fi, luu.se.se, luu.fi.fi, luu.fi.se);
					go(luu.fi.fi, luu.fi.se, luu.se.fi, luu.se.se);
				}
				ww = 0;
			}
			go(luu.se.fi, luu.se.se, u, v);
			cout << "\n";
			continue;
		}
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		{
			dd[i][j] = ddd[i][j][0] = ddd[i][j][1] = -1;
		}
		dd[x][y] = -2;
		queue<pair<int,int>> iq;
		iq.push({x, y});
		while(!iq.empty())
		{
			int uu = iq.front().fi, vv = iq.front().se; iq.pop();
			for (int i = 0; i < 4; i++)
			{
				int nu = uu + xx[i], nv = vv + yy[i];
				if (nu >= 1 && nu <= n && nv >= 1 && nv <= m && dd[nu][nv] == -1 && s[nu][nv] != s[uu][vv])
				{
					dd[nu][nv] = i;
					iq.push({nu, nv});
				}
			}
		}

		if (dd[u][v] != -1)
		{
			vector<char> res;
			int uu = u, vv = v;
			while(dd[uu][vv] != -2)
			{
				res.pb(id[dd[uu][vv]]);
				int w = dd[uu][vv];
				uu -= xx[w]; vv -= yy[w];
			}
			cout << (int)res.size() + 1 << " ";
			reverse(ALL(res));
			for (auto v : res) cout << v;
			cout << "\n";
			continue;
		}
		if ((s[x][y] != s[u][v])||(s[x][y] == 'W' && luu.fi.fi == 0 ) || (s[x][y] == 'B' && lu.fi.fi == 0))
		{
			cout << "-1\n";
			continue;
		} 
		queue<pair<pair<int,int>, int>>  iqq;
		ddd[x][y][0] = -2;
		iqq.push({{x, y}, 0});
		while(!iqq.empty())
		{
			int uu = iqq.front().fi.fi, vv = iqq.front().fi.se;
			int tt = iqq.front().se; iqq.pop();
			for (int i = 0; i < 4; i++)
			{
				int nu = uu + xx[i], nv = vv + yy[i];
				if (nu >= 1 && nu <= n && nv >= 1 && nv <= m)
				{
					if (ddd[nu][nv][tt] == -1 && s[nu][nv] != s[uu][vv])
					{
						ddd[nu][nv][tt] = i;
						iqq.push({{nu, nv}, tt});
					}
					if (tt == 0 && ddd[nu][nv][1] == -1 && s[nu][nv] == s[uu][vv] && s[uu][vv] != s[x][y])
					{
						ddd[nu][nv][1] = i;
						iqq.push({{nu, nv}, 1});
					}
				}
			}
		}
		if (ddd[u][v][1] != -1)
		{
			vector<char> res;
			int uu = u, vv = v;
			int tt = 1;
			while(ddd[uu][vv][tt] != -2)
			{
				res.pb(id[ddd[uu][vv][tt]]);
				int w = ddd[uu][vv][tt];
				if (s[uu][vv] == s[uu - xx[w]][vv - yy[w]]) tt = 0;
				uu -= xx[w]; vv -= yy[w];
			}
			cout << (int)res.size() + 1 << " ";
			reverse(ALL(res));
			for (auto v : res) cout << v;
			cout << "\n";
			continue;
		}
		cout << "-1\n";

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
