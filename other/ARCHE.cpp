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
	int ver1, ver2, va;
};
int n, m, par[100005], dd[100005];
vector<DATA> edge;
//map<int, bool> ban[100005];
vector<pair<int,int> > ldk;
int findpar(int u)
{
	return par[u] < 0 ? u : par[u] = findpar(par[u]);
}
void merge(int u, int v)
{
	if (u == v) return;
	if (par[u] > par[v]) swap(u, v);
	//if (dd[v]) dd[u] = dd[v];
	par[u] += par[v];
	par[v] = u;
}
bool check(int val)
{
	for (int i = 1; i <= n; i++)
	{ 
		par[i] = -1;
		//if (dd[i] != i) dd[i] = 0;
	}
	for (auto v : edge) if (v.va > val) 
	{
		int u = findpar(v.ver1), vv = findpar(v.ver2);
		//if (ban[dd[u]][dd[vv]]) return false;
		merge(u, vv);
	}
	for (auto v : ldk)
	{
		int u = findpar(v.fi), vv = findpar(v.se);
		if (u == vv) return false;
	}
	return true;
}
void solve() 
{
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, val;
		cin >> u >> v >> val;
		if (val == -1)
		{
			if (u == v)
			{
				cout << -1;
				return;
			}
			ldk.pb({u, v});
		 	//ban[u][v] = ban[v][u] = true, dd[u] = u, dd[v] = v;
		}
		else edge.pb({u, v, val});
	}
	int l = 0, r = oo;
	if (check(oo) == false)
	{
		cout << -1;
		return;
	}
	while (l <= r)
	{
		int mid = (l + r)/2;
		if (check(mid)) r = mid - 1; else l = mid + 1;
	}
	cout << l;
}	

int main() 
{   
    freopen("ARCHE.inp","r",stdin); freopen("ARCHE.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
