#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e6 + 3;
const int MAXN = 1e6;
const int oo = 1e9;
int dad[300050], con[300050], sau[300050];
vector<int> a[300050];
void dfs(int u)
{
	con[u] = a[u].size();
	for(auto v : a[u])
	{
		sau[v] = sau[u] + 1;
		dfs(v);
	}
}
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("hellodking.txt","r",stdin);
    #else
    // online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n ,m, u, v, root;
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
    	cin >> u >> v;
    	dad[u] = v;
    	a[v].pb(u);
    }
    for (int i = 1; i <= n; i++) 
    	if (dad[i] == 0) root= i;
    dfs(root);
	priority_queue<pair<int,int> > qq;
	for (int i = 1; i <= n; i++)
	if (con[i] == 0) qq.push({sau[i], i});
	int ans = 0;
	vector<pair<int,int> > tt;
	while (!qq.empty())
	{
		ans++;
		for (int i = 1; i <= m; i++)
		{
			int v = qq.top().s; qq.pop();
			con[dad[v]]-- ;
			if (con[dad[v]]==0) tt.pb({sau[dad[v]],dad[v]});
			if (qq.empty()) break;
		}
		for (auto v : tt) qq.push(v);
		tt.clear();
	}
	cout << ans;
}