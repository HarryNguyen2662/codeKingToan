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

int a[1005], de[1005], cango[1005][1005], cs[1005];
vector<int> adj[1005];

void dfs(int u, int pre)
{
	//cout << u << " " << pre << endl;
	cango[pre][u] = 2; cango[u][pre] = 0;
	for (auto v : adj[u])
	if (cango[u][v] == 1)
	{
		de[v]--; de[u]--;
		dfs(v, u);
		return;
	}
}

void solve() 
{
	long long su = 0;
	int n;
	bool kt = true;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cs[i] = i;
		for (int j = 1; j <= n; j++) cango[i][j] = 0;
		adj[i].clear();
		cin >> a[i];
		de[i] = a[i];
		if (a[i] >= n)
		{
			kt = false;
		}
		su += a[i];
	}
	if (su%2 || !kt)
	{
		cout << "-1\n";
		return;
	}

	for (int i = 1;  i <= n; i++)
	{
		sort(cs + 1, cs + 1 + n, [](const int &x, const int &y)
			{
				return a[x] > a[y];
			});
		if (a[cs[1]] == 0) break;
		//cout << 1 + a[cs[1]] << endl;
		for (int j = 2; j <= 1 + a[cs[1]]; j++)
		{
			//cout << cs[i] << " " << cs[j] << endl;
			if (a[cs[j]] == 0)
			{
				cout << "-1\n";
				return;
			}
			adj[cs[1]].pb(cs[j]); adj[cs[j]].pb(cs[1]);
			cango[cs[1]][cs[j]] = 1; cango[cs[j]][cs[1]] = 1;
			a[cs[j]]--;
		}
		a[cs[1]] = 0;
	}

	for (int i = 1; i <= n; i++)
	if (de[i]%2)
	{
		dfs(i, 0);
	}
	for (int i = 1; i <= n; i++)
	if (de[i]%2 == 0)
	{
		dfs(i, 0);
	}

	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (cango[i][j] == 2) cout << i << " " << j << " ";
	cout << "\n";

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
    cin >> testcase;
    while(testcase--)
        solve();
}
