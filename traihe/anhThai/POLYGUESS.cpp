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

long long power(long long a, long long b)
{
	if (b == 0) return 1;
	long long aa = power(a, b/2);
	if (b%2) return aa*aa%MOD*a%MOD; else return aa*aa%MOD;
}

long long a[20][20], c[20][20];

void gauss(int lim)
{
	//cout << "aloo " << endl;

	for (int i = 1; i <= lim; i++)
	for (int j = 0; j <= lim; j++) c[i][j] = a[i][j];
	// for (int i = 1; i <= lim; i++) cout << c[lim][i] << " ";

	for (int i = 1; i <= lim; i++)
	{
		for (int j = i; j <= lim; j++)
		if (c[j][i] == 0)
		{
			swap(c[j], c[i]);
			break;
		} 
		for (int j = i + 1; j <= lim; j++)
		{
			long long w = c[j][i]*power(c[i][i], MOD-2)%MOD;
			for (int e = i ; e <= lim; e++)
			{
				c[j][e] = (c[j][e] - c[i][e]*w%MOD + MOD)%MOD;
			}
			c[j][0] = (c[j][0] - c[i][0]*w%MOD + MOD)%MOD;
		}
	}
	for (int i = lim; i; i--)
	{
		c[i][0] = c[i][0]*power(c[i][i], MOD-2)%MOD;
		for (int j = 1; j < i; j++)
		{
			c[j][0] = (c[j][0] - c[j][i]*c[i][0]%MOD + MOD)%MOD;
		}
	}
		 
}

void solve() 
{
	//gauss(2);
	long long ck1, ck2;
	long long w;
	long long x = rng()%oo + 1, xx;
	cout << "ask 0" << endl;
	cin >> w;
	cout << "ask " << x << endl;
	cin >> ck1;
	xx = rng()%oo + 1;
	cout << "ask " << xx << endl;
	cin >> ck2;
	if (w == ck1 && ck2 == w)
	{
		cout << "degree " << 0 << endl;
		return;
	}
	
	for (int i = 1; i <= 10; i++)
	{
		
		a[i][0] = (ck1 - w + MOD)%MOD;
		a[i][1] = x; 
		for (int j = 2; j <= 10; j++) a[i][j] = a[i][j-1]*x%MOD;
		gauss(i);
		ck1 = ck2; x = xx;
		xx = rng()%oo + 1;
		cout << "ask " << xx << endl;
		cin >> ck2;
		long long res1 = w;
		long long e = x;
		for (int j = 1; j <= i; j++)
		{
			res1 = (res1 + c[j][0]*e%MOD)%MOD;
		//	cout << i << " " <<  c[j][0] << " " << e << endl;
			e = e*x%MOD;
		//	cout << c[j][0] << " ";
		}
		long long res2 = w;
		e = xx;
		for (int j = 1; j <= i; j++)
		{
			res2 = (res2 + c[j][0]*e%MOD)%MOD;
			e = e*xx%MOD;
		//	cout << i << " " <<  c[j][0] << " " << a[i][j] << endl;
		}
		if (res1 == ck1 && res2 == ck2)
		{
			cout << "degree " << i << endl;
			return;
		}
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
