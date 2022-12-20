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

int a[200], b[200];

vector<int> ldk[200];

long long dp[2000005], dp1[2000005];

void solve() 
{
	int n, h;
	cin >> n >> h;
	
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	long long dem = 0, dem1 = 0;

	for (int i = 0; i < mask(n); i++)
	{
		long long cur = 0, cur1 = 0;
		for (int j = i; j; j ^= (j&(-j)))
		{
			int id = __builtin_ctz(j);
			cur += a[id]; cur1 += b[id];
		}
		if (cur >= h) dp[i]++; 
		if (cur1 >= h) dp1[mask(n) - i - 1]++;
	}

	long long res = 0;

	for (int i = 0; i < n; i++) for(auto j : ldk[i])
	{
		if (j >= mask(n)) break;
		dp1[j] += dp1[j^mask(i)]; 
	}

	for (int i = 0; i < mask(n); i++)
	{
		res += dp[i]*dp1[i];
		dp[i] = dp1[i] = 0;
	}

	cout << res << "\n";
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
    for (int i = 0; i < 20; i++) for (int j = 0; j < mask(20); j++) if (ck(j, i)) ldk[i].pb(j);
    cin >> testcase;
    while(testcase--)
        solve();
}
