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
int n;
int x[105], y[105], z[105];
long long trau(int i, int maxx, int minx, int maxy, int miny, int maxz, int minz)
{
	if (i == n+1)
	{
		if (maxx != -oo -1 &&  minx != oo+1 && maxy != -oo -1 &&  miny != oo+1 && maxz != -oo -1 &&  minz != oo+1)
		return maxx+maxy+maxz-minx-miny-minz;
		else return 6ll*oo + 100;
	}
	return min({trau(i+1,max(maxx, x[i]), min(minx, x[i]), maxy, miny, maxz, minz),
				trau(i+1, maxx, minx, max(maxy, y[i]), min(miny,y[i]), maxz, minz), 
				trau(i+1, maxx,  minx, maxy, miny, max(z[i], maxz), min(z[i], minz) )});
}
void solve() 
{
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i] >> z[i];
	}
	cout << trau(1, -oo-1, oo+1, -oo-1, oo+1, -oo-1, oo+1);
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
