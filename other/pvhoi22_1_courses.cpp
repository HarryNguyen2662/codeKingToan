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
int n, m, res[300005], a[2005];
pair<long long,int> b[300005];
int cal(long long val) 
{
	priority_queue<int, vector<int>, greater<int>> pq;
	int re = n;
	long long su = 0;
	for (int i = 1; i <= n; i++)
	{	
		su += a[i]; pq.push(a[i]);
		if (su + val < 0)
		{
			su -= pq.top();
			pq.pop();
			re--;
		}
	}
	return re;
}
void xuly(int l, int r, int mn, int mx)
{
	if (l > r) return;
	if (mn == mx)
	{
		for (int i = l; i <= r; i++) res[b[i].se] = mn;
		return;
	}
	int mid = (l + r)/2;
	int w = cal(b[mid].fi);
	res[b[mid].se] = w;
	xuly(l, mid - 1, mn, w);
	xuly(mid + 1, r, w, mx);
}
void solve() 
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	cin >> a[i];

	for (int i = 1; i <= m; i++)
	{
		cin >> b[i].fi;
		b[i].se = i;
	}
	sort(b + 1, b + 1 + m);
	xuly(1, m, 0, n);
	for (int i = 1; i <= m; i++) cout << res[i] << " ";
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
