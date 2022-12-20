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


long long sum[100005], xo[100005], a[100005];

void solve() 
{
	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
		xo[i] = xo[i-1]^a[i];
	}

	while(q--)
	{
		int l, r, le;
		long long res = -1;
		cin >> l >> r;
		int anl = l, anr = r;
		le = l;
		vector<int> ldk, dk;
		for (int i = 0; i <= 40 && l <= r; i++)
		{
			ldk.pb(l);
			int ll = l, rr = r;
			while(ll <= rr)
			{
				int mid = (ll + rr)/2;
				if (sum[mid] - sum[l - 1] == a[l]) ll = mid + 1; else rr = mid - 1;
			}
			l = rr + 1;
		}


		for (int i = 0; i <= 40 && le <= r; i++)
		{
			dk.pb(r);
			int ll = le, rr = r;
			while(ll <= rr)
			{
				int mid = (ll + rr)/2;
				if (sum[r] - sum[mid - 1] == a[r]) rr = mid - 1; else ll = mid + 1;
			}
			r = ll - 1;
		}
		

		for (auto lef : ldk) for (auto rig : dk)
		if (lef <= rig)
		{
			if (res < sum[rig] - sum[lef-1] - (xo[rig]^xo[lef-1]))
			{
				res = sum[rig] - sum[lef-1] - (xo[rig]^xo[lef-1]);
				anr = rig; anl = lef;
			}
			else if (res == sum[rig] - sum[lef-1] - (xo[rig]^xo[lef-1]) && rig - lef + 1 < anr - anl + 1)
			{
				anr = rig; anl = lef;
			}
		}
		if (res == 0) anl = ldk[0], anr = ldk[0];

		cout << anl << " " << anr << "\n";
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
    cin >> testcase;
    while(testcase--)
        solve();
}
