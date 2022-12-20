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

long long dp[100005][15];
int n;


long long f(int id, int du)
{
	if (id == n)
	{
		return dp[id][du] = (du == 0);
	}
	if (dp[id][du] != -1) return dp[id][du];
	long long &res = dp[id][du];
	res = 0;
	for (int digit = (id == 0); digit <= 9; digit ++) if (digit != 1 && digit != 3)
	{
		if (id == n - 1) 
		{
			res = (res + f(id + 1, (du - digit*9%13 + 13)%13))%MOD;
		}
		else res = (res + f(id + 1, (du*10 + digit)%13))%MOD;
	}
	return res;
}

void solve() 
{
	cin >> n;
	for (int i = 0; i <= n + 1; i++) for (int j = 0; j <= 13; j++) dp[i][j] = -1;
	cout << f(0, 0);
	// int dem = 0;
	// for (int i = 10000; i <= 99999; i++) if (i%13 == 0) {
	// 	int va = i; bool kt = true;
	// 	while(va)
	// 	{
	// 		if (va%10 == 3 || va%10 == 1) kt = false;
	// 		va /= 10;
	// 	}
	// 	if (kt)
	// 	{
	// 		//cout << i << endl;
	// 		dem++;
	// 	}
	// }
	// cout << dem << endl;
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
