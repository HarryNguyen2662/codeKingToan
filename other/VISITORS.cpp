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
struct BIT
{
    vector<long long> seg;
    int n;
    void resize(int _n)
    {
        n = _n;
        seg.assign(_n + 5, oo15);
    }
    
    void updateup(int id, long long val)
    {
        for (; id <= n; id += (id&(-id))) seg[id] = min(seg[id], val);
    }
    void updatedown(int id, long long val)
    {
        for (; id; id -= (id&(-id))) seg[id] = min(seg[id], val);
    }
    long long getdown(int id)
    {
        long long res = oo15;
        for (; id; id -= (id&(-id))) res = min(res, seg[id]);
        return res;
    }
    long long getup(int id)
    {
        long long res = oo15;
        for (; id <= n; id += (id&(-id))) res = min(res, seg[id]);
        return res;
    }
};
int c[100005];
long long sum[100005], dp[100005];
void solve() 
{
	int n;
    vector<int> diffval;
    BIT ldk, qa;
	cin >> n;
    //cout << n << endl;
    n++;
    c[1] = 0;
	diffval.pb(0);
    for (int i = 2; i <= n; i++)
	{
        cin >> c[i];
        diffval.pb(c[i]);
        sum[i] = sum[i-1] + abs(c[i] - c[i-1]);
	}
    ldk.resize(n); qa.resize(n);
    sort(ALL(diffval));
    diffval.resize(unique(ALL(diffval)) - diffval.begin());
    dp[2] = sum[2];
    ldk.updateup(lower_bound(ALL(diffval), 0) - diffval.begin() + 1, dp[2] - sum[2] - c[1]); 
    qa.updatedown(lower_bound(ALL(diffval), 0) - diffval.begin() + 1, dp[2] - sum[2] + c[1]);
    for (int i = 3; i <= n; i++)
    {
        int x = lower_bound(ALL(diffval), c[i]) - diffval.begin() + 1;
        dp[i] = min(ldk.getdown(x) + c[i] + sum[i-1], qa.getup(x + 1) - c[i] + sum[i-1]);
       // if (i == n - 1) cout << ldk.getdown(x) << " " << qa.getup(x + 1) << endl; 
        int y = lower_bound(ALL(diffval), c[i-1]) - diffval.begin() + 1;
        ldk.updateup(y, dp[i] - sum[i] - c[i-1]); qa.updatedown(y, dp[i] - sum[i] + c[i-1]);
        //cout << endl;
    }
    long long res = oo15;
    for (int i = 1; i <= n; i++)
    {
        res = min(res, dp[i] + sum[n] - sum[i]);
        
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
