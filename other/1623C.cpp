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
int a[200005], n;
bool check(int val)
{
	int x = 0, y = 0;
	for (int i = n; i >= 3; i--)
	{
		if (a[i] + x < val) return false;
		int t = min((a[i] + x) - val, a[i])/3;
		x = y + t; y = 2*t;
	}
	//cout << a[2] + x << " " << a[1] + y << endl;
	if (a[2] + x < val || a[1] + y < val) return false;
	return true;
}
void solve() 
{
	//int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l = 0, r = oo;
	//cout << check(7) << endl;
	while(l <= r)
	{
		int mid = (l + r)/2;
		if (check(mid)) l = mid + 1 ; else r = mid - 1;
	}
	cout << r << "\n";
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
    cin >> testcase;
    while(testcase--)
        solve();
}
