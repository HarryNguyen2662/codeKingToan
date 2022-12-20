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

unordered_map<int,int> dem, dem1;
int su[1000005], suu[1000005], val[1000005];
pair<pair<int,int>, int> a[200005];
pair<pair<int,int>, pair<int,int>> b[200005];

void solve() 
{
	vector<int> diff;
	vector<pair<int,int>> deff;
	int n, k, p;
	cin >> n >> k >> p;

	for (int i = 1; i <= k; i++)
	{
		cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
		diff.pb(a[i].fi.fi); diff.pb(a[i].fi.se); 
		deff.pb(a[i].fi);
	}
	for (int i = 1; i <= p; i++)
	{
		cin >> b[i].fi.fi >> b[i].fi.se >> b[i].se.fi >> b[i].se.se;
		diff.pb(b[i].fi.fi); diff.pb(b[i].fi.se); 
		diff.pb(b[i].se.fi); diff.pb(b[i].se.se); 
		deff.pb(b[i].fi); deff.pb(b[i].se);
	}
	
	sort(ALL(diff)); sort(ALL(deff)); 
	diff.resize(unique(ALL(diff)) - diff.begin()); 
	deff.resize(unique(ALL(deff)) - deff.begin());
	
	long long res = 1ll*n*n;
	dem[0] = dem1[0] = n;
	
	for (int i = 1; i <= k; i++)
	{
		val[lower_bound(ALL(deff), a[i].fi) - deff.begin()] = a[i].se;
		int id = lower_bound(ALL(diff), a[i].fi.fi) - diff.begin();
		res -= dem1[su[id]]; res += dem1[su[id]^a[i].se];
		dem[su[id]^a[i].se]++; dem[su[id]]--;
		su[id] ^= a[i].se;

		id = lower_bound(ALL(diff), a[i].fi.se) - diff.begin();
		res -= dem[suu[id]]; res += dem[suu[id]^a[i].se];
		dem1[suu[id]^a[i].se]++; dem1[suu[id]]--; 
		suu[id] ^= a[i].se;
	}

	for (int i = 1; i <= p; i++)
	{
		int x = lower_bound(ALL(deff), b[i].fi) - deff.begin();
		int y = lower_bound(ALL(deff), b[i].se) - deff.begin();
		assert(b[i].fi == deff[x]);
		assert(b[i].se == deff[y]);
		if (b[i].fi.fi != b[i].se.fi)
		{
			int id = lower_bound(ALL(diff), b[i].fi.fi) - diff.begin();
			res -= dem1[su[id]]; res += dem1[su[id]^val[x]];
			dem[su[id]^val[x]]++; dem[su[id]]--;
			su[id] ^= val[x];
		
			id = lower_bound(ALL(diff), b[i].se.fi) - diff.begin();
			res -= dem1[su[id]]; res += dem1[su[id]^val[x]];
			dem[su[id]^val[x]]++; dem[su[id]]--;
			su[id] ^= val[x];
		}

		if (b[i].fi.se != b[i].se.se)
		{
			int id = lower_bound(ALL(diff), b[i].fi.se) - diff.begin();
			res -= dem[suu[id]]; res += dem[suu[id]^val[x]];
			dem1[suu[id]^val[x]]++; dem1[suu[id]]--; 
			suu[id] ^= val[x];

			id = lower_bound(ALL(diff), b[i].se.se) - diff.begin();
			res -= dem[suu[id]]; res += dem[suu[id]^val[x]];
			dem1[suu[id]^val[x]]++; dem1[suu[id]]--; 
			suu[id] ^= val[x];
		}
		if (x != y)
		{
			val[y] = val[x]; val[x] = 0;
		}

		cout << 1ll*n*n - res << " ";

	}
}

int main() 
{   
     
  freopen("topovi.inp","r",stdin); freopen("topovi.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
