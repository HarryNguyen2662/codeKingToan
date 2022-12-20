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
const long long MOD = 998244353;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Matrix
{	
	int c[8][8];

	Matrix()
	{

		for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++)  c[i][j] = 0;

		for (int i = 0; i < 4; i++) c[i][0] = 1;
		
		c[0][1] = c[0][2] = 1;	

		c[0][3] = 2; c[1][3] = c[2][3] = 1; 
		
		c[4][4] = 1; c[5][4] = 1; c[6][4] = 1; c[7][4] = 1;

		c[0][5] = 3; c[4][5] = 1;

		c[0][6] = 3; c[4][6] = 1;

		c[0][7] = 6; c[1][7] = 3; c[2][7] = 3; c[4][7] = 2; c[5][7] = 1; c[6][7] = 1; 
	}

	Matrix operator * (const Matrix &b) const
    {
        Matrix res , a = *this;
        for(int i = 0 ; i < 8; i++) for(int j = 0 ; j < 8; j++)
        {
            res.c[i][j] = 0;
            for(int e = 0 ; e < 8; e++) 
            {
            	res.c[i][j] += 1ll*a.c[i][e] * b.c[e][j] % MOD; 
            	if (res.c[i][j] >= MOD) res.c[i][j] -= MOD;
            }
        }
        return res;
    }
};

Matrix power(ll k)
{
	Matrix res;

	int st = 0;

	for (int i = 60; i >= 0; i--)
	if (ck(k, i))
	{
		st = i - 1; break;
	}

	res = Matrix();

	for (; st >= 0; st--)
	{
		res = res*res;
		if (ck(k, st)) res = res*Matrix();
	}

	return res;
} 
 
void solve() 
{
	ll n;
	cin >> n;
	if (n == 2)
	{
		cout << "12"; return;
	}


	n -= 2;
	Matrix res; res = power(n);

	// for (int i = 0; i < 8; i++) 
	// {
	// 	for (int j = 0; j < 8; j ++) cout << res.c[i][j] << " ";

	// 	cout << "\n";
	// }

	ll ans = 0;

	for (int i = 4; i < 8; i++)
	{
		ans = ans + 1ll*res.c[0][i] + 1ll*res.c[1][i] + 1ll*res.c[2][i] +  2ll*res.c[3][i];
		ans %= MOD;
		ans = ans + 3ll*res.c[5][i] + 3ll*res.c[6][i] + 6ll*res.c[7][i];
		ans %= MOD;
	}


	cout << ans % MOD;
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
