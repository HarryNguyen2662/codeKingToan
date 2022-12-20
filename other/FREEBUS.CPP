#include<bits/stdc++.h>
using namespace std;
int s,t,n,k;
long long dp[100005][6];
vector<pair<int, int > > a[100005];
struct kingldk
{
    int ft;
    long long sc;
    int tt;
    bool operator < (const kingldk & other) const
    {
        return sc > other.sc;
    }
};
void dijkstra()
{
    for (int i = 0 ; i<= 5; i++)
        for (int j = 0; j <= n; j++) dp[j][i] = 1e18;
    priority_queue<kingldk> q;
    dp[s][0] = 0;
    q.push({s,0,0});
    while(!q.empty())
    {
        int u = q.top().ft;
        long long dd = q.top().sc;
        int sl = q.top().tt;
        q.pop();
        if (dd!=dp[u][sl]) continue;
        for (int i = 0; i< a[u].size(); i++)
        {
            int  v=a[u][i].first;
            int  uv =a[u][i].second;
           // cout << v << " "<< uv << endl;
            if (dp[v][sl]>dd + uv)
            {
                dp[v][sl] = dd + uv;
                q.push({v,dp[v][sl],sl});
            }
          //  cout << dp[v][sl]<<endl;
            if (sl<k&&dp[v][sl+1]>dd)
            {
                dp[v][sl+1] = dd;
                q.push({v,dp[v][sl+1],sl+1});
            }
        }
    }
    cout << min({dp[t][0],dp[t][1],dp[t][2],dp[t][3],dp[t][4],dp[t][5]});
}
int main()
{
   freopen("FREEBUS.INP","r",stdin);
   freopen("FREEBUS.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long gt; int x,y;
    int m;
    cin >> n >> m >> k >> s >> t;
    for (int i = 1; i <= m ;i++)
    {
        cin >> x >>y >> gt;
        a[x].push_back({y, gt});
        a[y].push_back({x, gt});
    }
    dijkstra();
}
