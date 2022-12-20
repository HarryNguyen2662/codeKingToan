#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 17
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1ll << (i))
#define ck(n, i) (((n) >> (i))&1) 
#define setp(x) setprecision(x)
#define NMOD 3
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789; 
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 922372036854775807;
inline int ReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    int x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    return x;
}
void WriteInt(int x)
{
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
int n;
long long m;
pair<long long, long long> a[1000];
bool check(long long val)
{
	long long products = 0;
	for (int i = 1; i <= n; i++)
	{
		long long sl = val - val/(a[i].se + 1);
		if (a[i].fi > (m - products)/sl) return true;
		long long va = a[i].fi*sl;
		if (products >= m - va) return true;
		products += va;
	}
	return false;
}
void solve()
{
	cin >> n >> m;
	long long l = 1, r = oo18;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].fi >> a[i].se;
		//r = max(r, m/a[i].fi + m/a[i].se);
	}
	while(l <= r)
	{
		long long mid = (l + r)/2;
		if (check(mid)) r = mid - 1; else l = mid + 1;
	}
	cout << l;
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
