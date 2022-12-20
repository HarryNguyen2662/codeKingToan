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

bool c[105], vit[10005], dd[10005];
int num[10005], low[1005], cnt = 0, dist[1005];
vector<int> a[105], aa[10005];
stack<int> st;

void tarjan(int u)
{
	st.push(u);
	num[u] = low[u] = ++cnt;

	for (auto v : aa[u])
	{
		if (num[v]) low[u] = min(low[u], num[v]);
		else
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
	}

	if (low[u] == num[u])
	{
		if (st.top() == u) dd[u] = true;
		while(true)
		{
			int v = st.top(); st.pop();
			num[v] = low[v] = oo;
			if (v == u) break;
		}

	}

}

void dfs(int u)
{
	vit[u] = true;
	if (dist[u]) return;
	for (auto v : aa[u]) if (dd[v] == true)
	{
		cout << u << " " << v << endl; 
		if (vit[v] == false) dfs(v);
		dist[u] = max(dist[u], dist[v]);
	}

	if (dist[u]) dist[u]++; else dist[u] = oo;
}

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			bool kt;
			cin >> kt;
			if (kt) a[i].pb(j);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (auto v : a[i]) for (auto vv : a[v])
		{
			aa[vv].pb(i);
		}
		
	}

	for (int i = 1; i <= n*n; i++) for (auto v : aa[i]) cout << i << " " << v << endl;
	cout << endl;

	for (int i = 1; i <= n*n; i++) if (num[i] == 0 && dd[i] == false) tarjan(i);

	for (int i = 1; i <= n*n; i++) if (vit[i] == false && dd[i]) dfs(i);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << ((dist[(i-1)*n + j] < oo) ? dist[(i-1)*n + j] - 1 : -1)<< " ";
		}
		cout << "\n";
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
