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
const int lim = 100000;
bool dem[11];
bool kt(long long val)
{
	for (int i = 0; i < 10; i++) dem[i] = false;
	val = val*val;
	while(val)
	{
		if (dem[val%10]) return false;
		dem[val%10] = true;
		val/=10;
	}
	return true;
}

void solve() 
{
	vector<long long> ldk;
	for (int i = 1; i <= lim; i++)
	{
		if (kt(i)) ldk.pb(1ll*i*i);
	}
	long long k;
	cin >> k; k--;
	if (k >= (int)ldk.size())
	{
		cout << -1;
	}
	else cout << ldk[k];

}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("squares.inp","r",stdin); freopen("squares.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
