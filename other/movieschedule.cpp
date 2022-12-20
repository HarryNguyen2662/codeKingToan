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
long long dp[1500000];
int ti[100];
vector<int> ldk[100];
void solve() 
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> ti[i];
		int m;
		cin >> m;
		for (int j = 1; j <= m; j++)
		{
			int val;
			cin >> val;
			ldk[i].pb(val);
		}
	} 
	for (int i = 0; i < mask(n); i++)
	{
		//cout << i << " " << dp[i] << endl;
		for (int j = 0; j < n; j++) if (!ck(i, j))
		{
			int w = upper_bound(ALL(ldk[j+1]), dp[i]) - ldk[j+1].begin() - 1;
			if (w != -1) 
			{
				dp[i^mask(j)] = max(dp[i^mask(j)], dp[i] +  max(0, ti[j+1] - dp[i] + ldk[j+1][w]));
			}
		}
	}
	int res = oo;
	for (int i = 0; i < mask(n); i++)
	if (dp[i] >= k)
	{
		//cout << i << endl;
		res = min(res, getbit(i));
	}
	if (res == oo)
	{
		cout << -1;
		return;
	}
	cout << res;
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
