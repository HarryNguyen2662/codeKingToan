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

int sum[500005], f[500005], dem[5][5];

void solve() 
{
	int n;
	cin >> n;
	long long res = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		x %= 3;
		sum[i] = sum[i-1] + x; sum[i] %= 3;
		f[i] = (x*sum[i]%3 + f[i-1])%3;
		//cout << sum[i] << " " << f[i] << endl;
	}

	dem[sum[0]][f[0]]++;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++) for (int e = 0; e < 3; e++)
		if ((sum[i]*(sum[i-1] - j + 3)%3 - f[i-1] + e + 9)% 3 == 0)
		{
			res += dem[j][e];
		//	cout << i << " " << j << " " << e << " " << dem[j][e] << endl;
		}
		dem[sum[i]][f[i]]++;
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
