#include<bits/stdc++.h>
using namespace std;
vector<int> s[10];
long long dp[10][10],ans[10][10];
const long long MOD=1e9;
void solve(long long n)
{
    if (n==3)
    {
         for (int i =1; i<=9; i++)
            for (int j =0 ;j<s[i].size(); j++)
                dp[i][s[i][j]]=1;

        for  (int i =1; i<=9; i++)
            for (int j=1; j<=9; j++)
                if (dp[i][j])
                    for (int e=0; e<s[j].size(); e++)
                        ans[i][s[j][e]]=(ans[i][s[j][e]]+dp[i][j])%MOD;
        for (int i =1; i<=9; i++) for (int j =1; j<=9;j ++)
        {   dp[i][j]=ans[i][j]; ans[i][j]=0;}  
            return;
    }
    if(n==2)
    {
        for (int i =1; i<=9; i++)
            for (int j =0 ;j<s[i].size(); j++)
                dp[i][s[i][j]]=1;
            return;
    }
    solve(n/2);
    for (int i=1; i<= 9 ;i++)
    {
        for (int j =1;j<=9; j++)
         if (dp[i][j])
            for (int e=0; e<s[j].size(); e++)
                for (int w=1; w<=9; w++)
                    if (dp[s[j][e]][w])
                ans[i][w]=(ans[i][w]+dp[i][j]*dp[s[j][e]][w]%MOD)%MOD;
    }
    for (int i =1; i<=9; i++) for (int j =1; j<=9;j ++)
    {   dp[i][j]=ans[i][j]; ans[i][j]=0;}
    if (n%2)
    {
        for  (int i =1; i<=9; i++)
            for (int j=1; j<=9; j++)
                if (dp[i][j])
                    for (int e=0; e<s[j].size(); e++)
                        ans[i][s[j][e]]=(ans[i][s[j][e]]+dp[i][j])%MOD;
        for (int i =1; i<=9; i++) for (int j =1; j<=9;j ++)
        {   dp[i][j]=ans[i][j]; ans[i][j]=0;}      
    }
}
int main()
{
    //freopen("yeunhi.txt","r",stdin);
    freopen("NUMSET.INP","r",stdin);
    freopen("NUMSET.OUT","w",stdout);
    long long n,ans=0;
    cin >>n;
    if (n==2) cout<<"40"; else if (n==3) cout<<"224";
    else {
        s[1].push_back(7);
        s[2].push_back(6);  s[2].push_back(7); s[2].push_back(8); s[2].push_back(9);
        s[3].push_back(6);  s[3].push_back(7); s[3].push_back(8); s[3].push_back(9);s[3].push_back(5);
        s[4].push_back(5);  s[4].push_back(7);
         s[5].push_back(3);  s[5].push_back(4); s[5].push_back(5); s[5].push_back(6);s[5].push_back(7); s[5].push_back(9);
         s[5].push_back(8);
          s[6].push_back(2);  s[6].push_back(3); s[6].push_back(5); s[6].push_back(7);
        s[7].push_back(1);  s[7].push_back(2); s[7].push_back(3); s[7].push_back(4);
        s[7].push_back(5);  s[7].push_back(6); s[7].push_back(7); s[7].push_back(8);
        s[7].push_back(9);
         s[8].push_back(2);  s[8].push_back(3); s[8].push_back(5); s[8].push_back(7); 
        s[9].push_back(2);  s[9].push_back(3); s[9].push_back(5); s[9].push_back(7); 
        solve(n);
        for (int i = 1; i<=9; i++)
            for (int j=1; j<=9; j++)
                ans=(ans+dp[i][j])%MOD;
            cout<<ans;
    }
}