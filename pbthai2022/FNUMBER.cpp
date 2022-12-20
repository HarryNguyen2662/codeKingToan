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

const int adu = mask(5) - 1;
const int lim = 1e4;	

int dp[10004][9][35];

int f(int id, int du, int msk)
{
	if (dp[id][du][msk] != -1) return dp[id][du][msk];
	
	if (id == lim)
	{
		return dp[id][du][msk] = (du == 3 || du == 6);
	}

	int &res = dp[id][du][msk]; res = 0;

	for (int j = 0; j <= 9; j++)
	if (!ck(msk, j%5))
	{
		int newdu = (du + j)%9;
		int newmsk = msk; 
		
		if (newmsk || j)
		{ 
			newmsk |= mask((5 - j%5)%5);
		}
		
		res = res + f(id + 1, newdu, newmsk); if (res >= MOD) res -= MOD; 
	}

	return res;
}

void solve() 
{	
	string l, r;
	cin >> l >> r;
	int res =0;

	int curdu = 0;
	int curmsk = 0;
	int n = (int)r.size();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < r[i] - '0'; j++)
		if (!ck(curmsk, j%5))
		{
			int newmsk = curmsk;
			if (curmsk || j)
			{ 
				newmsk |= mask((5 - j%5)%5);

			}
			res = res + f(lim - (n - i - 1), (curdu + j)%9, newmsk); 
			if (res >= MOD) res -= MOD;

		}
		curdu = (curdu + (r[i] - '0'))%9;
		//cout << r[i] - '0' << " " << curmsk << endl;
		if (ck(curmsk, (r[i] - '0')%5))
		{
			curmsk = -1; break;
		} else
		{
			int j = r[i] - '0';
			curmsk |= mask((5 - j%5)%5);

		}
	}
	if (curmsk != -1) {
		res = res + f(lim, curdu, curmsk); 
			if (res >= MOD) res -= MOD;
	}

	curdu = 0;
	curmsk = 0;
	n = (int)l.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < l[i] - '0'; j++)
		if (!ck(curmsk, j%5))
		{
			int newmsk = curmsk;
			if (curmsk || j)
			{ 
				newmsk |= mask((5 - j%5)%5);
			}
			res = res - f(lim - (n - i - 1), (curdu + j)%9, newmsk) + MOD; 
			if (res >= MOD) res -= MOD;
		}
		curdu = (curdu + (l[i] - '0'))%9;
		if (ck(curmsk, (l[i] - '0')%5))
		{
			 break;
		} else
		{
			int j = l[i] - '0';
			curmsk |= mask((5 - j%5)%5);
		}
	}
	

	cout << res << "\n";

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

    for (int i = 0; i <= lim; i++)
    for (int j = 0; j < 9; j++)
    for (int msk = 0; msk <= adu; msk++) dp[i][j][msk] = -1;

    int testcase = 1;
   	cin >> testcase;
    while(testcase--)
        solve();
}
