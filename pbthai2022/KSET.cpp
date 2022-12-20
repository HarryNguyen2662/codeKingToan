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

const int maxn = 1000000;

ll fact[maxn + 5], infact[maxn + 5], f[maxn + 5];
int prime[maxn + 5], sl[maxn + 5], dem[maxn + 5];

long long power(long long x, long long y)
{
	if (y == 0) return 1;
	long long xx = power(x, y/2);
	if (y%2) return xx*xx%MOD*x%MOD; else return xx*xx%MOD;
}

void prepare()
{
	fact[0] = 1;

	for (int i = 1; i <= maxn; i++)
	{
		fact[i] = 1ll*i*fact[i - 1]%MOD;
		
		prime[i] = i;
	}

	infact[maxn] = power(fact[maxn], MOD - 2);

	for (int i = maxn; i; i--)
	{
		infact[i-1] = 1ll*i*infact[i]%MOD;
	}
	
	sl[1] = 0; f[1] = 1;

	for (int i = 2; i <= maxn; i++)
	{
		if (prime[i] == i)
		for (int j = 2*i; j <= maxn; j += i)
		prime[j] = i;
	
		sl[i] = sl[i - 1]; f[i] = f[i - 1];

		if (prime[i] == i) sl[i]++;
		
		int val = i;
		int pre = -1;

		while(val != 1)
		{
			int w = prime[val]; val /= w;
			if (w != pre)
			{
				if (pre != -1)
				{
					f[i] = f[i]*1ll*dem[pre]%MOD;
				}
				
				if (dem[w])
				f[i] = f[i]*power(dem[w], MOD - 2)%MOD;
				dem[w]++;
				pre = w;
			}
			else dem[w]++;
		}

		if (pre != -1)
		{
			f[i] = f[i]*1ll*dem[pre]%MOD;
		}
		// if (i == 4) cout << dem[2] << " " << f[4] << endl;

	}

}

ll c(int k, int n)
{
	if (k > n) return 0;

	return fact[n]*infact[k]%MOD*infact[n - k]%MOD;
}

ll calc(int n, int k)
{
	if (k > n) return 0;

	if (k == n) return 1;


	ll ans = 0;

	for (int i = 0; i <= k; i++)
	{
		ans += (i%2 == 0 ? 1ll : -1ll)*c(i, k)*power(k - i, n)%MOD; ans %= MOD; if (ans < 0) ans += MOD;
	}


	return ans*infact[k]%MOD;
}


void solve() 
{
	int n, k;

	cin >> n >> k;

	if (n == 1)
	{
		if (k == 1)
		{
			cout << "1\n";
		}
		else
		{
			cout << "0\n";
		}
		return;
	}


	cout << (calc(sl[n], k) + calc(sl[n], k - 1))%MOD*f[n]%MOD << "\n";
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
    
    prepare();

    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
