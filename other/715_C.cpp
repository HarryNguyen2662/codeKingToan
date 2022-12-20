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

long long res = 0, M;

long long power(long long a, long long b)
{
	if (b == 0) return 1;
	long long aa = power(a, b/2);
	if (b%2) return aa*aa%M*a%M; else return aa*aa%M;
}


map<int,int> dem, dem1;
vector<pair<int,int>> a[100005];
int sz[100005], mx[100005];
bool visit[100005];
long long iw;

int phi(long long m)
{
	int ans = m;
	for (int i = 2; 1ll*i*i <= m; i++)
	if (m % i == 0)
	{
		ans -= ans/i;
		while(m%i == 0) m/=i;
	}
	if (m > 1) ans -= ans/m;
	return ans;
}


void calsize(int u)
{
	visit[u] = true;
	sz[u] = 1;
	mx[u] = 0;
	for (auto v : a[u])
	if (visit[v.fi] == false)
	{
		calsize(v.fi);
		if (sz[v.fi] > sz[mx[u]]) mx[u] =v.fi;
		sz[u] += sz[v.fi];
	}
	visit[u] = false;
}

int findroot(int u)
{
	int num = sz[u]/2;
	while(sz[mx[u]] > num) u = mx[u];
	return u;
}

void dfs1(int u, long long w, long long hs, long long ww, long long hss)
{
	long long e = ((M - w)%M)*hs%M;
	res += dem[e];
	res += dem1[ww];
	visit[u] = true;
	for (auto v : a[u]) if (visit[v.fi] == false)
	{
		dfs1(v.fi, (w*10 + v.se)%M, hs*iw%M, (1ll*hss*v.se + ww)%M, hss*10%M);
	}
	visit[u] = false;
}

void dfs2(int u, long long w, long long hs, long long ww, long long hss)
{
	long long e = ((M - w)%M)*hs%M;
	dem1[e]++;
	dem[ww]++;
	visit[u] = true;
	for (auto v : a[u]) if (visit[v.fi] == false)
	{
		dfs2(v.fi, (w*10 + v.se)%M, hs*iw%M, (1ll*hss*v.se + ww)%M, hss*10%M);
	}

	visit[u] = false;
}

void dfs3(int u, long long w, long long hs, long long ww, long long hss)
{
	long long e = ((M - w)%M)*hs%M;
	dem1[e]--;
	dem[ww]--;
	visit[u] = true;
	for (auto v : a[u]) if (visit[v.fi] == false)
	{
		dfs3(v.fi, (w*10 + v.se)%M, hs*iw%M, (1ll*hss*v.se + ww)%M, hss*10%M);
	}

	visit[u] = false;
}
void centroid(int u)
{
	calsize(u); u = findroot(u);
	visit[u] = true;
	dem[0]++; dem1[0]++;
	for (auto v : a[u]) if (visit[v.fi] == false)
	{
		dfs1(v.fi, v.se%M, iw, v.se%M, 10);
		dfs2(v.fi, v.se%M, iw, v.se%M, 10);
	}
	dem[0]--; dem1[0]--;
	for (auto v : a[u]) if (visit[v.fi] == false) dfs3(v.fi, v.se%M, iw, v.se%M, 10);

	for (auto v : a[u]) if (visit[v.fi] == false) centroid(v.fi);
}

void solve() 
{
	int n;
	cin >> n >> M;
	for (int i = 1; i < n; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		u++; v++;
		a[u].pb({v, w}); a[v].pb({u, w});
	}

	iw = power(10, phi(M) - 1);
	centroid(1);
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
