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
long long f[200][200];

long long dp(int id, int st, int tt)
{
	if (id == -1)
	{
		return st <= 3;
	}

	if (tt == 0 && f[id][st] != -1) return f[id][st];

	int lim = (tt ? s[id] - '0' : 9);
	long long res = 0;

	for (int digit = 0; digit <= lim; digit++)
	{
		res += dp(id - 1, st + (digit != 0), (digit == s[id] - '0' ? tt : 0));
	}

	if (tt == 0) f[id][st] = res;

	return res;
}

long long cal(long long x)
{
	s = to_string(x);
	reverse(ALL(s));
	return dp(s.size() - 1, 0, 1);

}
void solve() 
{	
	long long l, r;
	cin >> l >> r;

	cout << cal(r) - cal(l - 1)<< "\n";
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
    
    for (int i = 0; i <= 190; i++) for (int j = 0; j <= 190; j++) f[i][j] = -1;

    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
