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

inline long long ReadInt() 
{
    char c;
    bool negative = false;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') negative = true;
    long long x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (negative) return -x; else return x;
}

void WriteInt(long long x) 
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
bool kt[1000005];
long long a[1000005];
void solve() 
{
	int n;
	vector<int> prime;
	
	for (int i = 2; 1ll*i*i <= 1000000; i++)
	if (kt[i] == false)
	for (int j = i*i; j <= 1000000; j += i) kt[j] = true;
	for (int i = 2; i <= 1000000; i++) if (!kt[i]) prime.pb(i);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int res = 0;
	for (auto v : prime)
	{
		int re = 0;
		for (int i = 1; i <= n; i++) 
		if (a[i]%v == 0)
		{
			re++;
			while(a[i]%v == 0) a[i] /= v;
		}
		res = max(res, re);
	}
	vector<long long> ldk;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			long long GCD = __gcd(a[i], a[j]);
			if (GCD > 1) ldk.pb(GCD);
		}
	sort(ALL(ldk)); ldk.resize(unique(ALL(ldk)) - ldk.begin());
	for (auto v : ldk)
	{
		int re = 0;
		for (int i = 1; i <= n; i++) 
		if (a[i]%v == 0)
		{
			re++;
		}
		res = max(res, re);
	}
	cout << res;
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
