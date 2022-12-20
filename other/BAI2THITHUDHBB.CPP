#include<bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define fi first
#define se second
#define pb push_back
#define endl "\n"

const int limit = 4e5 + 5;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef long long ll;

ll a[20];
ll low[limit], num[limit];
ll id = 0, bridges = 0;
map <ll, bool> bridge[limit];
vi g[limit], g1[limit];
pii edge[limit];
ll root[2][limit];
ll node[limit];
ll flag[limit], flag1[limit];
ll n, m;
int parent[limit];
int child[limit];
int roots[limit];
bool visit[limit];
int childs[limit];

ll findRoot(ll u, ll type) {
	return (root[type][u] < 0) ? u : root[type][u] = findRoot(root[type][u], type);	
}

bool mergeRoot(ll u, ll v, ll type) {
	u = findRoot(u,type);
	v = findRoot(v, type);

	if (u == v) return false;
	if (root[type][u] > root[type][v]) swap(u, v);

	root[type][u] += root[type][v];
	root[type][v] = u;
	return true;
}

void dfs(ll u, ll par) {
	low[u] = num[u] = ++id;

	for (auto v : g[u]) {
		if (v != par) {
			if (num[v]) low[u] = min(low[u], num[v]);
			else {
				dfs(v, u);
				low[u] = min(low[u], low[v]);

				if (low[v] >= num[v]) {
					bridge[u][v] = bridge[v][u] = true;
					++bridges;
				}	
			}
		}
	}
}

void dfs2(int u, int root) {
	roots[u] = root;
	visit[u] = true;
	child[u] = childs[u];

	for (auto v : g1[u]) {
		if (!visit[v]) {
			dfs2(v, root);
			parent[v] = u;
			child[u] += child[v];
		}
	}
}

void solve() {
	memset(root, -1, sizeof(root));
	REP(i, 1, n) {
		if (!num[i]) dfs(i, i);
	}

	REP(i, 1, m) {
		ll u = edge[i].fi, v = edge[i].se;
		if (!bridge[u][v]) {
			mergeRoot(u, v, 0);
		}

		mergeRoot(u, v, 1);
	}

	int curNode = n;
	vi tmp; ll cnt = 0;
	REP(i, 1, n) {
		ll anc = findRoot(i, 1);
		if (!flag[anc]) {
			++cnt;
			flag[anc] = i;
			tmp.pb(anc);
		}

		anc = findRoot(i, 0);
		if (!flag1[anc]) {
			node[anc] = ++curNode;
			++childs[curNode];
			flag1[anc] = i; 
		}

		else {
			++childs[node[anc]];
		}
	}

	REP(i, 1, m) {
		int u = edge[i].fi, v = edge[i].se;
		if (bridge[u][v]) {
			g1[node[findRoot(u, 0)]].pb(node[findRoot(v, 0)]);
			g1[node[findRoot(v, 0)]].pb(node[findRoot(u, 0)]);
			// cout << node[findRoot(u, 0)] << " " << node[findRoot(v, 0)] << endl;
			// cout << childs[node[findRoot(u, 0)]] << " " << childs[node[findRoot(v, 0)]] << endl; 
		}
	}

	REP(i, 1, n) {
		if (!visit[node[findRoot(i, 0)]]) {
			dfs2(node[findRoot(i, 0)], node[findRoot(i, 0)]);
		}
	}

	ll ans = 0;
	REP(i, 1, m) {
		ll u = edge[i].fi, v = edge[i].se;
		if (bridge[u][v] && cnt == 1) {
			int ancU = findRoot(u, 0), ancV = findRoot(v, 0);
			if (parent[node[ancU]] == node[ancV]) swap(ancU, ancV);
			int sumChild = child[roots[node[ancU]]];

			ans += 1LL * (sumChild - child[node[ancV]]) * child[node[ancV]] - 1;
			// cout << 
			// cout << child[node[ancV]] << " " << sumChild - child[node[ancV]] << " " << u << " " << v << endl;
		}

		else if (!bridge[u][v]) {
			if (cnt == 2)
			{
				ll a = -root[1][findRoot(tmp[0], 1)];
				ll b = -root[1][findRoot(tmp[1], 1)];

				ans += 1LL * a * b;
			}

			else if (cnt == 1) {
				ans += 1LL * n * (n - 1) / 2 - m;
				// cout << 1LL * n * (n - 1) / 2 - m << endl;
			}
		}
	}

	cout << ans << endl;
}

void LannaykoACdamchetmemay() {

}

void DeRacVaiCaCuc() {

}

int main()
{
    // freopen("hellodking.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n>> m;

    REP(i, 1, m) {
    	ll u, v;
    	cin >> u >> v;
    	g[u].pb(v);
    	g[v].pb(u);
    	edge[i] = {u, v};
    }

    solve();
    LannaykoACdamchetmemay();
    DeRacVaiCaCuc();
}