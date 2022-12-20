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

map<int,int> du[1005], de;

long long a[1005], d[1005];
int s[1005][1095];

void solve() 
{
	int n, k;
	cin >> n >> k;

	d[1] = 1;
	for (int i = 2; i <= k; i++) d[i] = d[i-1]*3;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			cin >> s[i][j];
			a[i] += d[j]*s[i][j];
		}

		for (int j = 1; j < i; j++)
		{
			long long st = 0;
			for (int e = 1; e <= k; e++) 
			{
				st += 1ll*((6 - s[j][e] - s[i][e])%3)*d[e];
			}


			de[st]++; du[i][st]++; du[j][st]++;
		}
	}
	long long res = 0;

	for (int i = 1; i <= n; i++)
	{
		long long val = de[a[i]];
		res += val*(val-1)/2;

		for (int j = 1; j <= n; j++)
		{
			val = du[j][a[i]];

			res -= val*(val-1)/2;
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
