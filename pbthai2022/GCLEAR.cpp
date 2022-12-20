#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
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

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int xx[4] = {-1, 1, 0, 0};
int yy[4] = {0, 0, -1, 1};

char s[1005][1005];
int d[1005][1005];

void solve() 
{
	int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) 
    {
        d[i][j] = -1;
        cin >> s[i][j];
    }

    int x, y, u, v; cin >> x >> y;
    string go; cin >> go; cin >> u >> v;
    queue<pair<int,int>> iq;
    d[u][v] = 0;
    iq.push({u, v});
    while(!iq.empty())
    {
        u = iq.front().fi; v = iq.front().se; iq.pop();
        for (int i = 0; i < 4; i++)
        {
            int nu = u + xx[i], nv = v + yy[i];
            if (1 <= nu && nu <= n && 1 <= nv && nv <= m && d[nu][nv] == -1 && s[nu][nv] == '0')
            {
                d[nu][nv] = d[u][v] + 1;
                iq.push({nu, nv});
            }
        }
    }


    for (int i = 0; i < (int)go.size(); i++)
    {
        if (go[i] == 'U')
        {
            x += xx[0]; y += yy[0];
        }
        else if (go[i] == 'D')
        {
            x += xx[1]; y += yy[1];
        }
        else if (go[i] == 'L')
        {
            x += xx[2]; y += yy[2];
        }
        else if (go[i] == 'R')
        {
            x += xx[3]; y += yy[3];
        }

        if (d[x][y] != -1 && i + 1 >= d[x][y] && i%2 != d[x][y]%2)
        {
          //  cout << x << " " << y << endl;
          //  cout << d[x][y] << endl;
            cout << i + 1;
            return;
        }
    }

    cout << -1;

}   

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
