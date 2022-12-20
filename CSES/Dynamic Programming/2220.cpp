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

long long f[22][10][2][2];
string s;
long long dp(int id, int pre, int t, int w)
{
	if (id == (int)s.size())
	{
		return  f[id][pre][w][t] = 1;
	}
	if (f[id][pre][w][t] != -1) return f[id][pre][w][t];
	long long &res = f[id][pre][w][t]; res = 0;
	int lim = t ? s[id] - '0' : 9;
	for (int i = 0; i <= lim; i++)
	if (w || i != pre)
	{
		int newt = t ? (i == lim) : 0;
		int neww = 1; neww = w ? (i == 0) : 0;
		res += dp(id + 1, i, newt, neww);
	}
	return res;
}
long long cal(long long x)
{
	if (x < 0) return 0;
	s = to_string(x);
	for (int i = 0; i <= 20; i++) for (int j = 0; j <= 9; j++) for (int t = 0; t < 2; t++) for (int tt = 0; tt < 2; tt++) f[i][j][t][tt] = -1;
	return dp(0, 0, 1, 1);
	//return 2;
}
void solve() 
{
	long long a, b;
	cin >> a >> b;
	cout << cal(b) - cal(a-1);
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
