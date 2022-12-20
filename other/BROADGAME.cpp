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
int prime[20005], numprime = 0;
bool check(int val)
{
	for (int i = 2; 1ll*i*i <= val; i++) if (val%i == 0) return false;
	return true;
}
int mo[20005];
long long cal(int x, int y)
{
	long long res = 0;
	for (int i = 1; i <= x && i <= y;)
	{
		int j = min(x/(x/i), y/(y/i));
		//cout << i << " " << j << endl;
		res = res + 1ll*(mo[j] - mo[i-1])*1ll*(x/i)*1ll*(y/i);
		//cout << res << endl;
		i = j + 1;
	}
	return res;
}
void solve() 
{
	int n = 0;
	cin >> n;
	if (n == 0) exit(0);
	long long res = 0;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		long long val = cal(x, y);
		//cout << val << endl;
		res = res ^ val;
	}
	if (res) cout << "YES\n"; else  cout << "NO\n";
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
    mo[1] = 1;
    for (int i = 1; i <= 20000; i++)
    	for (int j = 2*i; j <= 20000; j+=i)
    		mo[j] -= mo[i];
  
    for (int i = 1; i <= 20000; i++)
    {
    	mo[i] += mo[i-1];
    }
    //cout << mo[2] - mo[1] << endl;
    int testcase = 3;
    //cin >> testcase;
    while(testcase--)
        solve();
}
