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

long long power(long long x, long long y, ll mod)
{
	if (y == 0) return 1;
	long long xx = power(x, y/2, mod);
	if (y%2) return xx*xx%mod*x%mod; else return xx*xx%mod;
}

void solve() 
{	
	ll a, b, d;
	cin >> a >> b >> d;
	int cnt = 0;

	while(a%2 == 0 && b%2 ==0 && d%2 == 0)
	{
		cnt++;
		a /= 2; b /= 2;  d /= 2;
	}
	if (d%2 == 0 && (a%2 || b%2))
	{
		cout << "-1\n"; return;
	}

	cout <<  mask(cnt)*( (power((d + 1)/2, 30 - cnt, d) - 1 + d)%d*mask(30 - cnt) + mask(30 - cnt) - 1) << "\n";
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
    cin >> testcase;
    while(testcase--)
        solve();
}
