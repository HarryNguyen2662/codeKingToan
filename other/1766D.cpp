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
int pe[lim + 5];
prepare()
{
	for (int i = 1; i <= lim; i++) pe[i] = i;

	for (int i = 2; i <= lim; i++)
	if (pe[i] == i)
	for (int j = 2*i; j <= lim; j += i) pe[j] = i;
}

int gcd(int x, int y)
{
	if (y == 0)
	{
		return x;
	}

	return gcd(y, x%y);
}

void solve() 
{
	int x, y;
	cin >> x >> y;
	if (x < y) swap(x, y);

	if (x - y == 1)
	{
		cout << "-1\n"; return;
	}

	if (gcd(x, y) != 1)
	{
		cout << "0\n"; return;
	}

	
	if (x == y)
	{
		cout << "1\n"; return;
	}

	x -= y;

	int ans = oo;

	while(x > 1)
	{
		int cur = pe[x];
		ans = min(ans, cur - y%cur);
		x /= cur;
	}

	cout << ans << "\n";
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
