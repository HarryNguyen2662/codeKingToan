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

vector<int>  aa[100005];
int dem[100005], dem1[100005], sz[100005], mx[100005], ans[100005], cs[100005], n, m;
pair<int, int> cp[100005];
bool visit[100005];

void input_prepare() 
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		if (u > v) swap(u, v);
		dem[u]++; dem1[v]++;
	}

	int cnt = 1; cp[1].se = 1; cp[1].fi = n; cs[1] = 1;
	stack<int> st; st.push(cnt);
	for (int i = 1; i <= n; i++)
	{
		for (; dem1[i]; dem1[i]--)
		{
			int u = st.top(); st.pop();
			aa[u].pb(st.top()); aa[st.top()].pb(u);
			cp[u].fi = i;
		}
		for (; dem[i]; dem[i]--)
		{
			cnt++;
			st.push(cnt);
			cp[cnt].se = i;
			cs[cnt] = cnt;
		}
	}

	m++;
	//for (int i = 1; i <= m; i++) for (auto v : aa[i]) if (v > i) cout << i << " " << v << endl;
}

void calsize(int u)
{
	visit[u] = true;
	sz[u] = 1;
	mx[u] = 0;
	for (auto v : aa[u]) if (visit[v] == false)
	{
		calsize(v);
		if (sz[v] > sz[mx[u]]) mx[u] = v;
		sz[u] += sz[v];
	}
	visit[u] = false;
}

int findroot(int u)
{
	int num = sz[u]/2;
	while(sz[mx[u]] > num) u = mx[u];
	return u;
}

void centroid(int u, int hi = 1)
{
	calsize(u); u = findroot(u);
	visit[u] = true;
	ans[u] = hi;
	for (auto v : aa[u]) if (visit[v] == false) centroid(v, hi + 1);
}

void solve()
{
	input_prepare();
	centroid(1);
	sort(cs + 1, cs + 1 + m, [](const int &x, const int &y)
	{
		return cp[x] < cp[y];
	});

	for (int i = 1; i <= m; i++) cout << ans[cs[i]] << " ";
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
