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

bool dd[1005][1005];
vector<int> a[1004], aa[1004];

void solve() 
{
	int n, m;
	cin >> n >> m;

	long long res = 0;

	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v);
		aa[v].pb(u);
		dd[u][v] = true;
	}

	int w = sqrt(n);

	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (dd[i][j])
	{
		if ((int)a[i].size() <= w)
		{
			for (auto v : aa[i]) if (dd[j][v]) res++;
		}
		else
		{
			for (auto v : a[j]) if (dd[v][i]) res++;
		}
	}

	cout << res/3;

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
