#include<bits/stdc++.h>
using namespace std;
int m;
string ss;
const long long MOD=1000000007;
long long dp[100005],Le[100005][11],Dai[100005][11],King[100005][11];
const long long limit = 100000;
void khoitao()
{
    dp[0]=1;
    for (int i = 1; i <= limit; i++)
    {
        if (i == 1)
            for (int j = 0; j <= 9; j++)
            {
                Le[i][j] = 1; 
                Dai[i][j] = 1;
                King[i][j] = 1;
            }
        else
        {
            for (int j = 0; j <= 10; j++)
            {
                for (int u = 0; u <=j-1; u ++)
                    Le[i][j] = (Le[i][j] + Dai[i-1][u])%MOD;
                for (int u = j + 1; u <=9; u ++)
                    Dai[i][j] = (Dai[i][j] + Le[i-1][u])%MOD;  
                King[i][j] = (Le[i][j] + Dai[i][j])%MOD;
            }
        }
        dp[i]=dp[i-1];
        for (int j = 1; j <=9; j ++) dp[i] = (dp[i] + King[i][j])%MOD;
    }
}
int check(string s)
{
    if (s.size() == 1) return 1;
    if (s.size() == 2)
    {
        return (s[0] != s[1]);
    }
    for (int i = 1 ; i < s.size()-1; i++)
    {
        if ((s[i] - s[i-1])*(s[i] - s[i+1])<=0) return 0;
    }
    return 1;
}
long long solve(int cs)
{
    if (cs == ss.size())
    {
        return check(ss);
    }
    long long ans = 0;
    m--;
    if (ss[cs-1]-ss[cs-2]>0)
        for (int i = 0; i< min(ss[cs] - 48 ,ss[cs-1] - 48); i++) 
                ans = (ans + Dai[m][i]) % MOD;
    else if (ss[cs-1]<ss[cs-2])
         for (int i = ss[cs-1] - 47; i< ss[cs] - 48; i++) 
                ans = (ans + Le[m][i]) % MOD;
    if ( (ss[cs-1] - ss[cs]) * (ss[cs-1] - ss[cs-2]) <= 0) 
        return ans;
    if (ss[cs]==ss[cs-1]) return ans;
    ans = (ans + solve(cs+1))%MOD;
 
    return ans;
} 
int a,b;
string s1,s2;
void solve1()
{
    khoitao();
    long long ans1 = 0, ans2 = 0;
    cin >> a >> b;
    cin >> s1 >> s2;
    ans1 = dp[b-1];
   // cout << ans1<<endl;
    for (int i = 1; i < s2[0]-48; i++)
        ans1= (ans1 + King[b][i])%MOD;
    if (s2.size()>1)
        for (int i = 0; i < s2[1]-48; i++)
        {
            if (i == s2[0]-48) continue;
            ans1 = (i < s2[0]-48) ?  (ans1 + Dai[b-1][i]) % MOD :  (ans1 + Le[b-1][i]) % MOD;
        }
         if (s2.size()>2)
        {
            ss = s2; m = b-1;
            ans1 = (ans1 + solve(2))%MOD;
        }
        else
        {
            ans1= ans1 + check(s2);
        }
     ans2 = dp[a-1] ;
     //cout << ans2 << endl;
    for (int i = 1; i < s1[0]-48; i++)
        ans2= (ans2 + King[a][i])%MOD;
    if (s1.size()>1)
        for (int i = 0; i < s1[1]-48; i++)
        {
            if (i == s1[0]-48) continue;
            ans2 = (i < s1[0]-48) ?  (ans2 + Dai[a-1][i]) % MOD : (ans2 + Le[a-1][i]) % MOD;
        }
         if (s1.size()>2)
        {
            ss = s1; m = a-1;
            ans2 = (ans2 + solve(2))%MOD;
        } else
        {
            ans2 = ans2 + check(s1);
        }
 //  cout << ans2 << endl;
   ans2= ans2 - check(s1);
  // cout <<" aslo "<< s1 <<" " << check(s1)<< endl;
   // cout << ans1 << endl;
   // cout <
    cout << ((ans1-ans2)%MOD+MOD)%MOD;
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    freopen("lololoin.txt","r",stdin);
    solve1();
   
}