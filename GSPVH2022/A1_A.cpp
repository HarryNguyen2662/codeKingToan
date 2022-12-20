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

int dem[10][10], dem1[10][10];
void solve() 
{
	for (int i = 1; i <= 9; i++) for (int j = 1; j <= 9; j++) 
	{
		char x;
		cin >> x;
		dem[i][x - '0']++;
		dem1[j][x - '0']++; 
	}
	int so = -1, x = -1, y = -1;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (dem[i][j] == 0) 
			{
				so = j;
				x = i;
				break;
			}
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		if (dem1[i][so] == 0) 
			{
				y = i;
				break;
			}
	}
	cout << x << " " << y << " " << so;
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("sodoku.inp","r",stdin); freopen("sodoku.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
