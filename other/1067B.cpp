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


int dd[100005], bac[100005], pre[100005], center = 0;
vector<int> a[100005];

void dfs(int u, int par, int hei)
{
	pre[u] = par;
	if (dd[hei] == 0)
	{
		dd[hei] = u;
	}
	for (auto v : a[u]) if (v != par)
	{
		dfs(v, u, hei + 1);
	}
}


void dfs1(int u, int par)
{
	vector<int> ldk;
	for (auto v : a[u])
	if (v != par)
	{
		dfs1(v, u);
		ldk.pb(bac[v]);
	}

	if (!(int)ldk.size())
	{
		return;
	}

	if ((int)ldk.size() < 3)
	{
		cout << "NO";
		exit(0);
	}

	for (int i = 1; i < (int)ldk.size(); i++) if (ldk[i] != ldk[i-1])
	{
		cout << "NO";
		exit(0);
	}
	bac[u] = ldk[0] + 1;


}


void solve() 
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}
	dfs(1, 0, 1);

	int id = 0;
	for (int i = n; i; i--)
	{
		if (!id && dd[i])
		{
			id = dd[i];
		}	
		dd[i] = 0;
	}
	dfs(id, 0, 1);

	int len = 0;

	for (int i = n; i; i--)
	{
		if (!len && dd[i])
		{
			len = i;
			center = dd[i];
			if (len%2 == 0)
			{
				cout << "NO"; return;
			}
		}
	}

	//cout << center << endl;

	for (int i = 1; i <= len/2; i++) center = pre[center];

	dfs1(center, 0);

	if (bac[center] == k)
	cout << "YES";
	else
	cout << "NO";
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
