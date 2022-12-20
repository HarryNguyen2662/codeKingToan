#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e6 + 3;
const int MAXN = 1e6;
const int oo = 1e9;
int n , m;
int kc[3][MAXN+50]; 
vector<pair<int,int > > ldk[3][1000050]; 
void bfs(int u)
{
    for (int i = 0; i < 3; i++)
        for (int j = 1; j <= m*n; j++)
            kc[i][j] = oo;
    kc[0][u] = 0;
    queue<pair<int, int > > st;
    st.push({u,0});
    while (!st.empty())
    {
        int newe = st.front().f, type = st.front().s;
        st.pop();
     //   cout << newe <<" "<< type<<" "<< kc[type][newe]<<endl;
        for (auto v : ldk[type][newe])
            if (kc[v.s][v.f] == oo)
            {
                kc[v.s][v.f] = kc[type][newe] + 1;
                st.push({v.f, v.s});
            }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("hellodking.txt","r",stdin);
    #else
    // online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q,z;
    cin >> n >> m >> q;
    int dem = 0;
    for(int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            {
                cin >> z;
                dem++;
                if (dem-1>0&&(dem-1)%m!=0) ldk[0][dem].pb({dem-1,0});
                if (dem%m) ldk[0][dem].pb({dem+1,0});
                if (dem-m>0) ldk[0][dem].pb({dem-m,0});
                if (dem+m <= m*n) ldk[0][dem].pb({dem+m,0});
                if (z <= m*n) ldk[0][dem].pb({z,1});
                ldk[2][i*j].pb({dem,0});
                ldk[1][dem].pb({dem,2});
            }
    int x,y,u,v;
    while (q--)
    {
        cin >> x >> y >>  u >> v;
        int d1 = (x-1)*m+y, d2 = (u-1)*m+v;
        //out << d1 <<" "<<v<<endl;
        bfs(d1);
        cout<<kc[0][d2]<<endl;
    }
}