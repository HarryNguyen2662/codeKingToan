#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 18
#define mask(i) (1 << (i))
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6+5;
const int oo = 1e9;
int res = oo;
int dd = 0;
bool visit[200005];
vector<pair<int,int> >a[200005];
int numchild[200005];
int maxnumchild[200005];
int dem[1000005];
int dp[1000005];
int k;
void centroid(int u)
{
    numchild[u] = 1; maxnumchild[u] = 0;
    visit[u] = true;
    for (auto v : a[u])
      if (visit[v.fi] == false)
      {
          //if (u == 3) cout <<"check "<<v.fi <<endl;
          centroid(v.fi);
          if (numchild[v.fi] > numchild[maxnumchild[u]]) maxnumchild[u] = v.fi;
          numchild[u] += numchild[v.fi];
      }
    visit[u] = false;
}
int findcentroid(int u)
{
    int num = numchild[u]/2;
    while(numchild[maxnumchild[u]] > num)
      u = maxnumchild[u];
    return u;
}
void update(int x)
{
    if (dem[x]!=dd)
    {
      dem[x] = dd; dp[x] = oo;
    }
}
void dfs(int u, int height, int dist)
{
    if (dist > k) return;
    if (k == dist) 
      {
        res =min(res, height);
        return;
      }
    visit[u] = true;
     update(k-dist);
     res = min(res, height + dp[k-dist]);
    for(auto v : a[u])
    if (visit[v.fi] == false)
    {
      dfs(v.fi, height+1, dist + v.se);
    }
    visit[u] = false;
}
void dfs1(int u, int height, int dist)
{
    if (dist >= k) return;
    visit[u] = true;
     update(dist);
     dp[dist] = min(dp[dist], height);
    for(auto v : a[u])
    if (visit[v.fi] == false)
    {
      dfs1(v.fi, height+1, dist + v.se);
    }
    visit[u] = false;
}
void buildcentroidtree(int u = 1)
{
    centroid(u);
    //cout << u << " "<<numchild[u]<<" ";
    u = findcentroid(u);
    //cout << u << endl;
    dd++;
    visit[u] = true;
    for (auto v : a[u])
    if(visit[v.fi] == false)
    {
    dfs(v.fi, 1, v.se);
     dfs1(v.fi, 1, v.se);
   }
    for (auto v : a[u])
    if (visit[v.fi] == false)
    {
      buildcentroidtree(v.fi);
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    #else
    //online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, u ,v , uv;
    cin >> n >> k;
    for (int i= 1; i< n; i++)
    {
      cin >> u >> v >> uv;
      a[u+1].pb({v+1,uv});
      a[v+1].pb({u+1,uv});
    }
    buildcentroidtree();
    if(res == oo) cout <<-1; else cout << res;
}