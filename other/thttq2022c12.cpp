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

char ans[1000005];
int cnt = 0, id[20000005], ll[20000005], rr[20000005];

void create(int &i, int l, int r, int vt)
{	
	if (i == 0) i = ++cnt;
	if (l == r) return;
	int mid = (l + r)/2;
	if (vt <= mid) create(ll[i], l, mid, vt); else create(rr[i], mid + 1, r, vt);
}

int merge(int a, int b)
{
	if (a == 0 || b == 0) return a + b;

	ll[a] = merge(ll[a], ll[b]);
	rr[a] = merge(rr[a], rr[b]);

	return a;
}

void update(int &i, int &ii, int l, int r, int u, int v)
{
	if (i == 0 || l > v || r < u) return;
	if (u <= l && r <= v)
	{
		ii = merge(ii , i);
		i = 0;
		return;
	}
	if (ii == 0) ii = ++cnt;
	int mid = (l + r)/2;
	update(ll[i], ll[ii], l, mid, u, v);
	update(rr[i], rr[ii], mid + 1, r, u, v);
}

void get(int i, int l, int r, int val)
{
	if (i == 0) return;
	if (l == r)
	{	
		ans[l] = (char)('a' + val);
		return;
	}
	int mid = (l + r)/2;
	get(ll[i], l, mid, val); get(rr[i], mid + 1, r, val);
}

void solve() 
{
	string s;
	cin >> s;
	int n = (int)s.size();
	s = "@" + s;
	for (int i = 1; i <= n; i++)
	{
		create(id[s[i] - 'a'], 1, n, i);
	}

	int m;
	cin >> m;
	while(m -- )
	{
		int l, r; char x, y;
		cin >> l >> r >> x >> y;
		l ++ ; r ++;
		if (x != y)
		{
			update(id[x - 'a'], id[y - 'a'], 1, n, l, r);
		}
	}
	for (int i = 0; i < 26; i++) get(id[i], 1, n, i);
	for (int i = 1; i <= n; i++) cout << ans[i];
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
