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


void solve() 
{
	int x, y, u, v, e, f;
	cin >> x >> y >> u >> v >> e >> f;
	if (x != u && x != e) 
	{
		cout << x << " ";
		if (min(v, f) == y) cout << max(v, f); else cout << min(v, f);
	}
	else if (u != x && u != e) 
	{
		cout << u << " ";
		if (min(y, f) == v) cout << max(y, f); else cout << min(y, f);
	}
	else 
	{
		cout << e << " ";
		if (min(y, v) == f) cout << max(y, v); else cout << min(v, y);
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
    //freopen("cetvrta.inp","r",stdin); freopen("cetvrta.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
