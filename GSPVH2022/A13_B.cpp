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

const int oo = 2e9 + 10;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll cal(ll y, ll x, bool ok = true)
{
	if (x >= y) return 0;

	ll re = y - x + 1;

	if (ok)
	{
		return (re + (x%2 == 0))/2;
	}
	else
	{
		return (re + (x%2 != 0))/2;
	}
}

void solve() 
{
	int n;
	cin >> n;
	int A1 = -oo, A2 = oo, B1 = -oo, B2 = oo;
	for (int i = 1; i <= n; i++)
	{
		int a1 = oo, a2 = -oo, b1 = oo, b2 = -oo;
		for (int j = 1; j <= 4; j++)
		{
			int x, y;
			cin >> x >> y;
			a1 = min(a1, x + y);
			a2 = max(a2, x + y);
			b1 = min(b1, x - y);
			b2 = max(b2, x - y);
		}

		// cout << a1 << " " << a2 << " " << b1 << " " << b2 << endl;

		A1 = max(A1, a1);
		A2 = min(A2, a2);
		B1 = max(B1, b1);
		B2 = min(B2, b2);
	}

	B2--; A2--; A1++; B1++;
	// cout << A1 << " " << A2 << " " << B1 << " " << B2 << endl;
 
	cout << 1ll*cal(A2, A1)*cal(B2, B1) + 1ll*cal(A2, A1, 0)*cal(B2, B1, 0);
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("dimghinh.inp","r",stdin); freopen("dimghinh.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
