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
multiset<int> seg[400005];
void build(int id, int l, int r)
{
	if (l == r)
	{
		seg[id].insert(a[l]);
		return;
	}
	int mid = (l + r)/2;
	build(id*2, l, mid); build(id*2+1, mid + 1 , r);
	for (auto v : seg[id*2]) seg[id].insert(v); 
	for (auto v : seg[id*2+1]) seg[id].insert(v);
}
void update(int id, int l, int r, int vt, int val)
{
	if (l > vt || r < vt) return;
	seg[id].erase(seg[id].find(a[vt])); seg[id].insert(val);
	if (l == r) return;
	int mid = (l + r)/2;
	update(id*2, l, mid, vt, val); update(id*2+1, mid + 1, r, vt, val);
}
int get(int id, int l, int r, int u, int v, int val)
{
	if (l > v || r < u) return - 1;
	if (u <= l && r <= v)
	{
		auto v  = seg[id].lower_bound(val); 
		return (v == seg[id].end()) ? -1 : *v;
	}
	int mid = (l + r)/2;
	int res1 = get(id*2, l , mid, u, v, val); 
	int res2 = get(id*2+1, mid + 1, r, u, v, val);
	if (res1 != -1 && res2 != -1) return min(res1, res2);
	else if (res1 != -1) return res1; else return res2;
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
			int x, y;
			cin >> x >> y;
			update(1, 1, n, x, y);
			a[x] = y;
		}
		else
		{
			int x, y, so;
			cin >> x >> y >> so;
			cout << get(1, 1, n, x, y, so) << "\n";
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
