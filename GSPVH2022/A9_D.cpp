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

vector<pair<int,int>> match, ed[300005];
vector<int> spec[300005];
int cs[800005];
long long high[300005];
long long res = 0;

int dfs(int u, int pe)
{
	//cout << u << " " << high[u] << endl;
	vector<int> hehe;
	for (auto v : spec[u]) hehe.pb(v);
	for (auto v : ed[u])
	if (v.fi != pe)
	{
		high[v.fi] = high[u] + v.se;
		int w = dfs(v.fi, u);
		if (w != - 1) hehe.pb(w);		
	}
	for (int i = 0; i + 1 < (int)hehe.size(); i+= 2) 
	{
		match.pb({hehe[i], hehe[i + 1]});
		//cout << cs[hehe[i]] << " " << cs[hehe[i + 1]] << endl;
		res += high[cs[hehe[i]]] + high[cs[hehe[i+1]]] - 2*high[u];
	}

	if ((int)hehe.size()%2) return hehe.back(); else return - 1;
}

void solve() 
{
	int n, k;
	cin >> n >> n >> k >> k;

	for (int i = 1; i < n; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		ed[u].pb({v, w}); ed[v].pb({u , w});
	}

	for (int i = 1; i <= k; i++)
	{
		int u;
		cin >> u; spec[u].pb(i);
		cs[i] = u;
	}

	dfs(1, 0);

	cout << res << "\n"; for (auto v : match) cout << v.fi << " " << v.se << "\n";
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("partner.inp","r",stdin); freopen("partner.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
