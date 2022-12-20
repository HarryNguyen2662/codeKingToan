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
char a[100][100];
void solve() 
{
    int n, m, r, c;
    bool ok = false;
    int kt1 =0 , kt = 0;
    cin >> n >> m >> r >> c;
    //cout << n << " " << m << endl;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) 
    {
        cin >> a[i][j];
        if (a[i][j] == 'B')
        {
            ok= true;
        }
    }
    if (a[r][c] == 'B')
    {
        cout << "0\n";
        return;
    }
    for (int i = 1; i <= n; i++) if (a[i][c] == 'B')
    {
        cout << "1\n";
        return;
    }
    for (int i = 1; i <= m; i++) if (a[r][i] == 'B')
    {
        cout << "1\n";
        return;
    }
    if (ok) cout << "2\n"; else cout << "-1\n";
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