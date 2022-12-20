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
const int lim = 5000;
int dp[6][10001];

void solve() 
{
	int n, d;
	cin >> n >> d;	
	bool kt = false;
	int re = oo;
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		cin >> l >> r;
		if (d >= l && d <= r)
		{
			cout << "1";
			return;
		}
		if (2*r > d) kt = true;
		else
		{
			if (d%r == 0) re = min(re, d/r);
			else re = min(re, (d - 2*r + 1)/r  + ((d - 2*r + 1)% r != 0)+ 2);
		}
	}
	if (kt)
	{
		cout << "2"; return;
	}

	cout << re;
}	

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("golf.inp","r",stdin); freopen("golf.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
