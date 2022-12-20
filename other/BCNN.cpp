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
const long long MOD = 3769 * 14797 * 2;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int lim = 1000000;

int prime[lim + 5], dem[lim + 5];
vector<int> ldk;


void prepare()
{
	for (int i = 1; i <= lim; i++)
	{
		prime[i] = i;
	}

	for (int i = 2; i <= lim; i++)
	if (prime[i] == i)
	{
		for (int j  = 2*i; j <= lim; j+=i) 
		prime[j] = i;
		ldk.pb(i);
	}
}

int cal(ll val, int ti)
{
	int res = 0;
	while(val)
	{
		res += val/ti;
		val /= ti;
	}
	return res;
}

void solve() 
{
	int a, b;
	cin >> a >> b;

	ll res = 1;

	for (auto v : ldk) 
	{	
		ll cur = cal(b, v) - cal(a -  1, v); 
		if (cur != 0)
		{
			// cout << v << " " << cur << endl;	
			cur = ((cur + 1) *2ll%MOD) - 1;
			res = res * cur % MOD;
		}
	}
	
	res += MOD; res %= MOD;

	cout << res << "\n";
}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    // 
    // 
    freopen("BCNN.inp","r",stdin); freopen("BCNN.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    prepare();
    cin >> testcase;
    while(testcase--)
        solve();
}
