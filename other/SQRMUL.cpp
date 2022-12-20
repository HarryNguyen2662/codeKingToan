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
int snt[1000005], val;
int dem[1000005], re[1000005];
long long power(long long x, long long y)
{
	if (y == 0) return 1;
	long long xx = power(x, y/2);
	if (y%2) return xx*xx%MOD*x%MOD; else return xx*xx%MOD;
}
void solve() 
{
	int n;
	vector<int> qa;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int val;
		vector<int> ldk;
		cin >> val;
		while(val > 1)
		{
			if (dem[snt[val]] == 0) ldk.pb(snt[val]);
			dem[snt[val]]++;
			val /= snt[val];
		}
		for (auto v : ldk) 
		{
			if (re[v] == 0) qa.pb(v);
			re[v] = max(re[v], dem[v]); dem[v] = 0;
		}
	}
	long long res = 1;
	for (auto v : qa)
	{
		if (re[v]%2) re[v]++;
		res = res*power(v, re[v])%MOD;
		re[v] = 0;
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
    //freopen("SQRMUL.inp","r",stdin); freopen("SQRMUL.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    for (int i = 1; i <= 1000000; i++) snt[i] = i;
    for (int i = 2; 1ll*i*i <= 1000000; i++)
    if (snt[i] == i) for (int j = 2*i; j <= 1000000; j += i) snt[j] = i;
    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
