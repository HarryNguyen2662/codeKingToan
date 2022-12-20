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
string s;
long long dp[100005][11][2][2];

long long f(int id, int pre, bool ok, bool ti)
{
	if (id == ((int)s.size() + 1)/2)
	{
		//cout << pre << " " <<  ok << " " << ti << endl;
		if (!ok || !ti) dp[id][pre][ok][ti] = 1; else dp[id][pre][ok][ti] = 0;
		return dp[id][pre][ok][ti];
	}
	if (dp[id][pre][ok][ti] != -1) return dp[id][pre][ok][ti];

	long long &res = dp[id][pre][ok][ti]; res = 0;

	int lim = (ti == 0) ? 9 : s[id] - '0';

	for (int digit = 0; digit <= lim; digit++)
	if (pre == 10 || abs(digit - pre) >= 5)
	{
		bool newti = (digit == s[id] - '0') ? ti : 0;
		int newok = 0; if ((newti && s[id] > s[(int)s.size() - id - 1]) || ok) newok = 1; else newok = 0;
		int newpre = 10; if (pre != 10 || digit != 0) newpre = digit;
		
		res = (res + f(id + 1, newpre, newok, newti))%MOD;
		//cout << f(id + 1, newpre, newok, newti) << endl;
	}
	return res;
}

void solve() 
{
	cin >> s;

	for (int i = 0; i <= (int)s.size(); i++) for (int pre = 0; pre <= 10; pre++) 
	for (int e = 0; e < 2; e++) for (int t = 0; t < 2; t++)
	dp[i][pre][e][t] = -1;		

	cout << (f(0, 10, 0, (int)s.size()%2) - 1 + MOD)%MOD;
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
