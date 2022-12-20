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

long long power(long long x, long long y)
{
	if (y == 0) return 1;
	long long xx = power(x, y/2);
	if (y%2) return xx*xx%MOD1*x%MOD1; else return xx*xx%MOD1;
}

int a[100005], pre[100005], suf[100005];

long long lt[100005], fact[100005], infact[100005];

long long c(int k, int n)
{
	return fact[n]*infact[k]%MOD1*infact[n-k]%MOD1;
}

long long f(int l, int r)
{
	if (l == r)
	{
		return 1;
	}

	if (pre[l] >= r - l + 1)
	{
		return lt[r - l];
	}

	if (pre[l] && suf[r])
	{
		long long le = 0;
		for (int i = 0; i <= min(pre[l], suf[r]); i++)
		le = (le + c(i, pre[l])*c(i, suf[r])%MOD1)%MOD1;

		return le*f(l + pre[l], r - suf[r])%MOD1;
	}

	long long su = a[l], suu = a[r];

	while(true)
	{
		if (l >= r) return 1;
	
		if (su < suu)
		{
			l++;
			su += a[l];
		}
		else if (suu < su)
		{
			r--;
			suu += a[r];
		}
		else 
		{
			break;
		}
	}

	l++; r--;

	if (pre[l] >= r - l + 1)
	{
		return lt[r  - l + 2];
	}

	long long le = 0;
	for (int i = 0; i <= min(pre[l], suf[r]) + 1; i++)
	le = (le + c(i, pre[l] + 1)*c(i, suf[r] + 1)%MOD1)%MOD1;

	
	return le*f(l + pre[l], r - suf[r])%MOD1; 
  
}

void solve() 
{
	int n;
	cin >> n;


	for (int i = 0; i <= n + 1; i++) suf[i] = pre[i] = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == 0) suf[i] = suf[i-1] + 1;
	}


	for (int i = n; i; i--) 
	if (a[i] == 0) pre[i] = pre[i + 1] + 1;

	cout << f(1, n) << "\n";

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
 
 	lt[0] = 1; fact[0] = 1;
 	for (int i = 1; i <= 100000; i++) 
 	{
 		fact[i] = 1ll*i*fact[i-1]%MOD1;
 		lt[i] = lt[i-1]*2%MOD1;
 	}

 	infact[100000] = power(fact[100000], MOD1 - 2);

 	for (int i = 100000; i; i--) infact[i-1] = 1ll*i*infact[i]%MOD1;

    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
