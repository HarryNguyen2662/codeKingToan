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
const long long MOD = 2147483648;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


void solve() 
{
	int n, m, s, v;
	cin >> n >> m >> s >> v;

	ll dem = 0;
	
	ll cur = s;

	for (int i = 1; i <= m; i++)
	{
		int w;
		cin >> w;
		if (w > 0) dem++;
		cur = (cur*1103515245 + 12345) % MOD;
	}

	for (int i = m + 1; i <= n; i++)
	{
		if (2*(cur % v) - v + 1 > 0) dem++;
		cur = (cur*1103515245 + 12345) % MOD;
	}

	cout << dem*(dem - 1)*(dem - 2)/6;
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("triangle.inp","r",stdin); freopen("triangle.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
