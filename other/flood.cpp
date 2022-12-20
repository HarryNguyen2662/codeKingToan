#include <bits/stdc++.h>
using namespace std;
#define x first
#define y  second 
char s[1005][1005];
int n, m,k;
int xx[4] = {0,0,-1,1};
int yy[4] = {1,-1,0,0};
int tg[1005][1005],be[1005][1005];
vector<pair<int,int> > ldk;
pair<int,int> start, eend;
bool check(int e)
{
    queue<pair<int,int> > ss;
    for (int i = 1; i<= n; i++)
        for (int j = 1; j<= m; j++)
            tg[i][j] = be[i][j] = 1e9;
    for (auto v: ldk) 
        {
            tg[v.x][v.y] = 1;
            if(tg[v.x][v.y] < e)    ss.push({v.x,v.y});
        }
    while(!ss.empty())
    {
        int ox = ss.front().x;
        int oy = ss.front().y;
        ss.pop();
        for (int i = 0; i< 4; i++)
        {
            int  nx = ox + xx[i];
            int ny = oy + yy[i];
            if (nx<1||nx>n||ny<1||ny>m||(nx==start.x&&ny==start.y)||(nx==eend.x&&ny==eend.y)||tg[nx][ny]<=tg[ox][oy]+1) continue;
            tg[nx][ny] = tg[ox][oy] + 1; 
            if(tg[nx][ny] < e) ss.push({nx,ny}); 
        }
    }
    be[start.x][start.y] = 0;
    ss.push(start);
    while(!ss.empty())
    {
        int ox = ss.front().x;
        int oy = ss.front().y;
        ss.pop();
        for (int i = 0; i< 4; i++)
        {
            int nx = ox + xx[i];
            int ny = oy + yy[i];
            if (nx<1||nx>n||ny<1||ny>m) continue;
            int kt = (tg[nx][ny]!=1e9); 
            if (be[nx][ny]<=be[ox][oy]+kt) continue;
            be[nx][ny] = be[ox][oy] + kt; 
            ss.push({nx,ny}); 
        }
    }
   // cout << e << " "<< be[n][m]<<endl;
    return be[eend.x][eend.y] <= k;
}
int main ()
{
   // freopen("yeunhi.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
     queue<pair<int,int> > ss;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j<= m; j++)
        {
            tg[i][j] = 1e9;
            cin >> s[i][j];
            if (s[i][j]=='S') 
                {
                    ss.push({i,j});
                    tg[i][j] = 1;
                    ldk.push_back({i,j});
                }
            if(s[i][j]=='H') start ={i,j};
            if (s[i][j]=='G') eend = {i,j};
        }
    while(!ss.empty())
    {
        int ox = ss.front().x;
        int oy = ss.front().y;
        ss.pop();
        for (int i = 0; i< 4; i++)
        {
            int nx = ox + xx[i];
            int ny = oy + yy[i];
            if (nx<1||nx>n||ny<1||ny>m||(nx==start.x&&ny==start.y)||(nx==eend.x&&ny==eend.y)||tg[nx][ny]<=tg[ox][oy]+1) continue;
            tg[nx][ny] = tg[ox][oy] + 1; ss.push({nx,ny}); 
        }
    }
    int luu = 0;
    for (int i = 1; i<= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if ((i==start.x&&j==start.y)||(i==eend.x&&j==eend.y)) continue;
            luu = max(luu,tg[i][j]);
        }
    //cout << luu << endl;
    int l = 0, r = luu; 
    while(l <= r)
    {
        int mid = (l + r)/2;
        if(check(mid)) l = mid + 1; else r = mid - 1;
    }
   if (r==luu) cout << -1; else cout << r;
}