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
struct DATA
{
	int len, lenL, lenR;
	long long sub;
	bool l, r;
	DATA()
	{
		len = lenL = lenR = 0;
		sub = 0;
		l = r = false;
	}
};
DATA add(const DATA &x, const DATA &y)
{
	DATA res;
	res.sub = x.sub + y.sub;
	//cout << x.sub << " " << y.sub << endl;
	res.lenL = x.lenL; res.lenR = y.lenR;
	res.l = x.l; res.r = y.r;
	if (x.r != y.l) 
	{
		//cout << "hello" << endl;
		//cout << res.sub << endl;
		res.sub += 1ll*x.lenR*y.lenL;
		if (y.lenR == y.len) res.lenR += x.lenR;
		if (x.lenL == x.len) res.lenL += y.lenL;
	}
	res.len = x.len + y.len;
	return res;
}
DATA st[800005], ww;
bool lazy[800005];
void dolazy(int id)
{
	bool &ok = lazy[id];
	if (!ok) return;
	st[id*2].l = 1-st[id*2].l; st[id*2].r = 1-st[id*2].r;
	st[id*2+1].l = 1-st[id*2+1].l; st[id*2+1].r = 1-st[id*2+1].r;
	lazy[id*2] = 1-lazy[id*2];
	lazy[id*2+1] = 1-lazy[id*2+1];
	ok = 0;
}
void build(int id, int l, int r)
{
	if (l == r)
	{
		//cout << id << endl;
		st[id].sub = 1; st[id].len = st[id].lenL = st[id].lenR = 1;
		return;
	}
	int mid = (l+r)/2;
	build(id*2, l, mid); build(id*2+1, mid + 1, r);
	st[id] = add(st[id*2], st[id*2+1]);
}
void update(int id, int l, int r, int u, int v)
{
	if (r < u || l > v) return;
	if (u <= l && r <= v)
	{
		st[id].l = 1 - st[id].l;
		st[id].r = 1 - st[id].r;
		lazy[id] = 1 - lazy[id];
		return;
	}
	int mid = (l + r)/2;
	dolazy(id);
	update(id*2, l, mid, u, v); update(id*2+1, mid + 1, r, u, v);
	st[id] = add(st[id*2], st[id*2+1]);
}

DATA get(int id, int l, int r, int u, int v)
{
	if (r < u || l > v) 
	{
		//DATA w; w.sub = 0; w.len = -1; w.l = w.r = w.lenL = w.lenR = 0;
		return ww;
	}
	if (u <= l && r <= v)
	{
		return st[id];
	}
	dolazy(id);
	int mid = (l + r)/2;
	return add(get(id*2, l, mid, u, v), get(id*2+1, mid + 1,r, u, v));
}
void solve() 
{
	int n, q;
	cin >> n >> q;
	//cout << n << endl;
	//cout << st[1].sub << endl;
	build(1, 1, n);
	//cout << st[1].sub << endl;
	for (int i = 1; i <= n; i++)
	{
		bool ti;
		cin >> ti;
		if (ti) update(1, 1, n, i, i);
	}
	//cout << st[1].sub <<endl;
	while(q--)
	{
		int type, l, r;
		cin >> type >> l >> r;
		if (type == 1)
		{
				update(1, 1, n, l, r);
		}
		else
		{
			cout << get(1, 1, n, l, r).sub << "\n";
		}
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
    //cin >> testcase;
    while(testcase--)
        solve();
}
