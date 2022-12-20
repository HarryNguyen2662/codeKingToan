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

int sz[300005], sl[300005][2], co[300005], ok[300005], ans[300005], sw[300005];
char s[300005];
pair<int,int> a[300005];

int findpar(int u)
{
	return sz[u] < 0 ? u : findpar(sz[u]);
}

int findco(int u)
{
	if (sz[u] < 0) return sw[u];

	int w = findco(sz[u]); 
	if (!w) return sw[u]; else return 1 - sw[u];
}

void merge(int u, int v, int i)
{
	if (sz[u] > sz[v]) swap(u, v);
	int cou = findco(a[i].fi)^co[a[i].fi], cov = findco(a[i].se)^co[a[i].se];
	// if (i == 3)
	// {
	// 	cout << u << " " << v << endl; cout << cou << " " << cov << endl;
	// }
	if ((cou == cov && s[i] == '0') || (cou != cov && s[i] == '1'))
	{
		swap(sl[v][0], sl[v][1]); sw[v] = 1 - sw[v]; ok[v] = (3 - ok[v])%3;
	}
	sz[u] += sz[v]; sl[u][0] += sl[v][0]; sl[u][1] += sl[v][1];
	sz[v] = u;
}

void solve() 
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}

	for (int i = 1; i <= k; i++)
	{
		sl[i][0] = 1;
		co[i] = 0; sz[i] = -1;
		int sll;
		cin >> sll;
		for (int j = 1; j <= sll; j++)
		{
			int x;
			cin >> x;
			if (a[x].fi == 0) a[x].fi = i; else a[x].se = i;
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i].fi && a[i].se == 0)
		{
			int pa = findpar(a[i].fi);
			int cou = findco(a[i].fi);
			res -= ans[pa];
			if (s[i] == '0') 
			{
				ans[pa] = sl[pa][cou];
				ok[pa] = cou + 1;
			}
			else 
			{
				ans[pa] = sl[pa][1 - cou];
				ok[pa] = 1 - cou + 1;				
			}
			res += ans[pa];
		}
		else if (a[i].fi && a[i].se)
		{
			int u = findpar(a[i].fi), v = findpar(a[i].se);
			if (u == v)
			{
				cout << res << "\n"; continue;
			}

			res = res - ans[u] - ans[v];

			merge(u, v, i); int uv = findpar(a[i].fi);

			if (ok[u] == 1 || ok[v] == 1) 
			{
				ans[uv] = sl[uv][0];
				ok[uv] = 1;
			}
			else if (ok[u] == 2 || ok[v] == 2)
			{
				ans[uv] = sl[uv][1];
				ok[uv] = 2;
			}
			else
			{
				ans[uv] = min(sl[uv][0], sl[uv][1]);
				ok[uv] = 0;
			}

			
			res += ans[uv];

		}
		cout << res << "\n";
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
