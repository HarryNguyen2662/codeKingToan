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
const int lim = 1e6 + 2;;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 922372036854775807;
struct matrix
{
    long long c[102][102];
};
int kk;
matrix operator * (const matrix &a, const matrix &b)
{
    matrix res;
    for (int i = 0; i <= kk; i++)
        for (int j = 0; j <= kk; j++)
        {
            res.c[i][j] = 0;
            for (int k = 0; k <=kk; k++)
            {
                res.c[i][j] += a.c[i][k]*b.c[k][j]%MOD;
                if (res.c[i][j] >= MOD) res.c[i][j] -= MOD;
            }
        }
    return res;
}
matrix power(matrix a, int n)
{
    if (n == 1) return a;
    if (n%2) return power(a, n - 1)*a;
    matrix aa = power(a, n/2);
    return aa*aa;
}
void solve()
{
    int n, k;
    cin >> k >> n;
    kk = k;
    matrix A = matrix();
    for (int i = 0; i < 102; i++) for (int j = 0; j < 102; j++) A.c[i][j] = 0;
    for (int i = 1; i <= k; i++)
    {
        if (i >= 2)
        {
            kk++;
            A.c[i-1][kk] = 1;
            for (int j = 1; j + 1 < i; j++)
            {
                A.c[kk][kk+1] = 1;
                kk++;
            }
            A.c[kk][i] = 1;
            kk++;
            A.c[i][kk] = 1;
            for (int j = 1; j + 1 < i; j++)
            {
                A.c[kk][kk+1] = 1;
                kk++;
            }
            A.c[kk][i] = 1;
        }
        else A.c[i][i] = 1, A.c[i-1][i] = 1;
    }
     //cout << kk << endl;
    A = power(A, n);
    cout << A.c[0][k] << "\n";
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
    cin >> testcase;
    while(testcase--)
        solve();
}
