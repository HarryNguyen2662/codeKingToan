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

pair<int, pair<int,int>> luu[300005];
vector<int> spec[300005];
int pe[300005], ok[300005];

int findpe(int u)
{
	return pe[u] < 0 ? u : pe[u] = findpe(pe[u]);
}

void merge(int u, int v)
{
	if (pe[u] > pe[v]) swap(u, v);
	pe[u] += pe[v];
	pe[v] = u;
	ok[u] = max(ok[u], ok[v]);
}


void solve() 
{
	int n, k;
	vector<pair<int, int>> match;
	cin >> n >> n >> k >> k;

	pe[n] = -1; 
	for (int i = 1; i < n; i++)
	{
		pe[i] = -1;
		int u, v, w;
		cin >> u >> v >> w;
		luu[i] = {w, {u, v}};
	}

	sort(luu + 1, luu + n);

	for (int i = 1; i <= k; i++)
	{
		int u;
		cin >> u; spec[u].pb(i);
		ok[u] = u;
	}

	int id;

	long long res = 0;

	for (id = n - 1; id>= 1; id--) 
	{
		if (luu[id].fi < 22071997) break;

		int u = findpe(luu[id].se.fi), v = findpe(luu[id].se.se);

		if (ok[u] && ok[v])
		{
			while(true)
			{
				if ((int)spec[ok[v]].size() == 0 || (int)spec[ok[u]].size() == 0) break;
				res += luu[id].fi;
				match.pb({spec[ok[u]].back(), spec[ok[v]].back()}); 
				spec[ok[u]].pop_back();
				spec[ok[v]].pop_back();
			}
		}
		if ((int)spec[ok[v]].size() == 0) ok[v] = 0;
		if ((int)spec[ok[u]].size() == 0) ok[u] = 0;
		
		merge(u, v);
	}

	for (int i = 1; i <= n; i++)
	if ((int)spec[i].size())
	{
		while((int)spec[i].size() >= 2)
		{
			res += 22071997;
			match.pb({spec[i].back(), 0}); spec[i].pop_back();
			match.back().se = spec[i].back(); spec[i].pop_back();
		}
		if(!(int)spec[i].size()) ok[findpe(i)] = 0;
	}

	for (; id >= 1; id--)
	{
		int u = findpe(luu[id].se.fi), v = findpe(luu[id].se.se);

		if (ok[u] && ok[v])
		{
			while(true)
			{
				if ((int)spec[ok[v]].size() == 0 || (int)spec[ok[u]].size() == 0) break;
				res += luu[id].fi;
				match.pb({spec[ok[u]].back(), spec[ok[v]].back()}); 
				spec[ok[u]].pop_back();
				spec[ok[v]].pop_back();
			}
		}
		if ((int)spec[ok[v]].size() == 0) ok[v] = 0;
		if ((int)spec[ok[u]].size() == 0) ok[u] = 0;
		
		merge(u, v);
	}

	cout << res << "\n";

	for (auto v : match) cout << v.fi << " " << v.se << "\n";

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
