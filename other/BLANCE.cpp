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
int n, M, a[100];
map<int,int> dem;
vector<int> ldk;
void xuly1(int i, int su = 0)
{
	if (i == n/2)
	{
		dem[su]++; return;
	}
	xuly1(i + 1, su); xuly1(i + 1, su - a[i+1]); xuly1(i + 1, su + a[i+1]);
}
void xuly2(int i, int su = 0)
{
	if (i == n)
	{
		ldk.pb(su); return;
	}
	xuly2(i + 1, su); xuly2(i + 1, su - a[i+1]); xuly2(i + 1, su + a[i+1]);
}
void solve() 
{
	cin >> n >> M;
	for (int i = 1; i <= n; i++) cin >> a[i];
	xuly1(0); xuly2(n/2);
	long long res = 0;
	for (auto v : ldk) res += dem[M - v];
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
