#include<bits/stdc++.h>
using namespace std;
int x[4] ={0,0,-1,1};
int y[4] = {-1,1,0,0};
long long ans=-1e18;
vector<long long>dp[100005];
vector<int> h[100005],s[100005];
int n,m;
void dfs(int xx, int yy)
{
    dp[xx][yy]=s[xx][yy]; long long u = -1e18;
    for (int i =0; i<4; i++)
    {
        int nx=xx+x[i], ny=yy+y[i];
        if (1<=nx&&nx<=n&&ny>=1&&ny<=m&&h[nx][ny]>h[xx][yy])
        {
            if (dp[nx][ny]==-1e18) dfs(nx,ny);
            u=max(u,dp[nx][ny]);
        } 
    }
   // cout<<u<<endl;
    if (u>0) dp[xx][yy]+=u;
     ans=max(ans,dp[xx][yy]);
}        
int main()
{
    freopen("yeunhi.txt","r",stdin);
    int x;
    cin>> n>>m;
    for (int i = 1 ;i <=n; i++)
        for (int j = 1; j<= m; j++)
            {
                if (j==1)
                    {
                        h[i].push_back(0);
                        dp[i].push_back(0);
                    }
                cin>>x;
                h[i].push_back(x);
                dp[i].push_back(-1e18);
            }
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=m; j++)
            {
                if (j==1)
                    {
                        s[i].push_back(0);
                    }
                cin>>x;
                s[i].push_back(x);
            }
    for (int i =1 ;i<=n; i++)
        for (int j=1; j<=m; j++)
            if (dp[i][j]==-1e18) dfs(i,j);
    // for (int i = 1; i<=n ;i++)
    //     for (int j = 1; j<= m; j++) cout<< dp[i][j]<<endl;
    cout<<ans;
}
