#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define fi first
#define se second
#define pb push_back
#define log 16
#define mask(i) (1 << (i))
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

inline int ReadInt() 
{
    char c;
    bool negative = false;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') negative = true;
    int x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (negative) return -x; else return x;
}

void WriteInt(long long x) 
{
    //if (x < 0) putchar('-'), x = -x;
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
int a[100005], pre[100005], lg[100005];
int dp[100005], mn[100005][log+5];
int getmin(int l, int r)
{
	int k = lg[r - l + 1];
	return min(mn[l][k], mn[r-mask(k)+1][k]);
}
void solve() 
{
	int n, k;
	n = ReadInt(); k = ReadInt();
	for (int i = 1; i <= n; i++)
	{
		a[i] = ReadInt();
		lg[i] = lg[i-1];
		while(mask(lg[i]) <= i) lg[i]++; lg[i]--;
	}
	stack<int> st;
	for (int i = 1; i <= n; i++)
	{ 
		while(!st.empty() && a[st.top()] <= a[i]) st.pop();
		if (!st.empty()) pre[i] = st.top(); else pre[i] = 1;
		st.push(i);
	}
	int mx = 0;
	for (int i = 1; i <= n; i++) dp[i] = oo + 10;
	for (int i = 1; i <= n; i++)
	{
		mx = max(mx, a[i]);
		dp[i] = mx;
		mn[i][0] = dp[i];
	}
	for (int i = 1; i <= log; i++) for (int j = 1; j <= n - mask(i)+1; j++) mn[j][i] = min(mn[j][i-1], mn[j+mask(i-1)][i-1]);
	//cout << getmin(5,5) << endl;
	for (int i = 0; i <= n; i++) dp[i] = oo + 10;
	for (int sn = 2; sn <= k; sn ++)
	{
		for (int i = sn; i <= n; i++)
		{
			//cout << getmin(pre[i], i -1) << endl;
			dp[i] = min(getmin(pre[i], i - 1) + a[i], dp[pre[i]]);
		}
		for (int i = 1; i <= n; i++) mn[i][0] = dp[i], dp[i] = oo + 10;
		//if (k == sn) break;
		for (int i = 1; i <= log; i++) 
		for (int j = 1; j <= n - mask(i)+1; j++) 
		mn[j][i] = min(mn[j][i-1], mn[j+mask(i-1)][i-1]);
	}
	WriteInt(mn[n][0]);
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
