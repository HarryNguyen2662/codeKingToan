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

vector<int> cs[100005];
int b[100005];

void solve() 
{
	int n;
	cin >> n;
	vector<int> ldk, res;
	for (int i = 0; i <= n + 1; i++) cs[i].clear();
	int k = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];

		if (b[i] == n + 1 || b[i] == 0)
		{
			ldk.pb(i);
		}
		cs[b[i]].pb(i);
	}
	int tt = (b[ldk[0]] == n + 1);
	while(true)
	{
		int ruu = 0;
		for (auto v : ldk) 
		{
			if (!(int)cs[v].size()) res.pb(v); else ruu = v;
			if (tt) k = max(k, v);
		}
		if (ruu == 0) break;
		res.pb(ruu);
		ldk = cs[ruu];
		tt = 1 - tt;
	}

	cout << k << "\n";

	for (auto v : res) cout << v << " ";
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
