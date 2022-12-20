#include<bits/stdc++.h>
using namespace std;
string ss;
long long dp[20][2][180][1500],a,b;
string biendoi(long long x)
{
    stringstream s;
    s <<x;
    return s.str();
}
long long solve(int cs, bool trangthai, long long sum, long long sum2)
{
    long long ans = 0; int u;
    if (cs == ss.size())
        {
           // cout << sum-sum2 << endl;
            return __gcd(sum,sum2)==1;
        }   
    if (dp[cs][trangthai][sum][sum2]!=-1&&!trangthai) return dp[cs][trangthai][sum][sum2];
    if(trangthai) u = ss[cs]-48; else u = 9;
    for (int i = 0 ; i <= u; i++)
    {
        int newtt = (ss[cs]-48==i)? trangthai : 0;
        ans += solve(cs+1,newtt,sum+i,sum2+(i*i));
    }
   dp[cs][trangthai][sum][sum2] = ans;
    return ans;
} 
void solve1()
{
    long long ans ;
    cin >> a >> b;
    ss = biendoi(b);

     memset(dp,-1,sizeof dp);
    ans = solve(0,1,0,0);
   // cout << ans << endl;
    a--;
    ss = biendoi(a);
    memset(dp,-1,sizeof dp);
    ans -=solve(0,1,0,0);
    cout << ans;
}
int main()
{
    //ios_base::sync_with_stdio(0);
   // cin.tie(0); cout.tie(0);
    freopen("lololoin.txt","r",stdin);
    solve1();
}