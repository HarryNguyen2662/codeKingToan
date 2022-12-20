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

struct DATA
{
	int ti, fe, re;

	DATA(int _ti = 0, int _fe = 0, int _re = 0)
	{
		ti = _ti; fe = _fe ; re = _re;
	};
};

DATA query[100005];

bitset<1001> flip, se[1005];
int nu[1005], curr = 0, ans[100005];
int n, m, q, luu[100005];
vector<int> a[100005];

void dfs(int u)
{
	bool ok = false;
	DATA v = query[u];
	if (v.ti == 3)
	{
		se[v.fe] ^= flip;
		curr -= nu[v.fe];
		nu[v.fe] = m - nu[v.fe];
		curr += nu[v.fe];
	}
	else if (v.ti == 1 && se[v.fe][v.re] == 0)
	{
		ok = true;
		curr++;
		nu[v.fe]++;
		se[v.fe][v.re] = 1;
	} 
	else if (v.ti == 2 && se[v.fe][v.re] == 1)
	{
		ok = true;
		curr--;
		nu[v.fe]--;
		se[v.fe][v.re] = 0;
	}

	ans[u] = curr;

	for (auto v : a[u])
	{
		dfs(v);
	}

	if (v.ti == 3)
	{
		se[v.fe] ^= flip;
		curr -= nu[v.fe];
		nu[v.fe] = m - nu[v.fe];
		curr += nu[v.fe];
	}
	else if (v.ti == 1 && ok)
	{
		curr--;
		nu[v.fe]--;
		se[v.fe][v.re] = 0;
	} 
	else if (v.ti == 2 && ok)
	{
		curr++;
		nu[v.fe]++;
		se[v.fe][v.re] = 1;
	}
}

void solve() 
{	
	cin >> n >> m >> q;

	for (int i = 1; i <= m; i++) flip[i] = 1;

	int cur = 0;
	int cnt = 0;

	for (int i = 1; i <= q; i++)
	{
		int type;
		cin >> type;
		if (type == 4)
		{
			int k;
			cin >> k;
			luu[i] = luu[k];
		}
		else if (type <= 2)
		{
			int u, v;
			cin >> u >> v;
			luu[i] = ++cnt;
			query[cnt] = DATA(type, u, v);
			a[cur].pb(cnt);
		}
		else 
		{
			int u;
			cin >> u;
			luu[i] = ++cnt;
			query[cnt] = DATA(3, u, 0);
			a[cur].pb(cnt); 
		}
		
		cur = luu[i];
	}

	dfs(0);

	for (int i = 1; i <= q; i++) cout << ans[luu[i]] << "\n";
}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    // //
    freopen("BIENDOI.inp","r",stdin); freopen("BIENDOI.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
