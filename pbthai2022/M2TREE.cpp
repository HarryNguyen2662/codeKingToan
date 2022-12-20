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

ll ans[100005], add[100005], f[100005], du[100005];
int par[100005], last[100005], suf[100005], p[100005], lu[100005];

int findpar(int u)
{
	return par[u] < 0 ? u : par[u] = findpar(par[u]);
}
void merge(int u, int v, int val)
{
	u = findpar(u); v = findpar(v);
	if (par[u] > par[v]) swap(u, v);
	suf[last[u]] = v;
	add[last[u]] = val;
	last[u] = last[v];
	par[u] += par[v];
	par[v] = u;
}

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		par[i] = -1;
		last[i] = i;
		suf[i] = -1;
		if (i > 1)
		cin >> p[i];
	}


	vector<pair<ll,pair<int,int>>> ldk;

	for (int i = 1; i <= n; i++)
	{
		cin >> du[i];
	}

	for (int i = 2; i <= n; i++) ldk.pb({min(du[p[i]], du[i]), {p[i], i}});

	sort(ALL(ldk)); reverse(ALL(ldk));

	for (auto v : ldk) 
	{
		merge(v.se.fi, v.se.se, v.fi);
	}

	int nn = 0;
	for (int i = findpar(1); i != -1; i = suf[i])
	{
		lu[++nn] = i; 

		//cout << i << " " << add[i] << endl;
	}
	add[lu[nn]] = 0;

	stack<int> st;
	for (int i = 1; i <= nn; i++)
	{
		int cur = 0;
		while(!st.empty() && add[lu[st.top()]] >= add[lu[i]]) st.pop();
		if (!st.empty()) cur = st.top(); st.push(i);
		f[i] = f[cur] + 1ll*(i - cur)*add[lu[i]];
		ans[lu[i + 1]] += f[i];
	}
//	cout << endl;
	//cout << ans[4] << endl;

	while(!st.empty()) st.pop();

	for(int i = nn; i; i--)
	{
		int cur = nn + 1;
		while(!st.empty() && add[lu[st.top()]] >= add[lu[i]]) st.pop();
		if (!st.empty()) cur = st.top(); st.push(i);
		f[i] = f[cur] + 1ll*(cur - i)*add[lu[i]];
		ans[lu[i]] += f[i];
	}

	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] + du[i] << " ";
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
