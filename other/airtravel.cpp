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
vector<int> a[100005], aa[100005], iaa[100005];
int cnt = 0, tplt;
int num[100005], low[100005], id[100005], val[100005], dp[100005][2];
stack<int> st;
void tarjan(int u)
{
	st.push(u);
	num[u] = low[u] = ++cnt;
	for (auto v : a[u])
	if (num[v] > 0) low[u] = min(low[u], num[v]);
	else 
	{
		tarjan(v);
		low[u] = min(low[u], low[v]);
	}
	if (low[u] == num[u])
	{
		tplt++;
		while(true)
		{
			int v = st.top(); st.pop();
			val[tplt]++;
			id[v] = tplt;
			low[v] = num[v] = oo;
			if (v == u) break;
		}
	}
}
void solve() 
{
	vector<pair<int,int>> ldk;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		ldk.pb({u, v});
		a[u].pb(v);
	}
	for (int i = 1; i <= n; i++) if (num[i] == 0) tarjan(i);
	for (auto v : ldk)
	{
		int uu = id[v.fi], vv = id[v.se];
		if (uu != vv) aa[uu].pb(vv), iaa[vv].pb(uu);
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	dp[id[1]][0] = dp[id[1]][1] = val[id[1]];	
	pq.push({val[id[1]], id[1]});
	while(!pq.empty())
	{
		int u = pq.top().se, ts = pq.top().fi; pq.pop();
		if (dp[u][0] != ts) continue;
		for (auto v : aa[u])
		if (dp[v][0] < ts + val[v])
		{
			dp[v][0] = ts + val[v];
			pq.push({dp[v][0], v});
		}
	}
	pq.push({val[id[1]], id[1]});
	while(!pq.empty())
	{
		int u = pq.top().se, ts = pq.top().fi; pq.pop();
		if (dp[u][1] != ts) continue;
		for (auto v : iaa[u])
		if (dp[v][1] < ts + val[v])
		{
			dp[v][1] = ts + val[v];
			pq.push({dp[v][1], v});
		}
	}
	int res = val[id[1]];
	for (auto v : ldk)
	{
		int uu = id[v.fi], vv = id[v.se];
		if (uu == vv) continue;
		if (dp[uu][0] && dp[vv][1]) res = max(res, dp[uu][0]+ dp[vv][1]);
		if (dp[uu][1] && dp[vv][0]) res = max(res, dp[uu][1]+ dp[vv][0]);
	}
	cout << res - val[id[1]];
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
