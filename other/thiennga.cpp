#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6;
const int oo = 1e9;
int xx[4] = {0,0,-1,1};
int yy[4]= {-1,1,0,0};
int visit[1550][1550];
int dd[1550][1550];
char s[1550][1550];
int n,m;
typedef pair<int,int> ii;
pair<int,int> stt,ed;
bool kt(int x, int y)
{
    if (x>=1&&x<=n&&y>=1&&y<=m) return true;
    return false;
}
void dfs(int x, int y)
{   
    visit[x][y]  =1;
    for (int i = 0; i< 4; i++)
    {
        int nx = x + xx[i], ny= y + yy[i];
        
        if (kt(nx,ny)&&visit[nx][ny]==0&&dd[nx][ny]!=oo) dfs(nx,ny); 
    }
}
bool check(int mid)
{
    queue<pair<int,int> > st;
    for (int i = 1; i <= n; i++)
        for(int j = 1; j<= m; j++)
        if (s[i][j]=='X')
        {
            dd[i][j] = oo;
        }
        else 
        {
            dd[i][j] = 0;
            if (mid) st.push({i,j});
        }
        while(!st.empty())
        {
            int x = st.front().f, y = st.front().s;
         //  cout <<du << endl;
            st.pop();
            for (int i = 0; i< 4; i ++)
            {
                int nx = x + xx[i], ny= y +yy[i];
                if (kt(nx,ny)&&dd[nx][ny]==oo)
                {
                    dd[nx][ny] = dd[x][y] + 1;
                    if (dd[nx][ny] < mid) st.push({nx,ny});
                }
            }
        }
    memset(visit, 0, sizeof visit);
    dfs(stt.f,stt.s);
    return (visit[ed.f][ed.s] ==1);
}
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("yeunhi.txt","r",stdin);
    #else
    // online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i<= n; i++)
        for (int j = 1; j<= m; j++)
        {
            cin >> s[i][j];
            if (s[i][j]=='L')
            {
                if (stt.f==0) stt = {i,j};
                else ed ={i,j};
            }
        }
    int l = 0, r = m*n;
    while (l <= r)
    {
        int mid = (l+r)/2;
        if (check(mid)) r = mid -1; else l = mid + 1;
    }
    cout << l;
      // cout <<stt.f <<" "<<stt.s;
   // dfs(stt.f,stt.s);
}