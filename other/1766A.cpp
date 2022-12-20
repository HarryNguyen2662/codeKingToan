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
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int lim = 10000000;

int dem[lim + 5];
bool ok[lim + 5];

void prepare()
{
	for (int i = 1; i <= 9; i++) 
	{
		ok[i] = true;
		dem[i] = i;
	}

	for (int i = 10; i <= lim; i++)
	{
		dem[i] = dem[i-1];
		if (i%10 == 0 && ok[i/10])
		{
			ok[i] = true;
			dem[i]++;
		}
	} 
}

void solve() 
{
	int n;
	cin >> n;

	cout << dem[n] << "\n";
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
    prepare();
    cin >> testcase;
    while(testcase--)
        solve();
}
