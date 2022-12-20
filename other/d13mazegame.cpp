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

inline long long ReadInt() 
{
    char c;
    bool negative = false;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') negative = true;
    long long x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (negative) return -x; else return x;
}

void WriteInt(long long x) 
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
vector<pair<int,int>> ldk[2005];
void solve() 
{
	int n;
	cin >> n;
	int sl = 0;
	for (int i = 2; i <= n - (n%2); i += 2)
	{
		for (int j = 1; j <= sl; j++)
		{
			ldk[j].pb({i - 1, j});
			ldk[j].pb({i, j + sl});
		}
		sl++;
		for (int j = 1; j <= sl-1; j++) ldk[sl].pb({i, j}), ldk[sl].pb({i-1, j + sl - 1});
		ldk[sl].pb({i-1, i});	
		//cout << sl << endl;	
	}
	cout << n/2 << "\n";
	for (int i = 1; i <= sl; i++)
	{
		cout << n-1 << "\n";
		for (auto v : ldk[i]) cout << v.fi << " " << v.se <<"\n";
		if (n%2) cout << n << " " << i << "\n";
	}
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
