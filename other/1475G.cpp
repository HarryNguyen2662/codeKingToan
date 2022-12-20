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

int f[200005], a[200005];

void solve() 
{
	int n;
	int mx = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		mx = max(mx, a[i]);
	}


	sort(a + 1, a + 1 + n);

	int res = 0;

	for (int i = 1; i <= n; i++)
	{
		int w = 0;
		for (int j = 1; 1ll*j*j <= a[i]; j++)
		if (a[i]%j == 0)
		{
			w = max({w, f[j], f[a[i]/j]}); 
		}
		f[a[i]] = w + 1;
		res = max(res, f[a[i]]);
	}
	for (int i = 1; i <= mx; i++) f[i] = 0;

	cout << n - res << "\n";
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
