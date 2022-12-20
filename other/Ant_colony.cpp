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
int GCD[100005][log+5], lg[100005];
vector<int> ldk[100005];	
int getgcd(const int &l, const int &r)
{
	int k = lg[r - l  + 1];
	return __gcd(GCD[l][k], GCD[r - mask(k) + 1][k]);
}	
void solve() 
{
	int n;
	vector<int> diffval;
	n = ReadInt();
	for (int i = 1; i <= n; i++)
	{
		int val = ReadInt();
		GCD[i][0] = val;
		diffval.pb(val);
		lg[i] = lg[i-1];
		while(mask(lg[i]) <= i) lg[i]++; lg[i]--;
	}
	
	sort(ALL(diffval)); diffval.resize(unique(ALL(diffval)) - diffval.begin());
	for (int j = 1; j <= log; j++) for (int i = 1; i <= n - mask(j) + 1; i++) 
	GCD[i][j] = __gcd(GCD[i][j-1], GCD[i+mask(j-1)][j-1]);
	
	for (int i = 1; i <= n; i++)
	{
		int val = lower_bound(ALL(diffval), GCD[i][0]) - diffval.begin();
		ldk[val].pb(i);
	}

	int q = ReadInt();
	while (q--)
	{
		int l = ReadInt(), r = ReadInt();
		int val = getgcd(l, r);
		int id = lower_bound(ALL(diffval), val) - diffval.begin();
		int sl = 0;
		if (diffval[id] == val)
		{
			sl = upper_bound(ALL(ldk[id]), r) - lower_bound(ALL(ldk[id]), l); 
		}
		cout << r - l + 1 - sl << "\n";
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
