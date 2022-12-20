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
long long dp[100005], st[400005], stt[400005];
int iid[100005], a[100005], eid[100005];
void update(int id, int l, int r, int vt, long long val)
{
	if (l > vt || vt > r) return;
	if (l == r)
	{
		st[id] = val;
		//cout << "hello" << id << endl;
		return;
	}
	int mid = (l + r)/2;
	update(id*2, l, mid, vt, val); update(id*2+1, mid + 1, r, vt, val);
	st[id] = max(st[id*2], st[id*2+1]);
}
long long getmax(int id, int l, int r, int u, int v)
{
	if (r < u || l > v) return -oo-5;
	if (u <= l && r <= v)
	{
		return st[id];
	}
	int mid = (l + r)/2;
	return max(getmax(id*2, l, mid, u, v), getmax(id*2+1, mid + 1, r, u, v));
}
void update1(int id, int l, int r, int vt, long long val)
{
	if (l > vt || vt > r) return;
	if (l == r)
	{
		stt[id] = val;
		//cout << "hello" << id << endl;
		return;
	}
	int mid = (l + r)/2;
	update1(id*2, l, mid, vt, val); update1(id*2+1, mid + 1, r, vt, val);
	stt[id] = max(stt[id*2], stt[id*2+1]);
}
long long getmax1(int id, int l, int r, int u, int v)
{
	if (r < u || l > v) return -oo-5;
	if (u <= l && r <= v)
	{
		return stt[id];
	}
	int mid = (l + r)/2;
	return max(getmax1(id*2, l, mid, u, v), getmax1(id*2+1, mid + 1, r, u, v));
}
void solve() 
{
	int n;
	stack<int> w, ww;
	w.push(0);
	a[0] = oo + 5;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		while(a[w.top()] <= a[i]) w.pop();
		iid[i] = w.top();
		w.push(i);
		while(!ww.empty() && a[ww.top()] >= a[i]) ww.pop();
		if (!ww.empty()) eid[i] = ww.top(); 
		ww.push(i);
	}
	dp[0] = 0;
	//cout << id[1] << endl;
	update(1, 0, n, 0, dp[0] - a[1]);
	update1(1, 0, n, 0, dp[0] + a[1]);
	for (int i = 1; i <= n; i++)
	{
		dp[i] = a[i] + getmax(1, 0, n, iid[i], i - 1);
		dp[i] = max(dp[i], getmax1(1, 0, n, eid[i], i -1) - a[i]);
		update(1, 0, n, i, dp[i] - a[i+1]);
		update1(1, 0, n, i, dp[i] + a[i+1]);
		//cout << iid[i] << " " <<  dp[i] << endl;
	}
	cout << dp[n];
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
