#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
#define fi first
#define se second
#define pb push_back
#define log 19
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

vector<int> basis[200005];
int a[100005], sz = 0;
ll lt[100005];

void add(int id, int val)
{
	for (int i = 0; i <= log; i++)
	if (ck(val, i))
	{
		if (!basis[id][i])
		{
			basis[id][i] = val;
			if (id == 0) sz++;
			return;
		}
		val ^= basis[id][i];
	}
}

bool check(int val)
{
	for (int i = 0; i <= log; i++)
	if (ck(val, i))
	{
		if (!basis[0][i]) return false;

		val ^= basis[0][i];
	}

	return true;
}

void build(int id, int l, int r)
{
	if (l == r)
	{
		basis[id].assign(log + 1, 0);
		for (int i = 0; i <= log; i++) if (ck(a[l], i))
		{
			basis[id][i] = a[l]; break;
		}
		return;
	}

	int mid = (l + r) >> 1;
	build(id*2, l, mid); build(id*2+1, mid + 1, r);
	basis[id] = basis[id*2];
	for (auto v : basis[id*2+1]) if (v) add(id, v);
}

void update(int id, int l, int r, int vt, int val)
{
	if (l > vt || r < vt) return;
	if (l == r)
	{
		basis[id].assign(log + 1, 0);
		for (int i = 0; i <= log; i++) if (ck(val, i))
		{
			basis[id][i] = val; break;
		}
		return;
	}

	int mid = (l + r) >> 1;

	update(id*2, l, mid, vt, val); update(id*2+1, mid + 1, r, vt, val);
	basis[id] = basis[id*2];

	for (auto v : basis[id*2+1]) if (v) add(id, v);
}

void get(int id, int l, int r, int u, int v)
{
	if (sz == log + 1) return;
	
	if (l > v || r < u) return;

	if (u <= l && r <= v)
	{
		for (auto v : basis[id]) if (v) add(0, v);
		return;
	}

	int mid = (l + r) >> 1;

	get(id*2, l, mid, u, v); get(id*2 + 1, mid + 1, r, u, v);
}

void solve() 
{
	int n, q;
	cin >> n >> q;
	lt[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		lt[i] = 2ll*lt[i-1]%MOD;
	}

	build(1, 1, n);

	while(q--)
	{
		int ty, l, r;
		cin >> ty >> l >> r;
		if (ty == 1)
		{
			update(1, 1, n, l, r);
		}
		else
		{
			int s;
			cin >> s;
			basis[0].assign(log + 1, 0); sz = 0;
			get(1, 1, n, l, r);
			if (check(s))
			cout << lt[r - l + 1 - sz] << "\n"; 
			else cout << "0\n";
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
    //freopen("XORSEG.inp","r",stdin); freopen("XORSEG.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
