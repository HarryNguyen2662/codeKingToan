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


int a[100005];
multiset<int> sg[400005];

void build(int id, int l, int r)
{
	if (l == r)
	{
		sg[id].insert(a[l]);
		return;
	}
	int mid = (l + r)/2;

	build(id*2, l, mid); build(id*2+1, mid + 1, r);

	for (auto v : sg[id*2]) sg[id].insert(v); 
	for (auto v : sg[id*2+1]) sg[id].insert(v); 
}

void update(int id, int l, int r, int vt, int val)
{
	if (r < vt || l > vt) return;
	sg[id].insert(val);
	sg[id].erase(sg[id].find(a[vt]));
	if (l == r) return;
	
	int mid = (l + r)/2;

	if (vt <= mid) update(id*2, l, mid, vt, val);
	else update(id*2+1, mid + 1, r, vt, val);

}

int get1(int id, int l, int r, int u, int v, int val)
{
	if (r < u || l > v) return oo;
	if (u <= l && r <= v)
	{
		auto w = sg[id].lower_bound(val);
		if (w == sg[id].end()) return oo; 
		else return *w;
	}
	int mid = (l + r)/2;

	return min(get1(id*2, l, mid, u, v, val) , get1(id*2+1, mid + 1, r, u, v, val));
}

int get2(int id, int l, int r, int u, int v, int val)
{
	if (r < u || l > v) return -1;
	if (u <= l && r <= v)
	{
		auto w = sg[id].upper_bound(val);
		if (w == sg[id].begin()) return -1; 
		else 
		{
			w--;
			return *w;
		}
	}
	int mid = (l + r)/2;

	return max(get2(id*2, l, mid, u, v, val) , get2(id*2+1, mid + 1, r, u, v, val));
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
		if (type == 1)
		{
			int id, val;
			cin >> id >> val;
			update(1, 1, n, id, val);
			a[id] = val;
		}
		else 
		{
			int l, r, val;
			cin >> l >> r >> val;
			int res = 0;
			if (type == 2) res = get1(1, 1, n, l, r, val);
			else res = get2(1, 1, n, l, r, val);
			if (res == oo) res = -1;
			cout << res << "\n";
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
