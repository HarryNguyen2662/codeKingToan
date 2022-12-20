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

int low[2000005], num[2000005], cnt = 0, tplt = 0, ans[2000005];
stack<int> st;
vector<int> a[2000005];
void dfs(int u)
{
    st.push(u);
    low[u] = num[u] = ++cnt;
    for (auto v : a[u])
    if (num[v] > 0) low[u] = min(low[u], num[v]);
    else if (num[v] == 0)
    {
        dfs(v);
        if (low[v] > 0)
        low[u] = min(low[u], low[v]);
    }
    if (low[u] == num[u])
    {
        tplt++;
        while(true)
        {
            int v = st.top(); st.pop();
            low[v] = num[v] = -tplt;
            if (v == u) break;
        }
    }
}

void solve() 
{
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= q; i++)
	{
		int u, v, k;
		cin >> u >> v >> k;
		if (k)
		{
			a[u + n].pb(v); a[v + n].pb(u);
			a[u].pb(v + n); a[v].pb(u + n);
		}
		else
		{
			a[u + n].pb(v + n); a[v].pb(u);
			a[u].pb(v); a[v + n].pb(u + n);
		}
	}
	for (int i = 1; i <= 2*n; i++) if (num[i] == 0) dfs(i);
	for (int i = 1; i <= n; i++)
	{
		if (num[i] == num[i+n])
		{
			cout << -1;
			return;
		}
		else if (num[i] > num[i+n]) ans[i] = 2; else ans[i] = 1;
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
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
