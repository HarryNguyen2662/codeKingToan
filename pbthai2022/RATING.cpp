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

vector<int> a[100005], aa[100005];
pair<int,int> va[100005];
int cnt = 0, tplt = 0, num[100005], low[100005], dp[100005], cs[100005], cost[100005];
stack<int> st;

void tarjan(int u)
{
	//cout << u << endl;
	num[u] = low[u] = ++cnt;
	st.push(u);
	for (auto v : a[u]) 
	if (num[v] > 0)
	{
		low[u] = min(low[u], num[v]);
	}
	else if (num[v] == 0)
	{
		tarjan(v);
		if (low[v] > 0)
		low[u] = min(low[u], low[v]);
	}

	if (low[u] == num[u])
	{
		//cout << u << endl;
		tplt++;
		while(true)
		{
			int v = st.top(); st.pop();
			//cout << v << endl;
			cost[tplt]++;
			num[v] = low[v] = -tplt;
			if (v == u) break;
		}
	}
}

void dfs(int u)
{
	dp[u] += cost[u];
	int mx = 0;

	for (auto v : aa[u])
	{
		if (dp[v] == 0) dfs(v);
		mx = max(mx, dp[v]);
	}
	dp[u] += mx;
}

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> va[i].fi >> va[i].se;
		cs[i] = i;
	}

	sort(cs + 1, cs + 1 + n, [](const int &x, const int &y)
	{
		return va[x].fi < va[y].fi;
	});

	int id = cs[1];
	for (int i = 2; i <= n; i++)
	{
		a[cs[i]].pb(cs[i-1]);
		if (va[id].se < va[cs[i]].se) id = cs[i];
	}

	sort(cs + 1, cs + 1 + n, [](const int &x, const int &y)
	{
		return va[x].se < va[y].se;
	});

	id = cs[1];
	for (int i = 2; i <= n; i++)
	{
		a[cs[i]].pb(cs[i-1]);
		if (va[id].fi < va[cs[i]].fi) id = cs[i];
	}
	for (int i = 1; i <= n; i++) if (num[i] == 0) tarjan(i);
//	for (int i = 1; i <= n; i++)  for (auto v : a[i]) cout <<i << " " << v << endl;

	for (int i = 1; i <= n; i++) for (auto v : a[i])
	if (num[i] != num[v])
	{
//		cout << -num[i] << " " << -num[v] << endl;
		aa[-num[i]].pb(-num[v]);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(ALL(aa[i])); aa[i].resize(unique(ALL(aa[i])) - aa[i].begin());
	}

	//for (int i = 1; i <= tplt; i++) for (auto v : aa[i]) cout << i << " " << v << endl; 

	for (int i = 1; i <= tplt; i++) if (dp[i] == 0) dfs(i);

	for (int i = 1; i <= n; i++) cout << dp[-num[i]] - 1 << "\n";


}

int main() 
{   
  	#ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
