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
bool maximize(long long &x, const long long &y)
{
	if (x < y)
	{
		x = y;
		return true;
	}
	return false;
}
long long a[3005], c[3005], dp[3005][105], trace[3005][105];
void solve() 
{
	int n, k;
	cin >> n >> k;
	k++;
	for (int i = 1; i <= n; i++)
	cin >> c[i];
	for (int i = 1; i <= n; i++)
	cin >> a[i];
	if (n  == 1)
	{
		cout << c[1]; 
		return;
	}
	dp[1][0] = c[1];
	for (int i = 1; i < n; i++)
	for (int j = 0; j < k; j++)
	if (dp[i][j] > 0)
	{
		//cout <<i << " " << j << endl;
		for (int e = i + 1; e <= min(1ll*n, i + a[i]); e++)
		if (maximize(dp[e][j+1], dp[i][j] + c[e])) trace[e][j+1] = i;
	}
	long long res = 0;
	int luu = 0;
	for (int i = 1; i <= k; i++) if (maximize(res, dp[n][i])) luu = i;
	if (luu == 0)
	{
		cout << -1;
		return;
	}
	//cout << luu << endl;
	cout << res << " "<< luu-1 << "\n";
	vector<int> ldk;
	n = trace[n][luu]; luu--;
	for(; luu; luu--)
	{
		ldk.pb(n);
		n = trace[n][luu];
	}
	reverse(ALL(ldk));
	for (auto v : ldk) cout << v << " ";
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
