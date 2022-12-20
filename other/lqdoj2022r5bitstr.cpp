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

ll f[2005][2];

void solve() 
{
	int n, u, v;

	cin >> n >> u >> v;

	for (int i = 1; i <= n; i++)
	{
		f[i][0] = f[i][1] = 0;
	}

 	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (i >= v)
		{
			f[i][1] += f[i - v][0]; 
		}
		f[i][1] += f[i-1][1];
		f[i][1] %= MOD;
		f[i][0] += f[i - 1][0] + f[i - 1][1];
		f[i][0] %= MOD;
	}

	cout << (f[n][1] + f[n][0])%MOD << "\n";
}


int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("BITSTR.inp","r",stdin); freopen("BITSTR.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
