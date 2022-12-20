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
int sl[100005][10][2][2], dp[100005][10][2][2], adu, pw[100005];

long long f(int id, int pre, int ti, int tii)
{
	if (dp[id][pre][ti][tii] != -1) return dp[id][pre][ti][tii];
	if (id == (int)s.size())
	{
		//cout << pre << " " << ti << " " << tii << endl;
		if (!tii || !adu)
		{
			sl[id][pre][ti][tii] = 1;
			return dp[id][pre][ti][tii] = pre*(ti == 0);
		}
		else
		{
			return dp[id][pre][ti][tii] = 0;
		}
	}
	int &re = sl[id][pre][ti][tii]; re = 0;
	int &res = dp[id][pre][ti][tii]; res = 0;

	int mx = (tii == 1) ? s[id] - '0' : 9;

	for (int digit = 0; digit <= mx; digit++)
	{
		int newtii = (digit == s[id] - '0') ? tii : 0;
		
		res = (res + f(id + 1, digit, pre == digit, newtii));	
		re = (re + sl[id + 1][digit][pre == digit][newtii]);
		
		if (res >= MOD) res -= MOD;
		if (re >= MOD) re -= MOD;
	}

	if (ti == 0)
	{
		res = (res + 1ll*re*pre%MOD*1ll*pw[(int)s.size() - id]%MOD);
		if (res >= MOD) res -= MOD;
	}
	return res;
}


int cal()
{
	for (int i = 0; i <= (int)s.size(); i++)
	for (int j = 0; j <= 9; j++)
	for (int ok = 0; ok < 2; ok++)
	for (int ok1 = 0; ok1 < 2; ok1++) 
	{
		sl[i][j][ok][ok1] = 0;
		dp[i][j][ok][ok1] = -1;
	}

	return f(0, 0, 0, 1);
}


void solve() 
{
	cin >> s;
	adu = 1;
	long long res = -cal() + MOD;
	if (res >= MOD) res -= MOD;
	
	cin >> s;
	adu = 0;
	res += cal();
	if (res >= MOD) res -= MOD;
	cout << res << "\n";

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
    pw[0] = 1;
    for (int i = 1; i <= 100000; i++) pw[i] = 1ll*pw[i-1]*10%MOD;

    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
