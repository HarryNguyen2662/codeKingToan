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

char s[1000005];
long double f[1000005];

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}

	int dem0 = 0, dem1 = 0;

	long double de0 = 0, de1 = 0;
	if (s[n] == '0') de0 = 1; else de1 = 1;
	
	f[n] = 1;
	long double su = 1;

	for (int i = n - 1; i; i--)
	{
		if (s[i] == '0') de0 += (n - i + 1); else de1 += (n - i + 1);

		if (s[i] == '0')
		f[i] = (long double)1/(n - i + 1)*(su + de0);
		else
		f[i] = (long double)1/(n - i + 1)*(su + de1);

		su += f[i];
	}

	cout << fixed << setp(9) << f[1];
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
