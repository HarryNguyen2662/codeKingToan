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

int lu[1006], luu[1005], dis[1005][1005];
char s[1005][1005];

void solve() 
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++) luu[i] = lu[i] = -oo;

	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
	{
		cin >> s[i][j];
		dis[i][j] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		int w = -oo;
		for (int j = 1; j <= m; j++)
		{
			if (s[i][j] == 'B') luu[j] = max(luu[j], -i -j);
			w = max(w, luu[j]);
			dis[i][j] = max(dis[i][j], i + j + w);
		}
		w = -oo;
		for (int j = m; j; j--)
		{
			if (s[i][j] == 'B') lu[j] = max(lu[j], -i + j);
			w = max(w, lu[j]);
			dis[i][j] = max(dis[i][j], w + i -j);
		}
	}

	for (int i = 1; i <= m; i++) luu[i] = lu[i] = -oo;

	pair<int,int> id;
	int re = oo;

	for (int i = n; i; i--)
	{
		int w = -oo;
		for (int j = 1; j <= m; j++)
		{
			if (s[i][j] == 'B') luu[j] = max(luu[j], +i -j);
			w = max(w, luu[j]);
			dis[i][j] = max(dis[i][j], -i + j + w);
		}
		w = -oo;
		for (int j = m; j; j--)
		{
			if (s[i][j] == 'B') lu[j] = max(lu[j], +i + j);
			w = max(w, lu[j]);
			dis[i][j] = max(dis[i][j], w + -i -j);

			if (dis[i][j] < re)
			{
				id = {i, j}; re = dis[i][j];
			}
		}
	}

	//out << dis[4][2] << endl;

	cout << id.fi << " " << id.se << "\n";

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
    cin >> testcase;
    while(testcase--)
        solve();
}
