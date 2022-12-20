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
bool con[1005][1005], dd[1005], block[1005];
vector<int> a[1005], aa[1005];
int ined[1005], res[1005];
void dfs(int root, int u)
{
	con[root][u] = true;
	for (auto v : a[u])
	if (!con[root][v]) 
	{
		//if (root == 1) aa[u].pb(v), ined[v]++;
		dfs(root, v);
	}
}
void dfs1(int u)
{
	dd[u] = true;
	for (auto v : a[u])
	if (!dd[v] && !block[v])
	dfs1(v);
}
void solve() 
{
	int n, m;
	vector<pair<int,int>> ldk;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		if (u == v) continue;
		a[u].pb(v);
		ldk.pb({u, v});
	}
	for (int i = 1; i <= n; i++) dfs(i, i);
	int dem = 0;
	for (int i = 1; i <= n; i++) if (con[1][i]) dem++;
	for (auto v : ldk)
	if (con[1][v.fi] && con[1][v.se])
	{
		block[v.se] = true;
		for (int i = 1; i <= n; i++) dd[i] = false;
		if (v.se != 1)
		dfs1(1);
		if (dd[v.fi]) aa[v.fi].pb(v.se), ined[v.se]++;
		else if (con[v.se][v.fi]) aa[v.se].pb(v.fi), ined[v.fi]++;
		block[v.se] = false;
	}
	vector<int> topo;
	queue<int> list;
	list.push(1);
	//for (int i = 1; i <= n; i++) for (auto v : aa[i]) cout << i << " " << v << endl;
	//cout << endl;
	while(!list.empty())
	{
		int u = list.front(); list.pop();
		topo.pb(u);
		for (auto v : aa[u])
		{
			ined[v]--;
			//cout << u << " " << v << endl;
			if (ined[v] == 0) list.push(v);
		}
	}
	//cout << dem << " " << topo.size() << endl;
	if ((int)topo.size() != dem)
	{
		cout << -1;
		return;
	}
	int cnt = 0;
	for (auto v : topo) res[v] = ++cnt;
	for (int i = 1; i <= n; i++) if (res[i]) cout << res[i] << " ";
	else 
	{
		cnt++; cout << cnt << " ";
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
