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

int dem[105];

void solve() 
{
	int n, k, a = 0, b = 0;
	for (int i = 1; i <= 100; i++) dem[i] = 0;

	cin >> n >> k;
//cout << n << endl;

	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		dem[x]++;
	}

	for (int i = 1; i <= 100; i++)
	{
		if (dem[i] > 2)
		{
			cout << "NO\n";
			return;
		}		
		if (dem[i] == 1)
		{
			if (a < k) a++; else if (b < k) b++; else
			{
				cout << "NO\n";
				return;
			}
		}
		if (dem[i] == 2)
		{
			if (a < k && b < k)
			{
				a++; b++;
			}
			else
			{
				cout << "NO\n";
				return;
			}
		}
	}

	cout << "YES\n";

}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    int dem = 0;
    cin >> testcase;
    while(testcase--)
    {
    	dem++;
    	cout << "Case #" << dem << ": ";
        solve();
    }
}
