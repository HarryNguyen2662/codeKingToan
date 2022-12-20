#include<bits/stdc++.h>
using namespace std;
string ss;
int  dp[10][2][90][90],a,b;
string biendoi(int x)
{
    stringstream s;
    s <<x;
    return s.str();
}
int solve(int cs, bool trangthai, int sum, int sum2,int tt)
{
    int ans = 0,u;
    if (cs == ss.size())
        {
           // cout << du << endl;
            return (sum-sum2==1);
        }   
    if (dp[cs][trangthai][sum][sum2]!=-1&&trangthai) return dp[cs][trangthai][sum][sum2];
    if(trangthai) u = ss[cs]-48; else u = 9;
    for (int i = 0 ; i <= u; i++)
    {
        int newtt = (ss[cs]-48==i)? trangthai : 0;
        if (tt)
        ans += solve(cs+1,newtt,sum+i,sum2,0);
        else  ans += solve(cs+1,newtt,sum,sum2+i,1);
    }
    dp[cs][trangthai][sum][sum2] = ans;
    return ans;
} 
void solve1()
{
    int ans ;
    cin >> a >> b;
    ss = biendoi(b);
     memset(dp,-1,sizeof dp);
    ans = solve(0,1,0,0,ss.size()%2);
   // cout << ans << endl;
    a--;
    ss = biendoi(a);
    memset(dp,-1,sizeof dp);
    ans -=solve(0,1,0,0,ss.size()%2);
    cout << ans;
}
int main()
{
    //ios_base::sync_with_stdio(0);
   // cin.tie(0); cout.tie(0);
    freopen("lololoin.txt","r",stdin);
    solve1();
}