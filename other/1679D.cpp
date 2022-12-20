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

vector<int> a[200005];
long long aa[200005];
int low[200005], num[200005], dp[200005], cnt = 0, tplt = 0;
stack<int> st;
void dfs(int u, long long val)
{
	st.push(u);
	dp[u] = 1;
	low[u] = num[u] = ++cnt;
	for (auto v : a[u])
	if (aa[v] <= val)
	{
		if (num[v]) low[u] = min(low[u], num[v]);
		else{
			dfs(v, val);
			low[u] = min(low[u], low[v]);
		}
		dp[u] = max(dp[u], dp[v] + 1);
	}
	if (low[u] == num[u])
	{
		tplt++;	
		while(true)
		{
			int v = st.top(); st.pop();
			low[v] = num[v] = oo;
			if (u == v) break;
		}
	}
}

int n, m;
long long k;
bool check(long long val)
{
	int dem = 0;
	tplt = 0; cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (aa[i] <= val) dem ++;
		dp[i] = low[i] = num[i] = 0;
	}
	int mxlen = 0;
	for (int i = 1; i <= n; i++) if (num[i] == 0 && aa[i] <= val)
	{
		dfs(i, val);
		mxlen = max(mxlen, dp[i]);
	}
	//cout << tplt << " " << n << endl;
	if (tplt == dem)
	{
		if (mxlen >= k) return true; 
		return false;
	}
	else return true;
}
void solve() 
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> aa[i];
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v);
	}
	long long l = 1, r = oo;
	//cout << check(1) << endl;
	while(l <= r)
	{
		long long  mid = (l + r)/2;
		if (check(mid)) r = mid - 1; else l = mid + 1;
	}
	if (l > oo)
	{
		cout << -1;
		return;
	}
	cout << l;
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
