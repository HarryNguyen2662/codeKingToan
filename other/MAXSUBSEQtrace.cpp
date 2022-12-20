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
	if (x <= y)
	{
		x = y;
		return true;
	}
	return false;
}
long long sum[1000005];
void solve() 
{
	int n, l, r;
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++)
	{
		long long val;
		cin >> val;
		sum[i] = sum[i-1] + val;
	}
	deque<int> dq;
	dq.push_back(0);
	long long res = -oo18;
	int x = -1 , y = -1;
	for (int i = 1; i <= n; i++)
	{
		if (i - l >= 1)
		{
			while (!dq.empty() && sum[dq.back()] >= sum[i - l]) dq.pop_back();
			dq.push_back(i-l);
		}
		if (dq.front() < i - r) dq.pop_front();
		if (maximize(res, sum[i] - sum[dq.front()]))
		{
			x = dq.front() + 1; y = i;
		}
	}
	cout << res << "\n";
	cout << x << " " << y;
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
