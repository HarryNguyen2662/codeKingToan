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

const int lim = 2e5;
int cnt = 0, visit[lim + 5], luu[lim + 5], grandy[lim + 5], va[lim + 5], ans[lim + 5];
bool dd[lim + 5], kt[lim + 5];
vector<int> free_square[lim + 5], a[lim + 5];


void dfs1(int u)
{
	visit[u] = cnt; grandy[u] = 0;
	vector<int> ldk;
	for (auto v : a[u])
	{
		if (visit[v] != cnt) dfs1(v);
		ldk.pb(grandy[v]);
	}
	for (auto v : ldk)
	{
		dd[v] = true;
		while(dd[grandy[u]]) grandy[u]++;
	}
	for (auto v : ldk) dd[v] = false;
	ans[grandy[u]] ^= luu[va[u]];
}

void solve() 
{
	int n, m;
	cin >> n >> m;
	ans[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> va[i];
		a[i].clear();
		ans[i] = 0;
	}

	for (int j = 1; j <= m; j ++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); 
	}

	cnt++;
	for (int i = 1; i <= n; i++) if (visit[i] != cnt) dfs1(i);
	for (int i = 0; i < n; i++) if (ans[i] != 0)
	{
		cout << "1\n";
		return;
	}
	cout << "0\n";

}


void dfs(int u)
{
	visit[u] = cnt; grandy[u] = 0;
	vector<int> ldk;
	for (auto v : free_square[u])
	{
		if (visit[v] != cnt) dfs(v);
		ldk.pb(grandy[v]);
	}
	for (auto v : ldk)
	{
		dd[v] = true;
		while(dd[grandy[u]]) grandy[u]++;
	}
	for (auto v : ldk) dd[v] = false;
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

    auto  check = [&](const int &x)
    {
    	for (int i = 2; 1ll*i*i <= x; i++) if (x%(i*i) == 0) return false;
    	return true;
    };

    cnt++;
    for (int i = 2; i <= lim; i++) 
    {
    	kt[i] = check(i);
    	for (int j = 1; 1ll*j*j <= lim; j++) 
    	if (i%j == 0)
    	{
    		if (kt[j])
    		free_square[i].pb(i/j);
    		if (i/j != j && kt[i/j]) free_square[i].pb(j);
    	}
    	
    	dfs(i); 
    	luu[i] = grandy[i];
   		
    }
    cin >> testcase;
    while(testcase--)
        solve();
}
