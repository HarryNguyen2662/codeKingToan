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

int s[5005][5005];

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			char x;
			cin >> x;
			s[i][j] = x - '0';
		}

	int res = 0;

	for (int i = 1; i <= n; i++)
	{
		int d = 0;
		for (int j = n; j; j--)
		{
			s[i][j] ^= d;
			if (s[i][j] != s[i + 1][j])
			{
				s[i][j] ^= 1;
				res++; d ^= 1;
			}
		}
	}
	

	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= n; j++) cout << s[i][j]; cout << endl;
	// }

	cout << res;

}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    //
    freopen("TABLETIP.inp","r",stdin); freopen("TABLETIP.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
