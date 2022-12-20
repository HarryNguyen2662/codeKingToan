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

vector<int> a[1000005];
int sz[1000005], mx[1000005], ans[1000005];
bool visit[1000005];

void calsize(int u)
{
	visit[u] = true;
	sz[u] = 1;
	mx[u] = 0;

	for(auto v : a[u]) if (visit[v] == false)
	{
		calsize(v);
		if (sz[v] > sz[mx[u]]) mx[u] = v;
		sz[u] += sz[v];
	}
	visit[u] = false;
}

int findpar(int u)
{
	int num = sz[u]/2;
	while(sz[mx[u]] > num) u = mx[u];
	return u;
}

void centroid(int u, int high = 0)
{
	calsize(u); u = findpar(u); 
	visit[u] = true; ans[u] = high;
	for (auto v : a[u]) if (visit[v] == false)
	centroid(v, high + 1);
}

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}

	centroid(1);

	for (int i = 1; i <= n; i++) cout << (char)(ans[i] + 'A');
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
