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

long long dp[10005][18][11][2];
string s;

long long f(int id, int du, int pre, bool ti)
{
	if (id == (int)s.size())
	{
		//cout << pre << " " << du << endl;
		return dp[id][du][pre][ti] = (du == 0);
	}
	
	if (dp[id][du][pre][ti] != -1) return dp[id][du][pre][ti];
	
	long long &res = dp[id][du][pre][ti]; res = 0;

	int lim = (ti == 0) ? 9 : (s[id] - '0');
	
	for (int digit = 0; digit <= lim; digit++)
	if (digit != pre)
	{
		int newti = (digit == s[id] - '0') ? ti : 0;
		
		int newpre; if (digit == 0 && pre == 10) newpre = 10; else newpre = digit;
		//cout << du << " " << s[id] - '0' << " " << (du*10 + s[id] - '0')%17 << endl;
		res = (res + f(id + 1, (du*10 + digit)%17, newpre, newti))%MOD;   
	}
	return res;
}

long long cal(const string &ss)
{
	s = ss;
	for (int i = 0; i <= (int)s.size(); i++) for (int du = 0; du < 17; du++) 
	for (int pre = 0; pre <= 10; pre++) for (int ti = 0; ti < 2; ti++)
	dp[i][du][pre][ti] = -1;
	
	return f(0, 0, 10, 1);		
}	

void solve() 
{	
	string L, R;
	cin >> L >> R;
	int bonus = L[0];
	for (int i = 1; i < (int)L.size(); i++)
	{
		bonus = (bonus*10 + L[i] - '0')%17;
		if (L[i] == L[i-1]) 
		{
			bonus = 1;
			break;
		}
	}
	if (bonus == 0) bonus = 1; else bonus = 0;
	cout << (cal(R) - cal(L) + bonus + MOD)%MOD;
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
