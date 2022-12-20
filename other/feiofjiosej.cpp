#include<bits/stdc++.h>
using namespace std;
long long dp[101],cnt[101];
const long long MOD = 1e9+7;
struct MaTrix
{
    long long c[101][101];
};
MaTrix operator * (MaTrix a, MaTrix b)
{
    MaTrix res;
    for (int i=0; i<=100; i++)
        for (int j=0; j<=100; j++)
        {
            res.c[i][j] = 0;
            for (int k=0; k<=100; k++)
                res.c[i][j] = (res.c[i][j]+a.c[i][k]*b.c[k][j]%MOD)%MOD;
        }
    return res;
}
MaTrix power (MaTrix a, long long n)
{
    if (n==1)
    {
        return a;
    }
    MaTrix tt = power(a,n/2);
    if (n%2) return tt*tt*a; else return tt*tt;
}
int main()
{
   // freopen("yeunhi.txt","r",stdin);
  //  ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    int n,x; long long k;
    cin >> n >> k;
    for (int i = 1; i<= n; i++)
    {
        cin >> x;
        cnt[x]++;
    }
    MaTrix A;
    for (int i = 0; i < 101; i++)
            for (int j = 0; j< 101; j++)
                A.c[i][j] = 0;
    A.c[0][99]=A.c[0][100] = cnt[100];
    for(int i = 1; i < 100 ; i++)
       { 
            A.c[i][99] = A.c[i][100] = cnt[100-i];
            A.c[i][i-1] = 1;
        }
    A.c[100][100] = 1;
    dp[0]=1;
    for (int i = 1; i <= 100; i++)
       { 
            for (int j = 0; j<= i; j++)
                dp[i]=(dp[i]+dp[i-j]*cnt[j]%MOD)%MOD;
        }
    //cout << dp[1]<<" "<<dp[2]<<" "<<dp[3]<<endl;
    long long ans = 0;
    if (k<=100)
    {
        for (int i = 0; i <=k; i++)
            ans = (ans + dp[i])%MOD;
    }
    else 
    {
        A = power(A,k-100);
        for (int i=0; i < 100 ; i++)
        {
            ans = (ans + dp[i+1]*A.c[i][100]%MOD)%MOD;
        }
        long long z = 0;
         for (int i = 0; i <=100; i++)
            z = (z + dp[i])%MOD;
        ans=(ans+A.c[100][100]*z%MOD)%MOD;
    }
    cout << ans;
}
