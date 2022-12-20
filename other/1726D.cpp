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

pair<int,int> a[200005];
int par[200005], cs[200005];
bool mm[200005], du[200005];

int findpar(int u)
{
	return par[u] < 0 ? u : par[u] = findpar(par[u]);
}

bool merge(int u, int v)
{
	u = findpar(u); v = findpar(v);
	if (u == v) return false;
	if (par[u] > par[v]) swap(u, v);
	par[u] += par[v];
	par[v] = u;
	return true;
}


void solve() 
{
	int n, m;
	cin >> n >> m;
	//cout << n << " " << m << endl;
	for (int i = 1; i <= n; i++)
	{
		par[i] = -1;
	}
	
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].fi >> a[i].se;
		cs[i] = i;
	}

	if (m < n + 2)
	{
		for (int i = 1; i <= m; i++)
		{
			cout << merge(a[i].fi, a[i].se);
		}
		cout << "\n"; return;
	}

	while(true)
	{
		random_shuffle(cs + 1, cs + 1 + m);
		for (int i = 1; i <= n; i++)
		{
			mm[i] = false;
			//du[i] = true;
			par[i] = -1;
		}
		for (int i = 1; i <= m; i++) du[i] = true;
		int dem = 0;
		for (int i = 1; i <= m; i++)
		{
			int w = merge(a[cs[i]].fi, a[cs[i]].se);
			if (w == 0)
			{
				du[cs[i]] = false; 
				if (!mm[a[cs[i]].fi])
				{
					dem++;
					mm[a[cs[i]].fi] = true;
				}
				if (!mm[a[cs[i]].se])
				{
					dem++;
					mm[a[cs[i]].se] = true;
				}
			}
		}

		if (dem > 3)
		{
			for (int i = 1; i <= m; i++)
			{
				cout << du[i];
			}
			cout << "\n";
			return;
		}
	}
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
