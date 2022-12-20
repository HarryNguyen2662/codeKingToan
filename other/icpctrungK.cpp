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
const long long nMOD = 500000004;
int w;
struct Matrix
{
    long long c[102][102];

    Matrix operator * (const Matrix &other) const
    {
        Matrix res;
        for (int i = 1; i <= w; i++)
            for (int j = 1; j <= w; j++)
            {
                res.c[i][j] = 0;
                for (int k = 1; k <= w; k++)
                {
                    res.c[i][j] = res.c[i][j] + c[i][k]*other.c[k][j]%MOD;
                    if (res.c[i][j] >= MOD) res.c[i][j] -= MOD;                
                }
            }
        return res;
    }
};
Matrix cal(const Matrix &A, int n)
{
    Matrix res = A;
    int st = 30;
    for (; st >= 0; st--) if (ck(n, st)) break;
    for (int i = st-1; i >= 0; i--)
    {
        res = res*res;
        if (ck(n, i)) res = res*A;
    }
    return res;
}
int n, m, t;
char s[200][200];
bool check(int x, int y)
{
    if (x >= 1 && x <= n && y >= 1 && y <= m && s[x][y] != '#') return true;
    return false;
}
void solve()
{   
    
    cin >> n >> m >> t;
    w = n*m;
    //t = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> s[i][j];
    Matrix A, B;
    for (int i = 0; i <= n*m; i++) for (int j = 0; j <= n*m; j++) A.c[i][j] = B.c[i][j] =  0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int x, y;
            if (s[i][j] == 'D' || s[i][j] == '+')
            {
                x = i + 1; y = j;
                if (check(x, y)) A.c[(i-1)*m + j][(x-1)*m + y] = 1, B.c[1][(x-1)*m + y]++;
                //cout << x << " " << y << endl;
            }
            if (s[i][j] == 'U' || s[i][j] == '+')
            {
                x = i - 1; y = j;
                if (check(x, y)) A.c[(i-1)*m + j][(x-1)*m + y] = 1,  B.c[1][(x-1)*m + y]++;
                //cout << x << " " << y << endl;
            }
            if (s[i][j] == 'R' || s[i][j] == '+')
            {
                x = i; y = j + 1;
                if (check(x, y)) A.c[(i-1)*m + j][(x-1)*m + y] = 1,  B.c[1][(x-1)*m + y]++;
               // cout << x << " " << y << endl;
            }
            if (s[i][j] == 'L' || s[i][j] == '+')
            {
                x = i; y = j - 1;
                if (check(x, y)) A.c[(i-1)*m + j][(x-1)*m + y] = 1,  B.c[1][(x-1)*m + y]++;
               // cout << x << " " << y << endl;
            }
        }
    // for (int i = 1; i <= w; i++) 
    // {
    //     for (int j = 1; j <= w; j++) cout << A.c[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 1; i <= w; i++) 
    // {
    //     for (int j = 1; j <= w; j++) cout << B.c[i][j] << " ";
    //     cout << endl;
    // }
    if (t > 1)
    B = B*cal(A, t-1);
    long long res = 0;
    for (int i = 1; i <= n*m; i++)
    {
        res = res + B.c[1][i]; res %= MOD;
    }
    cout << res;
}
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    // 
    #endif
    //freopen("dienbien.inp","r",stdin); freopen("dienbien.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
