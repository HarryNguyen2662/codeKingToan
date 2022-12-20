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
const long long MOD = 998244353;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long sg[400005], lazy1[400005], lazy2[400005], a[100005];

void dolazy(int id, int l, int r)
{
	int mid = (l + r)/2;
	for (int i = id*2; i <= id*2+1; i++)
	{
		long long k, kk;
		if (i%2) k = r - mid, kk = r + mid + 1; else k = mid - l + 1, kk = l + mid;
		sg[i] = (sg[i] + lazy1[id]*k%MOD + k*kk%MOD*lazy2[id]%MOD)%MOD; 
		lazy1[i] = (lazy1[i] + lazy1[id])%MOD; lazy2[i] = (lazy2[i] + lazy2[id])%MOD;  
	}
	lazy1[id] = lazy2[id] = 0;
}


void build(int id, int l, int r)
{
	if (l == r)
	{
		sg[id] = a[l];
		return;
	}
	int mid = (l + r)/2;
	build(id*2, l, mid); build(id*2+1, mid + 1, r);
	sg[id] = (sg[id*2] + sg[id*2+1])%MOD;
}

void update(int id, int l, int r, int u, int v, long long val_a, long long val_b)
{
	if (r < u || l > v) return;
	if (u <= l && r <= v)
	{
		long long k = r - l + 1, kk = r + l;
		long long val = (val_b - 2ll*val_a*u%MOD + MOD)%MOD; 
		sg[id] = (sg[id] + val*k%MOD + k*kk%MOD*(1ll*val_a)%MOD)%MOD; 
		lazy1[id] = (lazy1[id] + val)%MOD; lazy2[id] = (lazy2[id] + val_a)%MOD;  
		return;
	}
	dolazy(id, l, r);
	int mid = (l + r)/2;
	update(id*2, l, mid, u, v, val_a, val_b); update(id*2+1, mid + 1, r, u, v, val_a, val_b);
	sg[id] = (sg[id*2] + sg[id*2+1])%MOD;	
}

int get(int id, int l, int r, int u, int v)
{
	if (r < u || l > v) return 0;
	if (u <= l && r <=v)
	{
		return sg[id];
	}
	dolazy(id, l, r);
	int mid = (l + r)/2;
	return (get(id*2, l, mid, u, v) + get(id*2 + 1, mid + 1, r, u, v))%MOD;
}

void solve() 
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	build(1, 1, n);
	while(m--)
	{
		int type;
		cin >> type;
		// cout << type << endl;
		if (type == 1)
		{
			int l, r, u, v;
			cin >> l >> r >> u >> v;
			v += u; v %= MOD;
			update(1, 1, n, l, r, u, v);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			cout << get(1, 1, n, l, r) << "\n";
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
