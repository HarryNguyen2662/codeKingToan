#include<bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;
long long dp[100005][35],sl[100005],f[35];
char cs[100005],p[100005];
long long power(long long a, long long b)
{
    if (b==0) return 1; 
    long long y= power(a,b/2);
    if (b%2) return y*y%MOD*a%MOD; else return y*y%MOD;
}
int main()
{
    freopen("yeunhi.txt", "r", stdin);
    long long n,m,unhi,dem;
    string s;
    cin>> n >> m;
    cin>>s; n=s.size(); n=0;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]>57) 
            {  
               sl[n]=dem; dem=0; cs[++n] = s[i];
            }
        else 
        {
            dem=dem*10+s[i]-48;
        }
    }
    sl[n]=dem;
    for (int i =1; i<=m; i++) cin>>p[i];
    f[0]=1;
    for (int i =1; i<=m+2; i++) f[i]=power(i,MOD-2);
    dp[0][0]=1;
    //for (int i =1 ;i<=n; i++)
        //cout<<cs[i]<<" "<<sl[i]<<endl;
    for (int i = 0; i<n; i++)
        for (int j = 0; j<= m; j++)
        if(dp[i][j])
        {
           // cout<<i<<" "<<j<<endl;
            dp[i+1][j]=(dp[i+1][j]+dp[i][j])%MOD;
            unhi=1; int z=min(m-j,sl[i+1]);
            //cout<<z<<endl;
            for (int e = 1; e<=z; e++)
            {
                if (p[j+e]!=cs[i+1]) break;
                unhi=unhi*((sl[i+1]-e+1)%MOD)%MOD*f[e]%MOD;
                  //if (unhi==0)unhi=1;
                dp[i+1][j+e]=(dp[i+1][j+e]+dp[i][j]*unhi%MOD)%MOD;
              //cout<<dp[i+1][j+e]<<" "<<i<<" "<<j<<" "<<e<<" "<<unhi<<endl;
            }
        }
     //   cout<<n<<" "<<m<<endl;
    cout<<dp[n][m];
}