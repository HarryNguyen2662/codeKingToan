#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define fi first
#define se second
#define pb push_back
#define log 19
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

int a[200005][log+5], lg[200005];

void solve() 
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		lg[i] = lg[i-1];
		while(mask(lg[i]) <= i) lg[i] ++; lg[i] --;
		cin >> a[i][0];
	}
	for (int i = 1; i <= log; i++)
	for (int j = 1; j <= m - mask(i) + 1; j++)
	a[j][i] = max(a[j][i-1], a[j + mask(i - 1)][i-1]);
	
	auto getmax = [&](const int &l, const int &r)
	{
		int k = lg[r - l + 1];
		return max(a[l][k], a[r - mask(k) + 1][k]);
	};
	
	int q;
	cin >> q;
	while(q--)
	{
		int x, y, u, v, k;
		cin >> x >> y >> u >> v >> k;
		if (x%k != u%k || y%k != v%k)
		{
			cout << "NO\n";
			continue;
		}
		int w = x%k;
		int mx = ((n - w)/k)*k + w;
		if (y > v) swap(y, v);
		if (mx <= getmax(y, v))
		{
			cout << "NO\n";
		}
		else cout << "YES\n";
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
