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
struct segmenttree
{
	vector<long long> seg, lazy;

	void resize(int n)
	{
		seg.assign(4*n + 5, -oo15);
		lazy.assign(4*n + 5, -oo15);
	}

	void dolazy(int id)
	{
		long long &add = lazy[id];
		seg[id*2] = max(seg[id*2], add); seg[id*2+1] = max(seg[id*2+1], add);
		lazy[id*2] = max(lazy[id*2], add); lazy[id*2+1] = max(lazy[id*2+1], add);
		add = -oo15;
	}

	void update(int id, int l, int r, int u, int v, long long val)
	{
		if (l > v || r < u) return;
		if (u <= l && r <= v)
		{
			seg[id] = max(seg[id], val); lazy[id] = max(lazy[id], val);
			return;
		}
		int mid = (l + r)/2;
		dolazy(id);
		update(id*2, l , mid, u, v, val); update(id*2+1, mid + 1, r, u, v, val);
		seg[id] = max(seg[id*2], seg[id*2+1]);
	}

	long long get(int id, int l, int r, int u)
	{
		if (l > u || r < u) return -oo15;
		if (l == r)
		{
			return seg[id];
		}
		dolazy(id);
		int mid = (l + r)/2;
		if (mid >= u) return get(2*id, l, mid, u); else return get(2*id+1, mid + 1, r, u);
	}
};
segmenttree qa[20];
pair<int,int> t[100005];
vector<int> a[20];
int c[100005][4];
void solve() 
{
	int n;
	vector<int> ldk;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i].fi >> t[i].se >> c[i][0] >> c[i][1] >> c[i][2] >> c[i][3];
	}
	for (int i = 0; i < mask(4); i++)
	{
		if ((ck(i, 0) && ck(i, 1))|| (ck(i, 1) && ck(i, 2)) || (ck(i, 2) && ck(i, 3))) continue;
		ldk.pb(i);
		qa[i].resize(n);
		for (int j = 0; j < mask(4); j++)
		{	
			if ((ck(j, 0) && ck(j, 1))|| (ck(j, 1) && ck(j, 2)) || (ck(j, 2) && ck(j, 3))) continue;
			bool kt = true;
			for (int e = 0; e < 4; e++) if (ck(i, e) && ck(j, e))
			{
				kt = false;
				break;
			
			}
		//	cout << i << " " << j << endl
;			if (kt) a[i].pb(j);
		}
	}
	
	long long resres = -oo15;
	for (auto v : ldk)
	{
		long long val = 0;
		for (int i = 0 ; i < 4; i++) if (ck(v, i)) val += c[1][i];
		if (v != 0)
		resres = max(resres, val);
		qa[v].update(1, 1, n, 1 + t[1].fi, min(n, 1 + t[1].se), val);
	}
	//cout << resres << endl;
	for (int i = 2; i <= n; i++)
	for (auto v : ldk)
	{
		long long val = -oo15;
		for (auto vv : a[v]) val = max(val, qa[vv].get(1, 1, n, i));
		for (int j = 0; j < 4; j++) if (ck(v, j)) val += c[i][j];
		//cout << val << endl;
		if (v != 0)
		resres = max(resres, val);
		qa[v].update(1, 1, n, i + t[i].fi, min(n, i + t[i].se), val);
	}
	cout << resres;

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
