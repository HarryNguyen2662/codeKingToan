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
int r[100005], l[100005], c[100005];
void solve() 
{
	int n;
	cin >> n;
	//cout << n << endl;
	for (int i = 1; i <= n; i++) cin >> l[i] >> r[i] >> c[i];
	l[0] = oo + 1; r[0] = 0;
	int left = 0, right = 0, ll = 0, rr = 0;
	for (int i = 1; i <= n; i++)
	{
		if (l[left] > l[i]) left = i; 
		if (r[right] < r[i]) right = i; 
		if (l[ll] > l[i]) ll = i; else if (l[ll] == l[i] && c[ll] > c[i]) ll = i;
		if (r[rr] < r[i]) rr = i; else if (r[rr] == r[i] && c[rr] > c[i]) rr = i;
		int res;
		if (left != right) res = c[left] + c[right]; else res = c[left];
		if (l[i] == l[left] && r[right] == r[i] && res > c[i])
		{
			res = c[i];
			left = i; right =i;
		} 
		if (r[right] == r[i] && c[ll] + c[i] < res)
		{
			res = c[left] + c[i];
			right = i;
		}
		if (l[left] == l[i] && c[rr] + c[i] < res)
		{
			res = c[right] + c[i];
			left = i;
		}
		cout << min(res, c[ll] + c[rr]) << "\n";
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
    cin >> testcase;
    while(testcase--)
        solve();
}
