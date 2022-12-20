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

long long lt[100], ltt[100];

void solve() 
{
	long long n;
	cin >> n;	

	long long res = 0;

	for (int ii = 0; ii <= 60; ii++)
	{
		for (int jj = 0; jj <= 38; jj++)
		if (n/lt[ii] >= ltt[jj] && n >= lt[ii]*ltt[jj])
		{
			//cout << ii << " " << jj << endl;
			int i = ii, j = jj;
			long long nn = n;
			long long re = 1;
			nn -= lt[i]*ltt[j];
			while(true)
			{
				if (j == 0) break;
				j--;
				i++;
				if (i == 61) break;
				while(j > 0 && oo18/lt[i] < ltt[j]) j--;
				if (nn/lt[i] < ltt[j]) break;
				re++;
				nn -= lt[i]*ltt[j];
			}
			res = max(res, re);

			i = ii; j = jj;  re = 1;
			nn = n - lt[i]*ltt[j];
			while(true)
			{
				if (i == 0) break;
				j++;
				i--;
				if (j == 39) break;
				while(i > 0 && oo18/lt[i] < ltt[j]) i--;
				if (nn/lt[i] < ltt[j]) break;
				re++;
				nn -= lt[i]*ltt[j];
			}
			res = max(res, re);
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
    int testcase = 1;
    lt[0] = ltt[0] = 1;

    for (int i = 1; i <= 60; i++) lt[i] = lt[i-1]*2;
    for (int i = 1; i <= 38; i++) ltt[i] = ltt[i-1]*3;
    cin >> testcase;
    while(testcase--)
        solve();
}
