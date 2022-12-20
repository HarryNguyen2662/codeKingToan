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
long long st[400005];
long long m;
void build(int id, int l, int r)
{
	if (l == r)
	{
		st[id] = 1;
		return;
	}
	int mid = (l + r)/2;
	build(id*2, l, mid); build(id*2+1, mid + 1, r);
	st[id] = st[id*2]*st[id*2+1];
}
void update(int id, int l, int r, int vt, int val)
{
	if (r < vt || l > vt) return;
	if (l == r)
	{
		st[id] = val;
		return;
	}
	int mid = (l + r)/2;
	update(id*2, l, mid, vt, val); update(id*2+1, mid + 1, r, vt, val);
	st[id] = st[id*2]*st[id*2+1]%m;
}
void solve() 
{
	int n;
	cin >> n >> m;
	build(1, 1, n);
	for (int i = 1; i <= n; i++)
	{
		int ti;
		int val;
		cin >> ti >> val;
		if (ti == 1) update(1, 1, n, i, val); else update(1, 1, n, val, 1);
		cout << st[1] << "\n";	
	}
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
