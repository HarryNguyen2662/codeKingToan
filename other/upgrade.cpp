#include <bits/stdc++.h>
using namespace std;
struct kingtapyeuduong
{
    int f,s; long long t;
};
vector<kingtapyeuduong> ldk;
typedef pair<long long ,int> ii;
int n;
vector<pair<int, long long> > a[100005];
pair<long long, long long > dp[100005],dpp[100005];
void dijtra()
{
    for (int i = 1; i <= n; i++)
        dp[i].first = 1e15;
    priority_queue<ii, vector<ii>, greater<ii> >  q;
    dp[1].first = 0; dp[1].second=1;
    q.push({0, 1});
    while(!q.empty())
    {
       int  u = q.top().second; long long dd= q.top().first;
        q.pop();
        if (dd!=dp[u].first) continue;
        for (int i = 0 ;i < a[u].size(); i++)
        {
            int v = a[u][i].first;
            long long uv = a[u][i].second;
            if (dp[v].first>dd+uv)
            {
                dp[v].first=dd+uv; dp[v].second= dp[u].second;
                q.push({dp[v].first,v});
            }
            else if (dp[v].first== dd+uv) dp[v].second +=dp[u].second;
        }
    }
    for (int i = 1; i <= n; i++)
        dpp[i].first = 1e15;
    priority_queue<ii , vector<ii >, greater<ii > > p;
    dpp[n].first = 0; dpp[n].second=1;
    p.push({0, n});
    while(!p.empty())
    {
        int u = p.top().second; long long dd= p.top().first;
        p.pop();
        if (dd!=dpp[u].first) continue;
        for (int i = 0 ;i < a[u].size(); i++)
        {
            int v = a[u][i].first;
            long long uv = a[u][i].second;
            if (dpp[v].first>dd+uv)
            {
                dpp[v].first=dd+uv; dpp[v].second= dpp[u].second;
                p.push({dpp[v].first,v});
            }
            else if (dpp[v].first== dd+uv) dpp[v].second +=dpp[u].second;
        }
    }
}
int main()
{
   // freopen("yeunhi.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m,gt,x,y;
    cin >> n >> m;
    for (int i = 1; i<= m; i++)
    {
        cin >> x >> y >> gt;
        a[x].push_back({y,gt});
        a[y].push_back({x,gt});
        ldk.push_back({x,y,gt});
    }
    dijtra();
   // cout << dp[n].first<<endl;
    int ans =0;
    for(auto v : ldk)
    {
        //cout << v.f <<" "<<v.s <<" "<<v.t<<endl;
     //  cout << dp[v.f].first+dpp[v.s].first<<" "<<dpp[v.f].first+dp[v.s].first+v.t<<endl;
        if (dp[v.f].first+dpp[v.s].first+v.t==dp[n].first&&dp[v.f].second*dpp[v.s].second==dp[n].second
            ||dpp[v.f].first+dp[v.s].first+v.t==dp[n].first&&dpp[v.f].second*dp[v.s].second==dp[n].second) ans ++;
    }
     cout << ans;
}