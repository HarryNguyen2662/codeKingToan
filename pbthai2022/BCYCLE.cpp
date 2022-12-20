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

int n;
long long fact[100005], infact[100005];
long long power(long long a, long long b)
{
	if (b == 0) return 1;
	long long aa = power(a, b/2);
	if (b%2) return aa*aa%MOD*a%MOD; else return aa*aa%MOD;
}

long long c(int a, int b)
{
	return fact[b]*infact[a]%MOD*infact[b - a]%MOD;
}

long long cal(int st, int ed, int step)
{
	long long res = 0;

	st %= (3*n); ed %= (3*n); st /=3; ed /= 3;

	for (int i = 0; i <= 2*step; i++)
	if (((st + i - step)%n + n)%n == ed)
	{
		res += c(i, 2*step);
	}
	
	for (int i = 1; i <= step; i++) res = res*2%MOD;
	
	return res;
}

void solve() 
{
	int k, s, t;
	cin >> n >> k >> s >> t;

	fact[0] = 1;
	
	for (int i = 1; i <= k; i++)
	{
		fact[i] = 1ll*i*fact[i-1]%MOD;
	}

	infact[k] = power(fact[k], MOD - 2);

	for (int i = k; i; i--) 
	{
		infact[i-1] = 1ll*i*infact[i]%MOD;
	}

	if (t%3 == 1) swap(s, t);

	if (s%3 == 1)
	{
		if (t%3 == 1)
		{
			if (k%2)
			{
				cout << 0;
				return;
			}
			cout << cal(s, t, k/2);
		}
		else
		{
			if (k%2 == 0)
			{
				cout << 0;
				return;
			}
			t = t + (3 - t%3)%3;
			cout << (cal(s, t + 1, k/2) +  cal(s, t - 2, k/2))%MOD; 
		}
	}
	else
	{
		if (k%2 || k < 2)
		{
			cout << 0;
			return;
		}
		
		k -= 2;
		s = s + (3 - s%3)%3;
		t = t + (3 - t%3)%3;

		cout << (cal(s + 1, t + 1, k/2) + cal(s - 2, t + 1, k/2) + cal(s + 1, t - 2, k/2) + cal(s -2, t-2, k/2))%MOD;
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
