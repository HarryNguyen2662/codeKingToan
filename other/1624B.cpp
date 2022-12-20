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
int a[5];
void solve() 
{
	cin >> a[0] >> a[1] >> a[2];
	for (int i = 0; i < 3; i++)
	for (int j = i + 1; j < 3; j++)
	if ((a[j] - a[i])%(j - i) == 0)
	{
		int w = 1^2^i^j;
		//cout << w << endl;
		int m = -1;
		if (j - i == 2)
		{
			if ((a[j] - (a[j] - a[i])/2)%a[w] == 0) m = (a[j] - (a[j] - a[i])/2)/a[w];
		}
		else
		{
			if (i == 0 && (a[j] + a[j] - a[i])%a[w] == 0) m = (a[j] + a[j] - a[i])/a[w];
			if (i == 1 && (2*a[i] - a[j])%a[w] == 0) m = (2*a[i] - a[j])/a[w];
		}
		if (m > 0)
		{
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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
