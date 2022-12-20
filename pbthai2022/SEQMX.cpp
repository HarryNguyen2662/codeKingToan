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

const long double lim = 1e-6;

int n, k;
long double b[100005];
long long su[100005];

bool check(long double val)
{
	long double mn = 0;
	for (int i = 1; i <= n; i++)
	{
		long double newval = su[i] - (long double)i*val;
		//cout << fixed << setp(6) << newval << endl;
		if (i >= k && newval >= mn) return true;
		b[i] = newval;
		if (i + 1 >= k) mn = min(mn, b[i - k + 1]);
	}
	return false;
}

void solve() 
{
	cin >> n; cin >> k;
	for (int i = 1; i <= n; i++) 
	{
		cin >> su[i];
		su[i] += su[i-1];
	}

	long double l = -1e5, r = 1e5;


	while(r - l > lim)
	{
		long double mid = (l + r)/2;
		if (check(mid)) l = mid; else r = mid;
	} 

	cout << fixed << setp(5) << (l + r)/2;
	
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
