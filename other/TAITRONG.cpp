#include<bits/stdc++.h>
using namespace std;
int f[1005],n,ss,t;
vector<pair<int,int> > a[1005];
priority_queue<pair<int,int>, vector<pair<int,int> > , greater<pair<int,int> > > s;
void input()
{
    int x, y ,z,m;
    cin >> n >> m >> ss >>t;
    for (int i = 0; i <  m; i++)
    {
        cin >> x >>y >> z;
        a[x].push_back({z,y});
        a[y].push_back({z,x});
    }
}
void solve()
{
    f[ss] = 1e7;
    s.push({f[ss],ss});
    while (s.size())
    {
        int u = s.top().second;
        int giatri = s.top().first;
     //   cout << u << " " << giatri<< endl;
        s.pop();
        //if (giatri!=f[u]) continue;
        for (auto v : a[u])
        {
            int d1 = v.second, d2 = v.first;
            if (f[d1] < min(giatri,d2))
            {
                f[d1] = min(giatri,d2);
               // cout << d1 << " "<< d2 << endl;
                s.push({f[d1],d1});
            }
        } 
    }
    //cout << "f" << t << endl;
	if (f[t] == 0 ) cout << -1 ; else cout << f[t];
}
int main()
{
  freopen("TAITRONG.INP","r",stdin);
   freopen("TAITRONG.OUT","w",stdout);
  	input();
	solve();
}