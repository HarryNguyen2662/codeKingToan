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

int a[100005], c[100005], child[100005];

vector<int> ed[100005];

int dd[100005];
long long dp[100005], fact[100005], infact[100005];

long long power(long long x, long long y)
{
	if (y == 0) return 1;
	long long xx = power(x, y/2);
	if (y%2) return xx*xx%MOD*x%MOD; else return xx*xx%MOD;
}

long long cc(int k, int n)
{
	return fact[n]*infact[k]%MOD*infact[n-k]%MOD;
}

long long cal(int n, int len)
{
	if (len == 0) return 1;
	long long res = 0;
	for (int i = 1; i <= len; i++)
	{
		res = (res + cc(i, n)*cc(i, len)%MOD)%MOD;
	}

	return res;
}

void dfs(int u)
{
	dp[u] = 1; child[u] = 1;
	for (auto v : ed[u])
	{
		dfs(v);

		child[u] += child[v];
		dp[u] = dp[u]*dp[v]%MOD*cc(child[v], child[u] - 1)%MOD;
	}
}

void solve() 
{
	int n;
	cin >> n;
	fact[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		fact[i] = 1ll*i*fact[i-1]%MOD;
	}

	infact[n] = power(fact[n], MOD - 2);
	for (int i = n; i; i--) infact[i-1] = 1ll*i*infact[i]%MOD;

	a[n + 1]  = oo;
	stack<int> st; st.push(n + 1);

	for (int i = n; i; i--)
	{
		while(!st.empty() && a[st.top()] <= a[i]) st.pop();
		c[i] = st.top(); st.push(i);
	
	}
	for (int i = 1; i <= n; i++)
	{
		if (dd[c[i]] == 0)
		{
			ed[c[i]].pb(i);
		}
		else ed[dd[c[i]]].pb(i);
		dd[c[i]] = i;
	}

	for (int i = 1; i <= n; i++)
	{

	}
		
	dfs(n + 1);
	cout << dp[n + 1];
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
