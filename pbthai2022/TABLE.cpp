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

long long su[5005][5005];

long long getsum(int u, int v, int dai)
{
	return su[u][v] - su[u - dai][v] - su[u][v - dai] + su[u - dai][v - dai];
}

void solve() 
{
	int n, m, k, res = 0;;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		int l = 1;
		for (int j = 1; j <= m; j++)
		{
			cin >> su[i][j];
			su[i][j] += su[i-1][j] + su[i][j-1] - su[i-1][j-1];

			while(l < j && (i - j + l <= 0 || getsum(i, j, j - l + 1) > k)) l++;

			if (res < j -l + 1 && i - j + l > 0 && getsum(i, j, j - l + 1)  <= k) res = j - l + 1;
		}
	}

	cout << res;
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
