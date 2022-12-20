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

long long lazy[400005], sg[400005], a[100005];

void dolazy(int id, int l, int mid, int r)
{
	long long &val = lazy[id];

	if (val == -1) return;

	sg[id*2] = 1ll*(mid - l + 1)*val; lazy[id*2] = val;
	sg[id*2+1] = 1ll*(r - mid)*val; lazy[id*2+1] = val;

	val = -1;
}

void build(int id, int l, int r)
{
	lazy[id] = -1;
	if (l == r)
	{
		sg[id] = a[l];
		return;
	}
	int mid = (l + r)/2;

	build(id*2, l, mid); build(id*2+1, mid + 1, r);

	sg[id] = sg[id*2] + sg[id*2+1];
}

void update(int id, int l, int r, int u, int v, long long val)
{
	if (l > v || r < u) return;

	if (u <= l && r <= v)
	{ 
		sg[id] = 1ll*(r - l + 1)*val;
		lazy[id] = val;
		return;
	}

	int mid = (l + r)/2;

	dolazy(id, l, mid, r);

	update(id*2, l, mid, u, v, val); update(id*2 + 1, mid + 1, r, u, v, val);

	sg[id] = sg[id*2] + sg[id*2+1];
}

long long get(int id, int l, int r, int u, int v)
{	
	if (l > v || r < u) return 0;

	if (u <= l && r <= v)
	{
		return sg[id];
	}

	int mid = (l + r)/2;

	dolazy(id, l, mid, r);

	return get(id*2, l, mid, u, v) + get(id*2+1, mid + 1, r, u, v);
}	

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	build(1, 1, n);

	int q;
	cin >> q;
	while(q--)
	{
		int id, L;
		cin >> id >> L;

		long long cur = get(1, 1, n, id, id);
		long long w = get(1, 1, n, id + 1, id + L) ;
		cout << w - 1ll*L*cur << "\n";
		update(1, 1, n, id + 1, id + L, cur);
	}
	//cout << get(1, 1, n, 2, 3) << endl;
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
