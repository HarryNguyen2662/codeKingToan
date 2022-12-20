#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
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

struct Query
{
	string type; int x, y;
}query[200005];

struct Trie
{
	Trie *child[2]; 
	set<int> pass;

	Trie()
	{
		child[0] = child[1] = NULL;
	}
} root;

int cnt = 0, ed[200005], st[200005], f[200005], ans[200005], cmt = 1;

vector<pair<int,int>> a[200005];

void add(int id)
{
	Trie *p = &root;
	for (int i = 30; i >= 0; i--)
	{
		int cur = ck(f[id], i);

		if (p->child[cur] == NULL) p->child[cur] = new Trie();

		p = p->child[cur]; 

		p->pass.insert(st[id]);
	}
}

int find(int val, int l, int r)
{
	int res = 0;
	Trie *p = &root;
	for (int i = 30; i >= 0; i--)
	{
		int cur = ck(val, i);

		if (p->child[1 - cur])
		{
			Trie *np1 = p->child[1 - cur];
			auto w = np1->pass.lower_bound(l);
			if (w != np1->pass.end() && *w <= r)
			{
				res += mask(i);
				p = np1;
			}
			else p = p->child[cur];

		}
		else p = p->child[cur];
	}

	return res;
}

void dfs(int u)
{
	st[u] = ++cnt;

	for (auto v : a[u]) 
	{
		f[v.fi] = f[u]^v.se;
		dfs(v.fi);
	}

	ed[u] = cnt;
}

void solve() 
{
	int n;
	cin >> n;

	int vex = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> query[i].type >> query[i].x >> query[i].y;
		if (query[i].type == "Add")
		{
			vex++;
			a[query[i].x].pb({vex, query[i].y});
		}
	}

	dfs(1);

 	add(1);
	vex = 1;
	for (int i = 1; i <= n; i++)
	if (query[i].type == "Add")
	{
		vex++;
		add(vex);
	}
	else
	{
		cout << find(f[query[i].x], st[query[i].y], ed[query[i].y]) << "\n";
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