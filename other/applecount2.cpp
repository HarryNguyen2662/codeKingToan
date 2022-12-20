#include <bits/stdc++.h>
using namespace std;
long long dp[17][3000][10][17],n;
vector<int> pos;
long long solve1(int cs, int sum,int cst, int sl,int gh)
{
    if (cs == -1 )
    {
      //  if (gh) cout << sum<< endl;
        return sum;
    }
    if (dp[cs][sum][cst][sl]!=-1&&!gh) return dp[cs][sum][cst][sl];
    int u = (gh)? pos[cs] : 9;
    long long ans = 0;
    for (int i = 0; i <= u; i++)
    {
        int newsum = (i==cst)? sum+2*i*sl+i:sum+i,newsl=(i==cst)? sl+1:1;
       int newgh = (i==pos[cs])? gh : 0;
        ans+=solve1(cs-1,newsum,i,newsl,newgh);
      //  cout << ans << endl;
    }
    //if (gh&&cs==1) cout << ans << endl;
    if (!gh) dp[cs][sum][cst][sl]=ans;
    return ans;
}
long long trans(long long a)
{
    pos.clear();
    memset(dp,-1,sizeof dp);
    while (a)
    {
        pos.push_back(a%10);
        a/=10;
    }
    n=pos.size()-1;
    long long ans = solve1(n,0,0,0,1);
    return ans;
}
void solve()
{
    long long l,r;
    cin >>l>>r;
    cout <<trans(r)-trans(l-1) ;
}
int main() 
{
    freopen("lololoin.txt","r",stdin);
    solve();
}