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

int a[200005];
ll sum[200005];
map<ll, int> dem;

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}

	int st = - 1;

	ll res = 0;

	for (int i = 1; i <= n; i++)
	if (a[i] == 0)
	{
		if (st == -1)
		{
			st = i;
			continue;
		}
		int re = 0;
		for (int e = st; e < i; e++)
		{
			dem[sum[e]]++;
			re = max(re, dem[sum[e]]);
		}
		res += re;
		 // cout << st << " " << i << " " << re << endl;
		for (int e = st; e < i; e++)
		{
			dem[sum[e]] = 0;
		}
		st = i;
	}
	else
	{
		if (st == -1 && sum[i] == 0) res++;
 	}

	if (st != -1)
	{
		int re = 0;
		for (int e = st; e <= n; e++)
		{
			dem[sum[e]]++;
			re = max(re, dem[sum[e]]);
		}
		res += re;
		for (int e = st; e <= n; e++)
		{
			dem[sum[e]] = 0;
		}
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
    cin >> testcase;
    while(testcase--)
        solve();
}
