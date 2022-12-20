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


vector<int> a[100005];
map<int,int> dem[100005];
int de[100005];
bool dd[100005];
pair<int,int> luu[100005];

void solve() 
{
	vector<int> ldk, dk;

	int n, m;
	cin >> n >> m;

	int can = sqrt(m);

	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v);
		luu[i] = {u, v};
	}

	ll res = 0;

	for (int i = 1; i <= n; i++)
	{
		sort(ALL(a[i]));
		if ((int)a[i].size() <= can) ldk.pb(i);
		else dk.pb(i);
	}

	for (auto v : ldk)
	{
		for (int i = 0; i < (int)a[v].size(); i++)
			for (int j = i + 1; j < (int)a[v].size(); j++)
				{
					res += dem[a[v][i]][a[v][j]];
					dem[a[v][i]][a[v][j]] ++;
				}
	}


	for (auto v : dk)
	{
		for (auto e : a[v]) 
		{
			dd[e] = true;
		}

		for (int i = 1; i <= m; i++)
		{
			if (dd[luu[i].se]) de[luu[i].fi]++;
 		}

 		for (int i = 1; i <= n; i++)
 		{
 			if (((int)a[i].size() <= can) || (v < i))
 			res += 1ll*de[i]*(de[i] - 1)/2; de[i] = 0; dd[i] = false;
 		}
	}

	cout << res;
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
