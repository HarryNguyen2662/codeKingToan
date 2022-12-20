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

int a[100005];
void solve() 
{
	int n, dem1 = 0, dem2 = 0, dem3 = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		if (a[i] == 1) dem1++;
		else if (a[i] == 2) dem2++;
		else dem3++;
	}
	if (dem2%2 == 1)
	{
		if (dem1 > 0)
		{
			dem1 = 1;
			dem2 = dem2/2 + 1;
			for (int i = 1; i <= n; i++) if (a[i] == 2)
			{
				if (dem2)
				{
					cout << "1 ";
					dem2--;
				}
				else cout << "3 ";
			}
			else if (a[i] == 1 && dem1)
			{
				cout << "3 ";
				dem1--;
			}
			else cout << "2 ";
		}
		else
		if (dem3 > 0)
		{
			dem3 = 1;
			dem2 = dem2/2 + 1;
			for (int i = 1; i <= n; i++) if (a[i] == 2)
			{
				if (dem2)
				{
					cout << "3 ";
					dem2--;
				}
				else cout << "1 ";
			}
			else if (a[i] == 3 && dem3)
			{
				cout << "1 ";
				dem3--;
			}
			else cout << "2 ";
		}
		else
		{
			cout << "0";
		}
	}
	else
	{
		dem2 = dem2/2;
		for (int i = 1; i <= n; i++) if (a[i] == 2)
		{
			if (dem2)
			{
				cout << "3 ";
				dem2--;
			}
			else cout << "1 ";
		}
		else cout << "2 ";

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
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
