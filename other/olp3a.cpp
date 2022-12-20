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
long long a[3005];
int n;
long long res1 = 0, res2 = 0, res3= 0;
void sub1()
{
	for (int i = 3; i <= n; i++)
	{
		int l = 1;
		for (int j = i - 1; j >= 2; j--)
		{
			while(l < j && a[l]*a[l] + a[j]*a[j] <= a[i]*a[i]) l++;
			if (j >= l) res1 += (j - l);
		}
	}

}
void sub2()
{
	long long res = 0;
	for (int i = 3; i <= n; i++)
	{
		int l = 1, ll = 1;
		for (int j = i - 1; j >=  2; j--)
		{
			while(l < j && a[l]*a[l] + a[j]*a[j] < a[i]*a[i]) l++;
			while(ll + 1 < j && a[ll+1]*a[ll+1] + a[j]*a[j] <= a[i]*a[i]) ll++;
			if (a[l]*a[l] + a[j]*a[j] == a[i]*a[i] && ll >= l && j > ll) res2 += (ll - l + 1);
		}
	}
}
void sub3()
{
	for (int i = 3; i <= n; i++)
	{
		int ll = 1;
		for (int j = i-1; j >= 2; j--)
		{
			while(ll < j && a[ll] + a[j] <= a[i]) ll++;
			if (j >= ll) res3 += (j - ll);
		}
	}
}
void solve() 
{
	int t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	if (t == 1)
	{
		sub1(); cout << res1;
	}
	else if (t == 2)
	{
		sub2(); cout << res2;
	}
	else
	{
		sub1(); sub2(); sub3(); cout << res3- res1-res2;
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
