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

ll a[5005];
int cs[5005];

struct DATA
{
	ll x, y, z;

	bool operator < (const DATA &other) const
	{
		return (a[y]*a[y] + a[z]*a[z] - a[x]*a[x])*a[other.y]*a[other.z] 
		>= (a[other.y]*a[other.y] + a[other.z]*a[other.z] - a[other.x]*a[other.x])*a[y]*a[z];
	}
};

void solve() 
{
	int n; ll p, q;
	cin >> n >> p >> q;
	vector<DATA> ldk;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		cs[i] = i;
	}

	sort(cs + 1, cs + 1 + n, [](const int &x, const int &y)
	{
		return a[x] < a[y];
	});

	for (int i = 1; i <= n; i++)
	for (int j = i + 1; j <= n; j++)
	{
		ll ok = (a[cs[i]]*a[cs[i]] + a[cs[j]]*a[cs[j]])*q - 2*a[cs[i]]*a[cs[j]]*p;
		int l = 1, r = n;
		while(l <= r)
		{
			int mid = (l + r)/2;
			if (a[cs[mid]] < a[cs[i]] + a[cs[j]] && q*a[cs[mid]]*a[cs[mid]] <= ok) l = mid + 1; else r = mid - 1;
		}

		if (r == i || r == j) r--; if (r == i || r == j) r--;
		
		if (r && a[cs[r]] > a[cs[j]] - a[cs[i]] && a[cs[r]] < a[cs[i]] + a[cs[j]] && q*a[cs[r]]*a[cs[r]] <= ok)
		{
			ldk.pb({cs[r], cs[i], cs[j]});
		}
	}

	if ((int)ldk.size() == 0)
	{
		cout << "-1"; return;
	}

	DATA res = ldk[0];

	for(auto v : ldk) if (res < v) res = v;


	cout << res.x << " " << res.y << " " << res.z;
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
