#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6;
const int oo = 1e9;
int gh;
string s[21];
int slv[21][21];
int dp[105][105];
int n;
int ddp[1050000];
int solve(int msk)
{
    if (msk == gh) return ddp[msk] = 0;
    if (ddp[msk]!=-1) return ddp[msk];
    int res = oo;
    for (int i = 0; i < 2*n; i++)
        for(int j = i+1; j < 2*n; j++)
            if((msk >> i&1) == 0&&(msk >>j&1) == 0)
            {
              //  cout <<max(slv[i][j],solve((msk |(1 << i))|(1 << j)))<<endl;
                res = min(res, max(slv[i][j],solve((msk |(1 << i))|(1 << j))));
            }
         //   bitset<4> ss;
         //   ss= msk;
       // cout <<ss<<endl;
    return ddp[msk] = res;
}
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("hellodking.txt","r",stdin);
    #else
    // online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i =0; i< 2*n; i++)
        cin >> s[i];
    for (int i = 0; i < 2*n; i++)
        for (int j = i +1; j < 2*n; j++)
        {
            for (int e = 1; e <= s[i].size(); e++)
                    dp[e][0] =e;
            for(int e =1; e <= s[j].size(); e++) dp[0][e] = e;
            dp[0][0] = 0;
            for (int e = 1; e <= s[i].size(); e++)
                for (int r = 1; r <= s[j].size(); r++)
                if (s[i][s[i].size()-e]==s[j][s[j].size()-r]) dp[e][r] = dp[e-1][r-1]+1;
                else dp[e][r] = min(dp[e][r-1],dp[e-1][r])+1;
                slv[i][j] =slv[j][i] = dp[s[i].size()][s[j].size()];
             //   cout <<slv[i][j]<<endl;
        }
    memset(ddp,-1,sizeof ddp);
    gh = 1 << (2*n); gh--;
   // cout << gh <<endl;
    cout << solve(0);
}