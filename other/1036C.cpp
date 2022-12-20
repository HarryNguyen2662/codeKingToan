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

long long dp[25][25][2];
vector<int> s;

long long f(int id, int sl, int ti = 1)
{
	if (id == -1)
	{
		return (sl <= 3);
	}

	if (dp[id][sl][ti] != -1) return dp[id][sl][ti];

	long long ans = 0;

	int lim = (ti == 1) ? s[id] : 9;

	for (int digit = 0; digit <= lim; digit++)
	ans += f(id - 1, sl + (digit > 0), (digit == s[id] ? ti : 0));

	if (!ti) dp[id][sl][ti] = ans;

	return ans; 
}


long long cal(long long val)
{
	s.clear();
	while(val) 
	{
		s.pb(val%10); val /= 10;
	}

	return f((int)s.size() - 1, 0);
}

void solve() 
{	
	long long L, R;
	cin >> L >> R;
	
	cout << cal(R) - cal(L - 1) << "\n";
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
    for (int i = 0; i <= 19; i++) for (int j = 0; j <= 19; j++) for (int e = 0; e < 2; e++) dp[i][j][e] = -1;
    cin >> testcase;
    while(testcase--)
        solve();
}
