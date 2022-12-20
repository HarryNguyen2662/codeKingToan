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
bool check(long long val,long long &sum, long long &k, long long &n)
{
	long long va = sum - val;
	long long slpt = min(val-1, k-1);
	long long sum1 = slpt*(2*val -1 - slpt)/2;
	if (sum1 > va) return false;
	va -= sum1;
	slpt = min(val-1, n - k);
	sum1 = slpt*(val-1 + val - slpt)/2;
	return sum1 <= va;
}
void solve() 
{
	long long n, m, k;
	cin >> n >> m >> k;
	long long l = 1, r = m;
	while(l <= r)
	{
		long long mid = (l + r)/2;
		if (check(mid, m, k, n)) l = mid + 1; else r = mid - 1;
	}
	cout <<m - r << "\n";
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("ARRANGE.inp","r",stdin); freopen("ARRANGE.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
