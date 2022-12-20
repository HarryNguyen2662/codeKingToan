#include<bits/stdc++.h>
using namespace std;
int p[25], dd[1005][25];
vector<pair<int, int> > a[1005];
void dfs(int u, int i)
{
        dd[u][i] = 1;
        for (auto e : a[u])
        {
            int v = e.first, uv = e.second;
            if (dd[v][i] == 0 && uv >= p[i]) 
            {
                dfs(v, i);
            }
        }
}
int main()
{
    freopen("yeunhi.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k, x, y, tt, ans = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> p[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> tt;
        a[x].push_back({y, tt});
        a[y].push_back({x, tt});
    }
    for (int i = 1; i <= n; i++)
    {
        bool kt = true;
        for (int j = 1; j <= k; j++) if (dd[i][j]==1)
        {
            kt = false; break;
        } 
        if (kt)
        {
            ans ++;
            for (int j = 1; j <= k; j++) dfs(i,j);
        }
      //   for (int i = 1; i<= n ;i++)
      // {
      //   for (int j = 1; j <= k; j++) cout << dd[i][j]<<" ";
      //       cout << endl;
      //   }
      //   cout <<"=========================="<<endl;
    }

    cout << ans;
}
