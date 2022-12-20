#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
#define fi first
#define se second
#define pb push_back
#define log 17
#define mask(i) (1ll << (i))
#define setp(x) setprecision(x)
#define ALL(v) v.begin(), v.end()
#define ck(n, i) (((n) >> (i)) & 1) 
#define getbit(x) __builtin_popcount(x)

const double PI = acos(-1);
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const ll oo = 1e15;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<pair<int,int>> a[100005];
pair<long long,long long> dd[100005];
int b[100005];

void solve() 
{ 
      int n, m, u, v, c;

      cin >> n;
    
    for (int i = 1; i<= n; i++)
    {
       cin >> b[i];
    }
    cin >> m;
    for (int i = 1; i<= m; i++)
    {
      cin >> u >> v >> c;
      a[u].pb({v,c});
      a[v].pb({u,c});
    }
    priority_queue< pair<pair<long long,long long>,int>, vector<pair<pair<long long,long long>,int> >, greater<pair<pair<long long,long long>,int> >  > q;
    dd[1] = {0, b[1]};
    q.push({{dd[1].fi,-dd[1].se},1});
    for (int i = 2; i <= n; i++) dd[i].fi = oo;
    while(!q.empty())
    {
      int u = q.top().se;
      long long dodai =q.top().fi.fi;
      long long banh = -q.top().fi.se;
    //  cout << u << " "<<dodai<<" "<<banh<<endl;
      q.pop();
      if (dd[u].fi!=dodai||dd[u].se!=banh) continue;
      for (auto v: a[u])
      {
        int di = v.fi;
        long long dc = v.se;   
        //cout <<"check "<<di <<" "<<dc<<endl;
        if (dd[di].fi > dd[u].fi + dc)
        {
          dd[di].fi = dd[u].fi +dc;
          dd[di].se = dd[u].se +b[di];
          q.push({{dd[di].fi,-dd[di].se}, di});
        } else if (dd[di].fi == dd[u].fi+dc && dd[di].se < dd[u].se +b[di])
        {
           dd[di].se = dd[u].se +b[di];
            q.push({{dd[di].fi,-dd[di].se}, di});
        }
      }
    }   
    if (dd[n].fi == oo)
    cout <<"impossible"; 
    else 
    cout <<dd[n].fi <<" "<<dd[n].se;
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("quanho.inp","r",stdin); freopen("quanho.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
