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

bool ok[5005][5005];
int ok1[5005][5005];
int a[5005];

void solve() 
{
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	ok[0][0] = true;
	ok1[n + 1][0] = 1;

	for (int i = 0; i <= n; i++)
	for (int j = 0; j <= k; j++)
	{
		if (ok[i][j] && i < n)
		{
			ok[i + 1][j] = true;
			ok[i + 1][min(k, j + a[i + 1])] = true;
		}
	}

	for (int i = n + 1; i >= 1; i--)
	for (int j = 0; j <= k; j++)
	{
		if (ok1[i][j] && i > 1)
		{
			ok1[i - 1][j] = 1;
			ok1[i - 1][min(k, j + a[i - 1])] = 1;
		}

		if (j)
		ok1[i][j] += ok1[i][j - 1];
	}

	for (int i = 1; i <= n; i++)
	{
		int hehe = 0;
		if (a[i] >= k)
		{
			hehe = 1;
		}
		else
		{
			for (int j = 0; j <= k - 1; j++) 
			if (ok[i - 1][j] && ok1[i + 1][k - 1 - j] - (k - a[i] - j - 1 >= 0 ? ok1[i + 1][k - a[i] - j - 1] : 0) > 0)
			{
				hehe = 1;
				break;
			}
		}

		cout << hehe;
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
    //freopen("SOLDIER.inp","r",stdin); freopen("SOLDIER.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
