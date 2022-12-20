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

vector<int> a[500005];

void solve() 
{	
	int n, m, k;
	vector<int> ldk;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		if (u < v) swap(u, v);
		a[u].pb(v);
	}
	for (int i = 1; i < n; i++) a[i + 1].pb(i); a[n].pb(1);
	for (int i = 1; i <= n; i++)
	if ((int)a[i].size())
	{
		sort(ALL(a[i])); reverse(ALL(a[i]));
	}
	m++; k = m - k + 1;
	for (; n; n--)
	if (k + 1 > (int)a[n].size())
	{
		k -= (int)a[n].size(); k++;
	}
	else
	{
		ldk.pb(n);
		int w = a[n][k-1];
		//cout << w << endl;
		while(1)
		{
			ldk.pb(w); w = a[w].back();
			if (w == a[n][k]) break;
		}
		ldk.pb(a[n][k]);
		break;
	}	
	reverse(ALL(ldk));
	for (auto v : ldk) cout << v << " ";
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
