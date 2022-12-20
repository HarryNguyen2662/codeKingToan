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

int n, k, m;

long long f[1000435];

void Ans()
{
	long long res = 0;
	long long w = 1;
	for (int i = 1; i <= n; i++)
	{
		w = w*1ll*(n+1)%MOD1;
		res = (res + w*f[i]%MOD1 + MOD1)%MOD1;
	}
	cout << res << "\n";
}

void solve() 
{
	cin >> n >> n >> k >> m;
	for (int i = 1; i <= n; i++) f[i] = MOD1-1;
	for (int i = 1 ; i <= k; i++)
	{
		int x;
		cin >> x;
		f[x] = 0;
	}
	Ans();
	while(m--)
	{
		char type; int l, r;
		cin >> type >> l >> r;
		if (type == 'D')
		{

			long long res = oo;
			if (f[r] != MOD1 -1) res = min(res, f[r] + 1);
			if (f[l] != MOD1-1) res = min(res, f[l] + 1);
			f[l] = min(f[l], res);
			f[r] = min(f[r], res);
		}
		else
		{
			long long res = oo;
			for (int i = l; i  <= r; i++) if (f[i] != MOD1 -1)  res = min(res, f[i] + 1);
			for (int i = l; i <= r; i++) f[i] = min(f[i], res);
			if (l == r && r == 4) cout << f[4] << endl;
		}
		Ans();
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
