#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
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

string L, R;
ll dp[50005][2][2][2], sl[50005][2][2][2];

ll f(int id, int l, int e, int r)
{
	if (id == 0)
	{
		sl[id][l][e][r] = 1;
		return 0;
	}

	if (sl[id][l][e][r] != 0) return dp[id][l][e][r];

	ll &re = dp[id][l][e][r]; 

	int limL = (l == 0 ? L[id - 1] - '0' : 0);
	int limR = (r == 0 ? R[id - 1] - '0' : 9);

	for (int le = limL; le <= 9; le++)
	for (int ri = 0; ri <= limR; ri++)
	if (e == 1)
	{
		int nl = (le == L[id - 1] - '0' ? l : 1), nr = (ri == R[id - 1] - '0' ? r : 1);

		ll cur = f(id - 1, nl, e, nr);
		
		re += cur + 1ll*abs(le - ri)*sl[id-1][nl][e][nr]%MOD; re %= MOD;
		
		sl[id][l][e][r] += sl[id-1][nl][e][nr]; 
		if (sl[id][l][e][r] >= MOD) sl[id][l][e][r] -= MOD;
	}
	else if (e == 0 && le <= ri)
	{
		int nl = (le == L[id - 1] - '0' ? l : 1), nr = (ri == R[id - 1] - '0' ? r : 1 );
		int ne = (le == ri ? 0 : 1);
		
		ll cur = f(id - 1, nl, ne, nr);
		
		re += cur + 1ll*(ri - le)*sl[id-1][nl][ne][nr]%MOD; re %= MOD;
		
		sl[id][l][e][r] += sl[id-1][nl][ne][nr]; 
		if (sl[id][l][e][r] >= MOD) sl[id][l][e][r] -= MOD;
	}

	return re;
}

void solve() 
{
	cin >> L >> R;

	reverse(ALL(L)); reverse(ALL(R));
	while((int)L.size() < (int)R.size()) L += "0";
	int lim = (int)R.size();

	cout << 2ll*f(lim, 0, 0, 0)%MOD;
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
