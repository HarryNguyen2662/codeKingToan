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

const int lim = 100000;
int a[200005];
bool ok[200005];

bitset<100001> dp;

void solve() 
{	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		assert(a[i] <= lim);
		ok[a[i]] = true;
		dp[a[i]] = 1;
	}

	sort(a + 1, a + 1 + n);
	if (a[1] != a[2])
	{
		cout << a[1]; return;
	}
	int res = 0;

	for (int i = a[n]; i >= 1; i--)
	if (ok[i])
	{
		res = max(res, i%a[1]);
		if (i <= 317)
		{
			for (int j = i + 1; j <= a[n]; j++) if (dp[j] == 1) dp[j%i] = 1;
		}
		else
		{
			for (int j = 2*i; j <= a[n]; j += i)
			{
				dp |= (((dp << (lim - j))>>(lim - i)));
			}
		}
	}	
	bitset<2> ldk(0); 

	for (int i = a[1] - 1; i >= 0; i--) if (dp[i] == 1)
	{
		res = max(res, i); break;
	}

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
