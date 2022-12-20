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

int a[200005], b[200005];

void solve() 
{	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int val;
		cin >> val;
		b[i] = val;
		a[val] = i;
	}

	int res = 1;

	for (int i = 2; i <= n; i++) if (a[i-1] > a[i]) res++;

	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;	
		u = b[u]; v = b[v]; swap(b[a[u]], b[a[v]]);

		if (u > v) swap(u, v);

		if (u > 1 && a[u - 1] > a[u]) res--;
		if (v < n && a[v] > a[v + 1]) res--;
		if (u + 1 == v)
		{
			if (a[u] > a[v]) res--;
		}
		else
		{
			if (a[u] > a[u + 1]) res--;
			if (a[v-1] > a[v]) res--;
		}

		swap(a[u], a[v]);

		if (u > 1 && a[u - 1] > a[u]) res++;
		if (v < n && a[v] > a[v + 1]) res++;
		if (u + 1 == v)
		{
			if (a[u] > a[v]) res++;
		}
		else
		{
			if (a[u] > a[u + 1]) res++;
			if (a[v-1] > a[v]) res++;
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
