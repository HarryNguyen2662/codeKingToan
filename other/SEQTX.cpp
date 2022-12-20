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
typedef pair<long long, long long> line;
long long su[100005], f[100005];
line tree[400005];
int n;
long long g(line a, long long x)
{
	return a.fi*x + a.se;
}
void addline(line nline, int\ id, int l, int r)
{
	int m = (l + r)/2;
	bool mid = g(nline, m) > g(tree[id], m);
	bool left = g(nline, l) > g(tree[id], l);
	if (mid) swap(nline, tree[id]);
	if (r - l == 1) return;
	if (left != mid) addline(nline, id*2, l, m);
	else addline(nline, id*2 + 1, m, r);
}
long long query(int va, int id = 1, int l = 0, int r = n)
{
	int m = (l + r)/2;
	long long cur = g(tree[id], va);
	if (r - l == 1) return cur;
	if (va < m) return max(cur, query(va, id*2, l, m));
	else return max(cur, query(va, id*2 + 1, m , r));
}
void solve() 
{	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int val;
		cin >> val;
		f[i] = f[i-1] + su[i-1] + val;
		su[i] = su[i-1] + val;
	}
	for (int i = 1; i <= 4*(n + 1); i ++) tree[i] = {0, -oo18};
	addline({0, 0}, 1, 0, n);
	long long res = -oo18;
	for (int i = 1; i <= n; i++)
	{
		res = max(res, query(i) + f[i]);
		addline({-su[i], 1ll*i*su[i] - f[i]}, 1, 0, n);
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
