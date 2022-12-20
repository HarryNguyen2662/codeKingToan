#include <bits/stdc++.h>
using namespace std;
struct LDK{
    int x,y,buoc;
};
int xx[8] = {2,2,1,1,-1,-1,-2,-2};
int yy[8] = {-1,1,-2,2,-2,2,-1,1};
int n, m;
int a[1001][1001];
int main()
{
   //freopen("lololoin.txt","r",stdin);
    freopen("QUANMA.inp","r",stdin);
    freopen("QUANMA.out","w",stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int mx,my;
    LDK batdau;
    cin >> batdau.x >> batdau.y >> mx >> my;
    a[batdau.x][batdau.y]=1;
    batdau.buoc =0;
    queue <LDK> king;
    king.push(batdau);
    while(!king.empty())
    {
        LDK ttt = king.front();
        king.pop();
        if(ttt.x == mx && ttt.y == my)
        {
            cout << ttt.buoc;
            return 0;
        }
        for(int i =0; i<=7;i++)
        {
            int x1=ttt.x+xx[i];
            int y1=ttt.y+yy[i];
            if((x1>=1&&x1<=n) &&(y1>=1&&y1<=m)&&a[x1][y1]==0)
            {
                a[x1][y1]=1;
                LDK ans;
                ans.x = x1;
                ans.y = y1;
                ans.buoc=ttt.buoc + 1;
                king.push(ans);
            }
        }
    }
    cout << -1;
    return 0;
}