#include<bits/stdc++.h>

using namespace std;

#define NMOD 4
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

const long long HSMOD[4] ={(long long)1e9 + 2277, (long long)1e9 + 5277, (long long)1e9 + 8277, (long long)1e9 + 9277};

const int MAXN = 500000;
const long long base = 9012005;

long long pw[NMOD][MAXN + 5], hs[NMOD][MAXN + 5], hs1[NMOD][MAXN + 5], a[MAXN + 5], b[MAXN + 5];

void preparepw()
{
    for (int i = 0; i < NMOD; i ++)
    {
        pw[i][0] = 1;
        for (int j = 1; j <= MAXN; j++) pw[i][j] = pw[i][j-1]* base % HSMOD[i];
    }
}

long long get(int ti, int l, int r)
{
	return (hs[ti][r] - hs[ti][l - 1]*pw[ti][r - l + 1] + HSMOD[ti]*HSMOD[ti])%HSMOD[ti];
}

long long get1(int ti, int l, int r)
{
	return (hs1[ti][r] - hs1[ti][l - 1]*pw[ti][r - l + 1] + HSMOD[ti]*HSMOD[ti])%HSMOD[ti];
}

void solve() 
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}


	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		
		for (int j = 0; j < NMOD; j++)
		{
			hs[j][i] = (hs[j][i-1]*base + a[i])%HSMOD[j];
			hs1[j][i] = (hs1[j][i-1]*base + b[i])%HSMOD[j];	
		}
	}

	for (int i = 1; i <= n; i++)
	{
		bool kt = true;
		for (int j = 0; j < NMOD; j++)
		{
			if (get(j, i, n) != get1(j, 1, 1 + n - i))
			{
				kt = false; break;
			}	
			if (i > 1 && get(j, 1, i - 1) != get1(j, n - i + 2, n))
			{
				kt = false; break;
			}
		}

		if (kt)
		{
				int val = i - 1;
				if (k == 0 && val == 0)
				{
					cout << "YES\n";
					return;
				}

				long long l = k - 1, r = 1ll*k*(n - 1);
				long long de = 0, de1 = 0;

				if (l >= val) de = (l - val)/n + 1;
				if (r >= val) de1 = (r - val)/n + 1;

				if (de1 - de > 0)
				{
					cout << "YES\n";
					return;
				}
		}
	}

	cout << "NO\n";
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
    int dem = 0;
    preparepw();

    cin >> testcase;
    while(testcase--)
    {
    	dem++;
    	cout << "Case #" << dem << ": ";
        solve();
    }
}
