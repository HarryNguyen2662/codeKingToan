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

typedef long long ll;
struct Dinitz {
	struct Edges {
		int u, v;
		ll cap;

		Edges() : u(), v(), cap() {}
		Edges(int _u, int _v, ll _cap) : u(_u), v(_v), cap(_cap) {}
	};

	vector<vector<int>> g;
	vector<Edges> ed;
	vector<int> dist;
	vector<int> id;
	int S, T;
	int n;

	Dinitz() : ed(), n(), S(), T() {}
	Dinitz(int _n, int _S, int _T) {
		n = _n; S = _S; T = _T;
		g.resize(n);
		dist.resize(n);
		id.resize(n);
		for(int i = 0; i < n; i++) g[i].clear();
		ed = vector<Edges>();
	}

	void addEdge(int u, int v, ll cap) {
		g[u].pb((int)ed.size());
		ed.pb(Edges(u, v, cap));
		g[v].pb((int)ed.size());
		ed.pb(Edges(v, u, 0));
	}

	bool bfs() {
		for(int i = 0; i < n; i++) dist[i] = n + 5;
		queue<int> q;
		q.push(S); dist[S] = 0;
		while(!q.empty()) {
			int u = q.front(); q.pop();
			for(int i : g[u]) {
				Edges e = ed[i];
				if(!e.cap) continue;
				if(dist[e.v] <= dist[u] + 1) continue;
				dist[e.v] = dist[u] + 1;
				q.push(e.v);
			}
		}

		return dist[T] < n + 5;
	}

	ll dfs(int u, ll flow) {
		if(u == T || flow == 0) return flow;

		ll ans = 0;
		for(int &i = id[u]; i < (int)g[u].size(); i++) {
			Edges e = ed[g[u][i]];
			if(!e.cap) continue;
			if(dist[e.v] != dist[u] + 1) continue;
			ll f = dfs(e.v, min(flow, e.cap));
			flow -= f;
			ans += f;
			ed[g[u][i]].cap -= f;
			ed[g[u][i] ^ 1].cap += f;
			if(flow == 0) return ans;
		}

		return ans;
	}

	ll Flow() {
		ll ans = 0;
		while(bfs()) {
			for(int i = 0; i < n; i++) id[i] = 0;
			ans += dfs(S, oo);
		}

		return ans;
	}
};
struct Trie
{	
	int child[2];
	Trie()
	{
		child[0] = child[1] = 0;
	}
} node[5005];

int numcnt = 1, S, T, f[3505][3505], c[3505][3505], visit[5005], dist[5005], luu[5005], dem = 0, lu[5005];
vector<int> a[5005];
void add(const string &s, int cost, int id)
{
	int p = S;
	for (int i = 0; i < (int)s.size(); i++)
	{
		int x = s[i] - '0';
		if (node[p].child[x] == 0) 
		{
			if (!id) return;
			node[p].child[x] = ++numcnt;
			a[p].pb(numcnt); //a[numcnt].pb(p); 
		}
		int w = node[p].child[x];
		if (i  + 1 == (int)s.size()) 
		{
			//cout << cost << endl;
			if (!f[p][w]) f[p][w] = cost; else f[p][w] = min(f[p][w], cost);  
			
		}
		else
		{
			if (f[p][w]) f[p][w] = min(f[p][w], oo); 
			else f[p][w] = oo;	
		}
		p = node[p].child[x];
	}
	if (id)
	{
		luu[id] = p;
	}
}

void add1(const string &s, int cost, int id)
{
	int p = T;
	for (int i = (int)s.size() - 1; i >= 0 ; i--)
	{
		int x = s[i] - '0';
		int w;
		if (node[p].child[x] == 0) 
		{

			if (!id) return;
			
				w = ++numcnt;
				node[p].child[x] = w;	
			//a[.pb(w); 
				a[w].pb(p); 
		} else w = node[p].child[x];
		
		if (i == 0) 
		{
			//cout << cost <<  " " << w << " " << p << endl;
			if (!f[w][p]) f[w][p] = cost; else f[w][p] = min(f[w][p], cost);  
			
		}
		else
		{
			if (f[w][p]) f[w][p] = min(f[w][p], oo); 
			else f[w][p] = oo; 

		}
		p = node[p].child[x];
	}
	if (id) lu[id] = p;
}
string s[1005];
void solve() 
{
	int n;
	cin >> n;
	vector<pair<string, int>> ldk;
	S = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		//while((int)s[i].size() <= 20) s[i] += '0';
		add(s[i], oo, i);
	}

	int m;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int type;  string ss; int cost;
		cin >> type >> ss >> cost;
		if (type == 1)
		{
			//while((int)ss.size() <= 20) ss += '0';
			add(ss, cost, 0);
		}
		else
		{
			//while((int)ss.size() <= 20) ss = '0' + ss; 
			ldk.pb({ss, cost});
		}
	}
	T = ++numcnt;
	//cout << T << endl;
	//cout << n << endl;
	for (int i = 1; i <= n; i++) add1(s[i], oo, i);
	for (auto v : ldk) add1(v.fi, v.se, 0);

	Dinitz dk = Dinitz(numcnt + 10, S, T);

	int res = 0;
	//cout << numcnt << endl;
	for (int i = 1; i <= numcnt; i++) 
	{
		for (auto v : a[i]) dk.addEdge(i, v, f[i][v]);
		//cout << endl;
	}
	//assert(numcnt <= 450);
	for (int i = 1; i <= n; i++)
	{
		dk.addEdge(luu[i], lu[i], oo);
	}
	

	res =  dk.Flow();
	if (res >= oo) cout << -1; else cout << res; 

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
