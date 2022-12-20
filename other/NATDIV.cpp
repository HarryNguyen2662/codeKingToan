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

const int lim = 1000000;

int pr[lim + 5];
ll sl[lim + 5], su[lim + 5];

void solve() 
{
	for (int i = 1; i <= lim; i++) 
	{
		pr[i] = i;
		sl[i] = 1;
		su[i] = 1;
	}

	for (int i = 2; i <= lim; i++) if (pr[i] == i)
	for (int j = i; j <= lim; j += i) 
	{
		int suu = 1;
		int cur = 1;
		int de = 1;

		while(pr[j]%(i*i) == 0)
		{
			cur = cur*i*i;
			suu += cur/i + cur;
			de += 2;
			pr[j] /= (i*i);
		}

		if (pr[j]%i == 0) de++, suu += cur*i, pr[j] /= i;

		sl[j] *= de; su[j] = 1ll*suu*su[j];
	}	

	for (int i = 1; i <= lim; i++) 
	{
		sl[i] += sl[i-1]; su[i] += su[i-1];
	}

	int t;
	cin >> t;
	while(t--)
	{
		int l, r;
		cin >> l >> r;
		cout << sl[r] - sl[l - 1] << " " << su[r] - su[l - 1] << "\n";
	}
}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    // //
    freopen("NATDIV.inp","r",stdin); freopen("NATDIV.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
