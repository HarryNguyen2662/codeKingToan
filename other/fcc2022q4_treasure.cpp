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

long long power(long long x, long long y)
{
	if (y == 0) return 1;
	long long xx = power(x, y/2);
	if (y%2) return xx*xx%MOD*x%MOD; else return xx*xx%MOD;
}

const ll Base = 9012005;

int n, m;
ll hs[200005], a[200005], b[200005], pw[200005];

bool check(int k)
{
	vector<ll> ldk;
	for (int i = 1; i < m; i++)
	{
		hs[i] = hs[i - 1]*Base + b[i];
		if (i >= k) ldk.pb(hs[i] - hs[i - k]*pw[k]);
	}

	sort(ALL(ldk));

	for (int i = 1; i < n; i++)
	{
		hs[i] = hs[i - 1]*Base + a[i];
		if (i >= k)
		{
			ll cur = hs[i] - hs[i - k]*pw[k];
			int id = lower_bound(ALL(ldk), cur) - ldk.begin();
			if (id < (int)ldk.size() && ldk[id] == cur) return true;
		}
	}

	return false;
}

void solve() 
{
	cin >> n >> m;

	if (min(n, m) == 1)
	{
		cout << 1; return;
	}

	pw[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pw[i] = pw[i-1]*Base;
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> b[i];
	}
	for (int i = 1; i < n; i++)
	{
		a[i] = a[i]*power(a[i + 1], MOD - 2)%MOD;
	}

	for (int i = 1; i < m; i++)
	{
		b[i] = b[i]*power(b[i + 1], MOD - 2)%MOD;
	}

	int l = 1, r = min(n - 1, m - 1);

	while(l <= r)
	{
		int mid = (l + r)/2;
		if (check(mid)) l = mid + 1; else r = mid - 1;
	}

	cout << r + 1;
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
