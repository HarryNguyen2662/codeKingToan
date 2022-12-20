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
int l[1005], h[1005], su[1005][1005], s[1005][1005];
int getsum(int x, int y, int u, int v)
{
	return su[u][v] - su[u][y-1] - su[x-1][v] + su[x-1][y-1];
}
void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int u, v; char type;
		cin >> u >> v >> type;
		u++; v++;
		if (type == 'H') s[u][v] = 1; else s[u][v] = -1;
	}
	for (int i = 1; i <= 1001; i++) for (int j = 1; j <= 1001; j++)
	su[i][j] = su[i-1][j] + su[i][j-1] - su[i-1][j-1] + (s[i][j] == 1);
	int res = 1, re = 0;
	for (int i = 1; i <= 1001; i++)
	{
		stack<int> st;
		for (int j = 1; j <= 1001; j++)
		{
			if (s[i][j] == -1) h[j] = 0; else h[j]++;
			l[j] = 1;
			while(!st.empty() && h[st.top()] >= h[j]) st.pop();
			if (!st.empty()) l[j] = st.top() + 1;
			st.push(j);
		}
		while(!st.empty()) st.pop();
		for (int j = 1001; j; j--)
		{
			int r = 1001;
			while(!st.empty() && h[st.top()] >= h[j]) st.pop();
			if (!st.empty()) r = st.top() - 1;
			st.push(j);
			int hh = h[j];
			int va = getsum(i - hh + 1, l[j], i , r);
			if (va < res) continue;
			int ll = 1, rr = hh;
			while(ll <= rr)
			{
				int mid = (ll + rr)/2;
				if (getsum(i - hh + 1, l[j], i - hh  + mid, r) == 0) ll = mid + 1; else rr = mid - 1;
			}
			hh -= rr;
			ll = 1; rr = r - l[j] + 1;
			while(ll <= rr)
			{
				int mid = (ll + rr)/2;
				if (getsum(i - hh + 1, l[j], i, l[j] + mid - 1) == 0) ll = mid + 1; else rr = mid -1;
			}
			l[j] += rr;
			ll = 1; rr = r - l[j] + 1;
			while(ll <= rr)
			{
				int mid = (ll + rr)/2;
				if (getsum(i - hh + 1, r- mid + 1, i, r) == 0) ll = mid + 1; else rr = mid -1;
			}
			r -= rr;
			if (va > res)
			{
				res = va;
				re = (hh-1)*(r - l[j]);
			}else if (res == va && re > (hh-1)*(r-l[j])) re = (hh-1)*(r-l[j]);
		}
	}
	cout << res << "\n" << re;
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
