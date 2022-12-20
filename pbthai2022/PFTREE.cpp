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

const int maxn = 100005;

vector<int> a[maxn];
vector<pair<int,int>> lu[maxn];
int max_high = 0;
int high[maxn];
bool oki[maxn];


void dfs(int u, int par)
{

	high[u] = high[par] + 1;
	max_high = max(max_high, high[u]);

	for (auto v : a[u]) if (v != par)
	{
		dfs(v, u);

		lu[0].clear();
		swap(lu[u], lu[0]);
		int last1 = 0, last2 = 0;

		int n = (int)lu[0].size(), m = (int)lu[v].size();
		int id1 = 0, id2 = 0;

		while(id1 < n || id2 < m)
		{
			if (id1 < n && id2 < m)
			{
				if (lu[0][id1].fi < lu[v][id2].fi)
				{
					last1 = lu[0][id1].se;
					if ((int)lu[u].size() == 0 || last1 + last2 != lu[u].back().se)
					lu[u].pb({lu[0][id1].fi, last1 + last2});
					id1++;
				}
				else if (lu[0][id1].fi > lu[v][id2].fi)
				{
					last2 = lu[v][id2].se;
					if ((int)lu[u].size() == 0 || last1 + last2 != lu[u].back().se)
					lu[u].pb({lu[v][id2].fi, last1 + last2});
					id2++;
				}
				else
				{
					last1 = lu[0][id1].se;
					last2 = lu[v][id2].se;
					if ((int)lu[u].size() == 0 || last1 + last2 != lu[u].back().se)
					lu[u].pb({lu[0][id1].fi, last1 + last2});
					id1++;
					id2++;
				}
			}
			else if (id1 < n)
			{
				if ((int)lu[u].size() == 0 || lu[0][id1].se + last2 != lu[u].back().se)
				lu[u].pb({lu[0][id1].fi, lu[0][id1].se + last2});
				id1++;
			}
			else
			{
				if ((int)lu[u].size() == 0 || lu[v][id2].se + last1 != lu[u].back().se)
				lu[u].pb({lu[v][id2].fi, lu[v][id2].se + last1});
				id2++;
			}
		}

	}

		reverse(ALL(lu[u])); while((int)lu[u].size() && lu[u].back().se == 1) lu[u].pop_back();
		lu[u].pb({high[u], 1});
		reverse(ALL(lu[u]));
}

struct DATA
{
	ll fii, see;
	DATA(ll _fii = 0, ll _see = 0)
	{
		fii = _fii; see = _see;
	}
};

struct DATA1
{
	ll fii, see, tii;
	DATA1(ll _fii = 0, ll _see = 0, ll _tii = 0)
	{
		fii = _fii; see = _see; tii = _tii;
	}
};

long long power(long long x, long long y)
{
	if (y == 0) return 1;
	long long xx = power(x, y/2);
	if (y%2) return xx*xx%MOD*x%MOD; else return xx*xx%MOD;
}

DATA calc1(ll val, ll x)
{
	if (x == 0)
	{
		return DATA(1, 0);
	}

	DATA res = calc1(val, x/2);
	res = {res.fii*res.fii%MOD,  (res.fii+ 1)*res.see%MOD};

	if (x%2) res = {res.fii*val%MOD, (res.see + res.fii*val)%MOD};

	return res;
}

DATA1 calc2(ll val, ll x)
{
	if (x == 0)
	{
		return DATA1(1, 0, 0);
	}

	DATA1 res = calc2(val, x/2);

	res = {res.fii*res.fii%MOD, (res.fii + 1)*res.see%MOD, ((res.fii + 1)*res.tii%MOD + 1ll*(x/2)*res.see%MOD*res.fii%MOD)%MOD};

	if (x%2)
	res = {res.fii*val%MOD, (res.see + res.fii*val)%MOD, (res.tii + x*res.fii%MOD*val)%MOD};

	return res;

}

ll calc(ll val, ll x, ll y, ll he, ll hi)
{
	//y la so luong| x la loai| he la mu bat dau | hi la do cao nho nhat
	
	DATA f = calc1(val, y - 1);	

	ll val1 = (f.see + 1)*power(val, he)%MOD;

	DATA1 ff = calc2(power(val, y), x - 1);

	ll val2 = (ff.tii + 1ll*hi*(1 + ff.see)%MOD)%MOD;

	return val1*val2%MOD;
}

bool kktt = true;

void dfs1(int u, int par)
{
	if (high[u] == max_high) oki[u] = true;

	for (auto v : a[u]) if (v != par)
	{
		dfs1(v, u);
		if (oki[v]) oki[u] = true;
	}
	if (!oki[u]) kktt = false;
}

vector<int> ldk[100005];

void dfs2(int u, int par)
{
    ldk[u].pb(high[u]);

    for (auto v : a[u]) if (v != par)
    {
        dfs2(v, u);
        for (auto e : ldk[v]) ldk[u].pb(e);
    }

    sort(ALL(ldk[u]));
}


void solve() 
{
	int n, q;
	cin >> n >> q;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v); a[v].pb(u);
	}

	dfs(1, 0);
	// dfs1(1, 0);

	// if (!kktt)
	// {
	// 	dfs2(1, 0);


	//     ll ans = 0;

	//     ll su = 0;


	//     while(q--)
	//     {
	//         ll u, t;
	//         cin >> u >> t;
	        
	//         u = 1 + (u + su)%n; t = 1 + (t + su)%oo;
	//         ans = 0;

	//         for (int i = 0; i < (int)ldk[u].size(); i++) 
	//         {
	//             ans += 1ll*(ldk[u][i] - high[u])*power(t, i)%MOD; ans %= MOD;

	//         }
	//         su += ans;
	//         cout << ans << "\n";
	//     }
	//     return;
	// }

	// for (int i = 1; i <= n; i++)
	// {
	// 	cout << i << "\n";
	// 	for (auto v : lu[i]) cout << v.fi << " " << v.se << "\n";
	// 	cout << endl;
	// }


	ll suu = 0;

	while(q--)
	{
		ll aa, bb;
		cin >> aa >> bb;

		ll u = 1 + (aa + suu)%n; ll t = 1 + (bb + suu)%oo;


		ll ans = 0;

		int lim = (int)lu[u].size();

		int su = 0;

		for (int i = 0; i + 1 < lim; i++)
		{
			int cu = lu[u][i + 1].fi - lu[u][i].fi, cur = lu[u][i].se;

			ans += calc(t, cu, cur, su, lu[u][i].fi - lu[u][0].fi);

			ans %= MOD;
			
			su += cu*cur;
		}
		ans += calc(t, max_high - lu[u].back().fi + 1, lu[u].back().se, su, lu[u].back().fi - lu[u][0].fi);
		
		ans %= MOD;

		suu += ans;

		cout << ans << "\n";
	}
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
