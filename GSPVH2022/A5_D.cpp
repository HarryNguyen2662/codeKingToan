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

long long lt[20];

void solve() 
{
	long long x, y, z;
	cin >> x >> y >> z;
	lt[0] = 1;
	int st = 0;
	for (int i = 1; i <= 19; i++) 
	{
		lt[i] = lt[i-1]*10;
		if (!st && lt[i] > x)
		{
			st = i;
		}
	}

	for (int i = st; i <= 19; i++)
	{
		long long sobuoc = lt[i] - 1;
		while(sobuoc%y != x%y) sobuoc--;
		sobuoc = (sobuoc - x)/y + 1;
		if (z/sobuoc + (z % sobuoc != 0) > i)
		{
			z -= 1ll*i*sobuoc;
			x += sobuoc*y;
		}
		else
		{
			long long l = 1, r = sobuoc;
			while(l <= r)
			{
				long long mid = (l + r)/2;
				if (z/mid + (z % mid != 0) > i) l = mid + 1; else r = mid - 1;
			}

			z -= 1ll*i*r;

			x += y*r;

			for (int j = i - 1; j >= 0; j--)
			{
				cout << x/lt[j];
				x %= lt[j];
				z--;
				if (z == 0) return;
			}
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
    //freopen("digits.inp","r",stdin); freopen("digits.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
