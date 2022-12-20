#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6;
const int oo = 1e9;
int xx[4] = {0,0,-1,1};
int yy[4]= {-1,1,0,0};
struct MaTran
{
    long long c[50][50];
     MaTran()
    {
        for (int i =0 ;i< 50; i++)
            for (int j = 0; j<50; j++)
                c[i][j] = 0;
    }
};

MaTran operator  * (MaTran a, MaTran b)
{
    MaTran res;
    for (int i=0; i<50; i++)
        for (int j=0; j<50; j++)
        {
            res.c[i][j] = 0;
            for (int k=0; k<50; k++)
                res.c[i][j] = (res.c[i][j]+a.c[i][k]*b.c[k][j]%MOD)%MOD;
        }
    return res;
}
bool getbit(long long x, int id) {
    return ((x >> id) & 1);
}
MaTran power(MaTran a, long long n) {
    MaTran ans = MaTran();
    for(int i = 0; i <50; i++) ans.c[i][i] = 1;
    for(int i = 0; i <= 62; i++) {
        if((long long)((long long)1 << i) > n) break;
        if(getbit(n, i)) ans = ans * a;
        a = a * a;
    }
    return ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("yeunhi.txt","r",stdin);
    #else
    // online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; long long k;
    cin >> n >> k;
    MaTran A;
    for (int i =0 ; i < n; i++)
        for (int j =0; j < n; j++)
        {
            cin >> A.c[i][j];
        }
    int ans = 0;
    A = power(A,k);
    for (int i =0 ; i < n; i++)
        for (int j =0; j < n; j++)
        {
           ans = (ans + A.c[i][j])%MOD;
        }
    cout << ans;
}