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

ll p[1000005];

void solve() 
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> p[i];
	sort(p + 1, p + 1 + n);
	
	for (int i = 1; i <= n; i++) p[i] += p[i-1];

	for (int i= 1; i <= m; i++)
	{
		int c, k;
		cin >> c >> k;
		if (c <= k)
		{
			cout << p[n] - p[n - c] << "\n";
		}
		else
		{
			int t = c/(k + 1); c -= t;
			cout << 2*(p[n] - p[n-t]) + p[n-t] - p[n-t-c] << "\n";
		}
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
