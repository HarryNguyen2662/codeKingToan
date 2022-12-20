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
const int oo = 2e9;
int x[4] = {-1, 0, 1, 0};
int y[4] = {0, -1, 0, 1};
int n;
bool check(int xx, int yy)
{
    return (1<=xx&&xx<=n&&1<=yy&&yy<=n);
}
struct egd
{
    int dai;
    pair<int,int> cs;
    int nd, p;
} ;
int dd[1001][1001][2][2], d[1001][1001][2][2];
int a[1001][1001];
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
    pair<int,int> st, ed;
    int sum=0;
    cin >> n;
    for (int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        {
          cin >> a[i][j];
          sum+=a[i][j];
          dd[i][j][0][0] = dd[i][j][0][1] = dd[i][j][1][0] =dd[i][j][1][1] = oo;
          d[i][j][0][0] = d[i][j][0][1] = d[i][j][1][0] =d[i][j][1][1] = oo;
        }
    cin >> st.fi >> st.se >> ed.fi >> ed.se;
    queue<egd> q;
    dd[st.fi][st.se][0][0] = dd[st.fi][st.se][1][0] = 0;
    q.push({0, st, 0, 0}); q.push({0, st, 1, 0});
    while(!q.empty())
    {
        int dodai = q.front().dai;
        pair<int,int> u = q.front().cs;
        int chieu = q.front().nd;
        int sovatbipha = q.front().p;
        q.pop();
        if (dd[u.fi][u.se][chieu][sovatbipha]!= dodai) continue;
        for (int i = 0; i < 4; i++)
        if(check(u.fi+x[i], u.se + y[i]))
        {
          pair<int,int> uu = {u.fi+x[i], u.se + y[i]};
          int congthem = (chieu == ((i+1)%2));
          //cout<< uu.fi <<" "<<uu.se <<" "<< i%2<<" "<<congthem<<endl;
          if(a[uu.fi][uu.se]*sovatbipha == 0)
          {
            int newchieu = max(sovatbipha, a[uu.fi][uu.se]);
            if(dd[uu.fi][uu.se][i%2][newchieu] > dodai + congthem)
            {
                dd[uu.fi][uu.se][i%2][newchieu] = dodai + congthem;
                q.push({dd[uu.fi][uu.se][i%2][newchieu],uu,i%2, newchieu});
            }
          }
        }
    }
    //cout << dd[5][2][0][0]<<" "<<dd[2][2][1][0]<<endl;
    int kq = min(dd[ed.fi][ed.se][0][0], dd[ed.fi][ed.se][1][0]);
    int kqq = min(dd[ed.fi][ed.se][0][1], dd[ed.fi][ed.se][1][1]);
    cout <<kq <<" ";
    cout << kqq <<" ";
    d[ed.fi][ed.se][0][0] = d[ed.fi][ed.se][1][0] = 0;
    q.push({0, ed, 0, 0}); q.push({0, ed, 1, 0});
    while(!q.empty())
    {
        int dodai = q.front().dai;
        pair<int,int> u = q.front().cs;
        int chieu = q.front().nd;
        int sovatbipha = q.front().p;
        q.pop();
        if (d[u.fi][u.se][chieu][sovatbipha]!= dodai) continue;
        for (int i = 0; i < 4; i++)
        if(check(u.fi+x[i], u.se + y[i]))
        {
          pair<int,int> uu = {u.fi+x[i], u.se + y[i]};
          int congthem = (chieu == (i+1)%2);
          if(a[uu.fi][uu.se]*sovatbipha == 0)
          {
            int newchieu = max(sovatbipha, a[uu.fi][uu.se]);
            if(d[uu.fi][uu.se][i%2][newchieu] > dodai + congthem)
            {
                d[uu.fi][uu.se][i%2][newchieu] = dodai + congthem;
                q.push({d[uu.fi][uu.se][i%2][newchieu],uu,i%2, newchieu});
            }
          }
        }
    }
    //cout << d[st.fi][st.se][1][0]<<endl;
    if (kq==kqq)
    {
      cout << sum;
      return 0;
    }
    int dem = 0;
    for (int i = 1; i<= n; i++)
      for (int j = 1; j <= n; j++)
        if(a[i][j]&&(dd[i][j][0][1]+d[i][j][0][1] == kqq||kqq==dd[i][j][1][1]+d[i][j][1][1]))
          dem++;
    cout << dem;
}