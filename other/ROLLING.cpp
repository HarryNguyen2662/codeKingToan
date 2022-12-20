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
int luu[7];
void solve() 
{
	long long n, m;
	long long res = 0;
	cin >> n >> m;
	luu[1] = 6; luu[2] = 5; luu[3] = 3; luu[4] = 1; luu[5] = 2; luu[6] = 4;
	if (n%4 == 0)
	{
		cout << 14*(n/4)*m;
	}
	else if (n%4 == 1)
	{
		res = 14*(n/4)*m + 14*(m/4);
		if (m%4 == 1) res = res + 6; 
		if (m%4 == 2) res = res + 6 + 5;
		if (m%4 == 3) res = res + 6 + 5 + 1;
		cout << res;
	}
	else if (n%4 == 2)
	{
		res = 14*(n/4)*m + 42*(m/6);
		//cout << m%6 << endl;
		for (int i = 1; i <= m%6; i++) 
		{
			res += luu[i];
			if (i == 1) res += luu[6]; else res += luu[i-1]; 
		}
		cout << res;	
	}
	else
	{
		res = 14*(n/4)*m + 22*(m/2);
		if (m%2 == 1) res = res + 6 + 4 + 1;
		cout << res;
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
    //freopen("ROLLING.inp","r",stdin); freopen("ROLLING.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
