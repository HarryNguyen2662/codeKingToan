#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 17
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1ll << (i))
#define ck(n, i) (((n) >> (i))&1) 
#define setp(x) setprecision(x)
#define NMOD 3
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789; 
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 922372036854775807;
inline int ReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    int x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    return x;
}
void WriteInt(int x)
{
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
bool checkprime(int val)
{
	if (val <= 1) return false;
	for (int i = 2; 1ll*i*i <= val; i++) if (val%i == 0) return false;	
	return true;
}
vector<int> convert(long long val)
{
	vector<int> re;
	while(val)
	{
		re.pb(val%10); val /= 10;
	}
	reverse(re.begin(), re.end());
	return re;
}
bool prime[405];
long long f[17][320][320][3];
vector<int> ldk;
long long dp(int id, int sum, int sum1, int du)
{
	if (id == (int)ldk.size())
	{
		//cout << sum << " " << sum1 << endl;
		return prime[sum] && prime[sum1] && !du;
	}
	if (f[id][sum][sum1][du] != -1) return f[id][sum][sum1][du];
	long long &res = f[id][sum][sum1][du];
	res = 0;
	for (int i = 0; i <= 9; i++)
	for (int j = 0; j <= 9; j++)
	for (int ndu = 0; ndu <= 2; ndu++)
	{
		int val = (i + 2*j + ndu);
		if (val/10 == du && val%10 == ldk[id]) res += dp(id + 1, sum + i, sum1 + j, ndu);
	}
	return res;
}
void solve()
{
	long long n;
	cin >> n;
	ldk = convert(n);
	for (int i = 2; i <= 400; i++) if (checkprime(i)) prime[i] = true;
	for (int i = 0; i <= 15; i++) 
	for (int e = 0; e <= 318; e++) 
	for (int j = 0; j <= 318; j++)
	for (int du = 0; du <= 2; du++) f[i][e][j][du] = -1;
	cout << dp(0, 0, 0, 0);
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
