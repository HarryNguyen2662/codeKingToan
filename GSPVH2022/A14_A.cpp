#include<bits/stdc++.h>

using namespace std;

#define int __int64
#define NMOD 3
#define ll __int64
#define fi first
#define se second
#define pb push_back
#define log 17
#define mask(i) (1ll << (i))
#define setp(x) setprecision(x)
#define ALL(v) v.begin(), v.end()
#define ck(n, i) (((n) >> (i)) & 1) 
#define getbit(x) __builtin_popcount(x)



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll k, adu, a[100005], n;

bool check(ll val)
{
	return val*(val + 1)/2 - adu*(val/n) + a[val%n] >= k;
}

void solve() 
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		adu += a[i];
		a[i] = a[i - 1] - a[i];
	}

	for (int i = 1; i <= n; i++)
	if (check(i))
	{
		cout << i; return;
	}

	ll res = 1e18;

	for (int i = 1; i <= n; i++)
	{
		int l = 0, r = 3e9/n;

		while(l <= r)
		{
			int mid = (l + r)/2;
			if (check(mid*n + i)) r = mid - 1; else l = mid + 1;
		}
		res = min(res, l*n + i);
	}

	cout << res;

}

signed main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("nhanpham.inp","r",stdin); freopen("nhanpham.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
