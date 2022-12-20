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


const int lim = 100000;
int a[lim + 5], du[60], divi[lim + 5], he[60], cs[lim + 5];
pair<int,int> st[50000];
int dem[lim + 5], dd[lim + 5], high[lim + 5], pa[lim + 5];
long long f[lim + 5];
vector<int> ed[lim + 5], ldk[lim + 5], uoc[lim + 5];

bool cmp(const int &x, const int &y)
{
	if (high[x] == high[y]) return x < y;
	return high[x] < high[y];
}
void dfs(int u, int par)
{
	high[u] = high[par] + 1;
	pa[u] = par;
	for (auto v : ed[u]) if (v != par) dfs(v, u);
}
 

int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

void back_track(int id, const int &u, const int &v)
{
	int cnt = 0;
	st[++cnt] = {id, 1};

	while(cnt)
	{
		id = st[cnt].fi; int val = st[cnt].se;
		cnt--;
		
		if (id == 0)
		{
			if (val > 1)
			uoc[u].pb(val); uoc[v].pb(val);
			continue;
		}

		st[++cnt] = {id - 1, val};
		for (int i = 1; i <= he[id]; i++) 
		{
			val *= du[id]; st[++cnt] = {id - 1, val};
		}
	}
}

void solve() 
{

	int n;

	n = readInt();
	for (int i = 1; i <= lim; i++) divi[i] = i;
	for (int i = 2; i <= lim; i ++) if (divi[i] == i)
	for (int j = 2*i; j <= lim; j += i) divi[j] = i;
	
	for (int i = 1; i <= n; i++) 
	{
		a[i] = readInt(); cs[i] = i;
	}

	for (int i = 1; i < n; i++)
	{
		int u, v;
		u = readInt(); v = readInt();
		ed[u].pb(v); ed[v].pb(u);
		int w = __gcd(a[u], a[v]);
		int cnt = 0;
		while(w > 1)
		{
			if (du[cnt] != divi[w]) 
			{
					du[++cnt] = divi[w];
					he[cnt]  = 1;
			}
			else he[cnt]++;
			w /= divi[w];
		}
		back_track(cnt,  u, v);
		for (int j = 1; j <= cnt; j ++) he[j] = 0;
	}
	
	long long res = 0;

	dfs(1, 0); sort(cs + 1, cs + 1 + n, cmp); for (int i = 1; i <= n; i++) 
	{
		sort(ALL(uoc[cs[i]])); uoc[cs[i]].resize(unique(ALL(uoc[cs[i]])) - uoc[cs[i]].begin());
		for (auto v : uoc[cs[i]]) 
		ldk[v].pb(cs[i]);
	}
	long long re = 1ll*n*(n - 1)/2;

	vector<pair<int, long long>> ans;

	for (int i = lim; i > 1; i--)
	if ((int)ldk[i].size() > 1)
	{
		int cnt = 0;
		for (auto v : ldk[i]) if (dd[pa[v]])
		{
			dd[v] = dd[pa[v]];
			dem[dd[v]]++;
		}
		else
		{
			dd[v] = ++cnt;
			dem[cnt] = 1;
		}
		for (auto v : ldk[i])
		{
			f[i] += 1ll*dem[dd[v]]*(dem[dd[v]] - 1)/2;
			dem[dd[v]] = 0; dd[v] = 0;
		}
 		
 		if (f[i])
		for (int j = 2*i; j <= lim; j += i) f[i] -= f[j];
 
		if (f[i]) ans.pb({i, f[i]}); re -= f[i];
	}
	if (re) ans.pb({1, re});

	for (int i = (int)ans.size() - 1; i >= 0; i--) cout << ans[i].fi << " " << ans[i].se << "\n";

}

int main() 
{   
	//  #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    // //
    freopen("GCDTREE.inp","r",stdin); freopen("GCDTREE.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
