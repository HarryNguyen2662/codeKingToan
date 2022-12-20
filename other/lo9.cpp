#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 19
#define mask(i) (1 << (i))
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6+5;
const int oo = 1e9;
const long long oo18 = 1e18;
int n;
int maxflow = 0;
struct ldk
{
    int xx,yy,zz;
};
vector<ldk> inp;
int xi[6] = {-1,0,0,0,0,1};
int xj[6] = {0,-1,0,0,1,0};
int xe[6] = {0,0,-1,1,0,0};
pair<int,int> trace[102][102][102];
int f[102][102][102][6];
int dem = 0;
ldk ed;
bool check(int i, int j, int e)
{
    if (i < 0 || i > 101) return false;
    if (j < 0 || j > 101) return false;
    if (e < 0 || e > 101) return false;
    return true;
}
bool bfs()
{
    queue<ldk> q;
    for (auto v : inp)
    {
        q.push(v); trace[v.xx][v.yy][v.zz].se = dem;
    }
    while(!q.empty())
    {
        int i = q.front().xx, j = q.front().yy, e = q.front().zz;
        q.pop();
        
        for (int cs = 0; cs < 6; cs++)
        {
            int newi=i+xi[cs], newj=j+xj[cs], newe=e+xe[cs];
            if (!check(newi,newj,newe)) continue;
             
            if (trace[newi][newj][newe].se != dem && f[i][j][e][cs] < 1)
            {
                trace[newi][newj][newe] = {cs, dem};
                if(newi == 0|| newj == 0||newe==0||newi==101||newj==101||newe==101) 
                {
                   ed = {newi,newj,newe};
                   return true;
                }
                q.push({newi,newj,newe});
            }
        }

    }
    return false;
}
void incmaxflow()
{
    int t1,t2,t3; 
    t1=ed.xx; t2=ed.yy; t3= ed.zz;
    while(trace[t1][t2][t3].fi!=-1)
    {
        int e = trace[t1][t2][t3].fi;
        f[t1][t2][t3][5-e] --;
        t1+=xi[5-e]; t2+=xj[5-e]; t3+=xe[5-e];
        f[t1][t2][t3][e] ++;
    }
    maxflow++;
    return;
        
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int i,j,e;
    while(n--)
    {
        
        cin >> i >> j >> e;
        i++; j++; e++;
        trace[i][j][e].fi = -1;
        inp.pb({i,j,e});
    }
    dem++;
    while(bfs()) 
        {
            //dem++;
            incmaxflow();
        }
    //cout << f[1][1][1][0]<<endl;
    cout << maxflow;
}