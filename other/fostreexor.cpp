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

long long res = 0;
int L, R;
bool visit[100005];
vector<int> ed[100005];

//trie
struct Trie
{
	int child[2], pass;
	Trie() { child[0] = child[1] = 0; pass = 0;}
};

Trie node[3100005];
int nuchild_trie = 1;

void reset(int root)
{
	for (int i = 1; i <= nuchild_trie; i++)
	{
		node[i].child[0] = node[i].child[1] = node[i].pass = 0;
	}
	nuchild_trie = 1;
}
void insert(int val)
{
	int root = 1;
	for (int i = 29; i >= 0; i--)
	{
	
		int bit = ck(val, i);
		if (node[root].child[bit] == 0) node[root].child[bit] = ++nuchild_trie;
		root = node[root].child[bit]; node[root].pass++;

	} 
}

void cal_LR(int val)
{
	int rootL = 1, rootR = 1;
	for (int i = 29; i >= 0; i--)
	{

		int bit = ck(val, i), bitL = ck(L, i), bitR = ck(R, i);

		if (bitL && node[rootL].child[bit]) res -= node[node[rootL].child[bit]].pass;
		if (bitR && node[rootR].child[bit]) res += node[node[rootR].child[bit]].pass;

		if (node[rootL].child[(bit^bitL)]) rootL = node[rootL].child[(bit^bitL)]; else rootL = 0;
		if (node[rootR].child[(bit^bitR)]) rootR = node[rootR].child[(bit^bitR)]; else rootR = 0;

	}
	//cout << rootR << endl;
	res += node[rootR].pass;
}


int val[100005], sz[100005], mxchild[100005];

void calsize(int u)
{
	visit[u] = true;
	sz[u] = 1;
	mxchild[u] = 0;

	for (auto v : ed[u])
	if (visit[v] == false)
	{
		calsize(v);
		if (sz[v] > sz[mxchild[u]]) mxchild[u] = v;
		sz[u] += sz[v];
	}

	visit[u] = false;
}

//centroid
int findnode(int u)
{
	int num_child = sz[u]/2;
	while(sz[mxchild[u]] > num_child) u = mxchild[u];
	return u;
}

void dfs1(int u, int val_cur)
{
	visit[u] = true;
	val_cur ^= val[u];
	cal_LR(val_cur);
	
	for (auto v : ed[u]) 
	if (visit[v] == false)
	{
		dfs1(v, val_cur);
	}

	visit[u] = false;
}

void dfs2(int u, int val_cur)
{
	visit[u] = true;
	val_cur ^= val[u];
	insert(val_cur);

	for (auto v : ed[u])
	if (visit[v] == false)
	{
		dfs2(v, val_cur);
	}
	visit[u] = false;
}

void build_centree(int u)
{
	calsize(u);
	u = findnode(u);
	//cout << L << R << endl;
	
	visit[u] = true;
	
	res += (val[u] >= L && val[u] <= R);
	
	insert(val[u]);
	
	for (auto v : ed[u]) if (visit[v] == false)
	{
		dfs1(v, 0); dfs2(v, val[u]);
	}
	
	reset(1);

	for (auto v : ed[u]) if (visit[v] == false) build_centree(v);
}

void solve() 
{
	int n;
	cin >> n >> L >> R;


	for (int i = 1; i <= n; i++)
	{
		cin >> val[i];
	}

	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		ed[u].pb(v); ed[v].pb(u);
	}

	calsize(1);
	build_centree(1);

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
