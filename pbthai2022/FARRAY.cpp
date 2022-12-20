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

int n, lg[100005];
long long s, a[100005][log + 2];

void solve() 
{
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i][0];
		a[i][0] += a[i-1][0];
		while(mask(lg[i]) <= i) lg[i]++; lg[i]--;
	}
	
	for (int i = 1; i <= log; i++) for (int j = 0; j <= n - mask(i) + 1; j++)
	a[j][i] = min(a[j][i-1], a[j + mask(i - 1)][i-1]);

	auto get = [&](const int &l, const int &r)
	{
		int k = lg[r - l + 1];
		return min(a[l][k], a[r - mask(k) + 1][k]);
	};
	
	int res = oo;

	for (int i = 1; i <= n; i++)
	{
		int l = 0, r = i - 1;
		while(l <= r)
		{
			int mid = (l + r)/2;
			if (a[i][0] - get(mid, i - 1) >= s) l = mid + 1; else r = mid - 1;
		}
		if (a[i][0] - a[r][0] >= s)  res = min(res, i - r);
	}

	cout << (res == oo ? -1 : res);

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
