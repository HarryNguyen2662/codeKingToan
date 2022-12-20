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

int xx[4] = {1, -1, 0, 0};
int yy[4] = {0, 0, -1, 1};

int W, H, vit[205][205], dd[205][205], res[205];
char s[205][205];
string se[40005];
vector<int> ldk[205], dk[205];
int n, cmt = 0, cnt, mxr, mnr, mxh;

bool cmp(const int &x, const int &y)
{
	return se[x] < se[y];
}


void dfs(int x, int y)
{
	vit[x][y] = cnt; mxr = max(mxr, y); mnr = min(mnr, y); mxh = max(mxh, x);

	for (int i = 0; i < 4; i++)
	{
		int nx = x + xx[i], ny = y + yy[i];

		if (1 <= nx && nx <= W && 1 <= ny && ny <= H && s[nx][ny] == 'X' && vit[nx][ny] == 0) dfs(nx, ny);
	}

}

void dfs1(int x, int y)
{
	vit[x][y] = cnt; mxr = max(mxr, y); mnr = min(mnr, y); mxh = max(mxh, x);

	for (int i = 0; i < 4; i++)
	{
		int nx = x + xx[i], ny = y + yy[i];

		if (1 <= nx && nx <= W && 1 <= ny && ny <= H && s[nx][ny] == 'X' && vit[nx][ny] != cnt) dfs1(nx, ny);
	}

}

void solve() 
{
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> W >> H;
		
		for (int h = 1; h <= W; h++)
		for (int r = 1; r <= H; r++)
		{
			cin >> s[h][r];
		}
		
		int h = 0;
		mxr = 0; mnr = oo; mxh = 0; 
		cnt++;

		for (int hh = 1; hh <= W; hh++)
		{
			for (int r = 1; r <= H; r++) if (s[hh][r] == 'X')
			{
				h = hh;
				dfs1(hh, r);
				break; 
			}
			if (h) break;	
		}
		
		//cout << h << " " << mxh << " " << mnr << " " << mxr << endl;
		int nW = mxh - h + 1, nH = mxr - mnr + 1;
		string se1 = "", se2 = "", se3 = "";

		if (nW <= nH)
		{
			int kt = 0;
			for (int e = h; e <= mxh; e++)
			for (int f = mnr; f <= mxr; f++)
			{
				se[cnt] += (vit[e][f] == cnt ? 'X' : '.');
				se1 += (vit[mxh - e + h][mxr - f + mnr]  == cnt ? 'X' : '.');
				if (kt == 0)
				{
					if (se[cnt].back() > se1.back()) kt = 1;
					else if (se[cnt].back() < se1.back()) kt = -1;
				}
			}
			if (kt == 1) swap(se1, se[cnt]);
		}

		if (nW >= nH)
		{
			int kt = 0;
			for (int f = mnr; f <= mxr; f++)
			for (int e = mxh; e >= h; e--)
			{
				se2 += (vit[e][f] == cnt ? 'X' : '.');
				se3 += (vit[mxh - e + h][mxr - f + mnr]  == cnt ? 'X' : '.');
				if (kt == 0)
				{
					if (se2.back() > se3.back()) kt = 1;
					else if (se2.back() < se3.back()) kt = -1;
				}
			}
			
			if (kt == 1) swap(se2, se3);
			
			if (nW == nH)
			{
				if (se2 > se[cnt]) swap(se2, se[cnt]);
			} else se[cnt] = se2;
			
			swap(nW, nH);
		}
			

		if (dd[nW][nH] == 0)
		{
			dd[nW][nH] = ++cmt;
		}

		ldk[dd[nW][nH]].pb(cnt);
		//cout << se[cnt] << endl;

	}

	cin >> W >> H;

	for (int h = 1; h <= W; h++)
	for (int r = 1; r <= H; r++)
	{
		vit[h][r] = 0;
		 cin >> s[h][r];
	}

	cnt = n;

	for (int h = 1; h <= W; h++)
	for (int r = 1; r <= H; r++)
	if (vit[h][r] == 0 && s[h][r] == 'X')
	{
		cnt++;
		mxr = 0; mnr = oo; mxh = 0; 

		dfs(h, r);

		int nW = mxh - h + 1, nH = mxr - mnr + 1;
		string se1 = "", se2 = "", se3 = "";

		if (nW <= nH)
		{
			int kt = 0;
			for (int e = h; e <= mxh; e++)
			for (int f = mnr; f <= mxr; f++)
			{
				se[cnt] += (vit[e][f] == cnt ? 'X' : '.');
				se1 += (vit[mxh - e + h][mxr - f + mnr]  == cnt ? 'X' : '.');
				if (kt == 0)
				{
					if (se[cnt].back() > se1.back()) kt = 1;
					else if (se[cnt].back() < se1.back()) kt = -1;
				}
			}
			if (kt == 1) swap(se1, se[cnt]);
		}

		if (nW >= nH)
		{
			int kt = 0;
			for (int f = mnr; f <= mxr; f++)
			for (int e = mxh; e >= h; e--)
			{
				se2 += (vit[e][f] == cnt ? 'X' : '.');
				se3 += (vit[mxh - e + h][mxr - f + mnr]  == cnt ? 'X' : '.');
				if (kt == 0)
				{
					if (se2.back() > se3.back()) kt = 1;
					else if (se2.back() < se3.back()) kt = -1;
				}
			}
			
			if (kt == 1) swap(se2, se3);
			
			if (nW == nH)
			{
				if (se2 > se[cnt]) swap(se2, se[cnt]);
			} else se[cnt] = se2;
			
			swap(nW, nH);
		}

			//cout << nW << " " << nH << endl;
		if (dd[nW][nH]) dk[dd[nW][nH]].pb(cnt);
	}

	// for (int i = 1; i <= cmt; i++)
	// {
	// 	sort(ALL(dk[i]), cmp); sort(ALL(ldk[i]), cmp);
	// 	cout << i << "\n";
	// 	for (auto v : dk[i]) cout << se[v] << endl;
	// 	cout << endl;
	// 	for (auto v : ldk[i]) cout << se[v] << endl;
	// 	cout << "----------------\n";
	// }

	for (int i = 1; i <= cmt; i++)
	if ((int)dk[i].size() && (int)ldk[i].size())
	{
		sort(ALL(dk[i]), cmp); sort(ALL(ldk[i]), cmp);
		
		int l = 0;
		for (int j = 0; j < (int)ldk[i].size(); j++)
		if (j > 0 && se[ldk[i][j]] == se[ldk[i][j-1]])
		{
			res[ldk[i][j]] = res[ldk[i][j-1]];
		}
		else
		{
			while(l < (int)dk[i].size() && se[dk[i][l]] < se[ldk[i][j]]) l++;

			if (l < (int)dk[i].size())
			{
				while(l < (int)dk[i].size() && se[dk[i][l]] == se[ldk[i][j]])
				{
					res[ldk[i][j]]++; l++;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) cout << res[i] << " ";

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
