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

int dd[22][50005];

void solve() 
{
	int n, m, s;
	cin >> n >> m >> s;

	if (n <= m)
	{
		for (int i = 1; i <= n; i++) for(int j = 1; j <= m; j++)
		{
			int w;
			cin >> w;
			dd[i][j] += w; dd[i][j + 1] -= w;
		} 
		for (int i = 1; i <= s; i++)
		{
			int ti;
			cin >> ti;
			if (ti <= n)
			{
				dd[ti][1]++; 
			}
			else
			{
				for (int j = 1; j <= n; j++)
				{
					dd[j][ti - n] ++; dd[j][ti - n + 1] --;
				}
			}
		}

		int res = 0;

		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			dd[i][j] += dd[i][j-1];
			if (dd[i][j]%3 == 0) res++;
		}

		cout << res;
	}
	else
	{
		for (int i = 1; i <= n; i++) for(int j = 1; j <= m; j++)
		{
			int w;
			cin >> w;
			dd[j][i] += w; dd[j][i + 1] -= w;
		} 
		for (int i = 1; i <= s; i++)
		{
			int ti;
			cin >> ti;
			if (ti > n)
			{
				dd[ti - n][1] ++; 
			}
			else
			{
				for (int j = 1; j <= m; j++)
				{
					dd[j][ti] ++; dd[j][ti + 1] --;
				}
			}
		}

		int res = 0;

		for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			dd[i][j] += dd[i][j-1];
			if (dd[i][j]%3 == 0) res++;
		}

		cout << res;
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
    //
    freopen("LISYS.inp","r",stdin); freopen("LISYS.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
