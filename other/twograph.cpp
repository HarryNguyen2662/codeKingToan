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
struct graph
{
	int ver1, ver2, weight;
	bool type;
	bool operator  < (const graph &other) const
	{
		return weight < other.weight;
	}
};
class disjointsetunion
{

	vector<int> par;
public:
	void setup(int n)
	{
		par.assign(n + 5, -1);
	}
	int findpar(int u)
	{
		return par[u] < 0 ? u : par[u] = findpar(par[u]);
	}
	bool merge(int u, int v)
	{
		u = findpar(u); v = findpar(v);
		if (u == v) return false;
		if (par[u] > par[v]) swap(u, v);
		par[u] += par[v];
		par[v] = u;
		return true;
	}
	int gpar(int u)
	{
		return par[u];
	}
};
void solve() 
{
	int n, m;
	vector<graph> ldk, qa;
	disjointsetunion dsu1, dsu2;
	
	n = ReadInt(); m = ReadInt();

	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		u = ReadInt(); v = ReadInt(); w = ReadInt();
		ldk.pb({u, v, w, 0});
	}
	sort(ldk.begin(), ldk.end());
	
	int nn, mm;
	nn = ReadInt(); mm = ReadInt();

	for (int i = 1; i <= mm; i++)
	{
		int u, v, w;
		u = ReadInt(); v = ReadInt(); w = ReadInt();
		ldk.pb({u, v, w, 1});
	}
	
	long long res = 0;
	sort(ALL(ldk));
	dsu1.setup(n); dsu2.setup(nn);
	for (auto v : ldk)
	if (v.type == 0)
	{
		if (dsu1.merge(v.ver1, v.ver2)) res = res + 1ll*v.weight*nn, n--;
	}
	else
	{
		if (dsu2.merge(v.ver1, v.ver2)) res = res + 1ll*v.weight*n, nn--;
	}
	if (n != 1 || nn != 1)
	{
		cout << "-1";
		return;
	}
	cout << res;
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
