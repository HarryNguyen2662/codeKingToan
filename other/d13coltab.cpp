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
int h[1005][1005], c[1005][1005];
void solve() 
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
	{
        h[i][j] = h[i][j-1];
        c[i][j] = c[i-1][j];
		bool kt;
		cin >> kt;
       // cout << kt << " ";
		if (kt) h[i][j]++, c[i][j]++;
	}
   
    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        if (h[i][m] + h[j][m] + 2*(j - i - 1) > res)
        {
            int w = min(-(c[j-1][1] - c[i][1]), 0);
            for (int e = 2; e <= m; e++)
            {
                res = max(res, h[i][e] + h[j][e] + c[j-1][e] - c[i][e] - w);
                w = min(w, h[i][e] + h[j][e] - (c[j][e] - c[i-1][e])); 
            }
            //if (i == 2 && j == 5) cout << w << endl;
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
