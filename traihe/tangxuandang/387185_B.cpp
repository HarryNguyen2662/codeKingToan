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

int f[27][100005], le;

void dfs(int x, int y)
{
	if (y == 0) 
	{
		f[x][y] = 2;
		return;
	}
	if (x < 26 && f[x + 1][y-1] == 0) dfs(x + 1, y - 1);
	if (x > 0 && f[x-1][y] == 0) dfs(x - 1, y);

	if (x == 26 || f[x-1][y] == 2) 
	{
		f[x][y] = 3 - f[x - 1][y];
		return;
	}
	if (x == 0 || f[x + 1][y - 1])
	{
		f[x][y] = 3 - f[x + 1][y - 1];
		return;
	}
	
	f[x][y] = 1;

}

void solve() 
{
	string s;
	cin >> s;
	sort(ALL(s));
	le = (int)s.size()%2;
	int x = 0, y = 0;
	for (int i = 0; i + 1 < (int)s.size(); i++)
	if (s[i] != s[i + 1]) 
	{
		x++;
		if (i == (int)s.size() - 2) x++;
	}
	else 
	{
		y++;
		if (i == (int)s.size() - 3) x++;
		i++;
	}
	for (int i = 0; i <= 26; i++) 
	for (int j = 0; j <= y; j++) f[i][j] = 0;
	dfs(x, y);
	//cout << f[2][0] << endl;
	cout << (f[x][y] == 1 ? 'A' : 'B');
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
