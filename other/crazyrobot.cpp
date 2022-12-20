#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 17
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1ll << (i))
#define ck(n, i) (((n) >> (i))&1) 
#define setp(x) setprecision(x)
#define NMOD 3
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789; 
const int lim = 1e6 + 2;;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 922372036854775807;
pair<int,int> xy[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
vector<int> sl[1000005];
vector<bool> visit[1000005];
vector<char> s[1000005]; 
void solve()
{
    int n, m;
    cin >> n >> m;
    pair<int,int> st;
    for (int i = 1; i <= n; i++) 
    {
        s[i].assign(m + 2, 0);
        sl[i].assign(m + 2, 0);
        visit[i].assign(m + 2, false);
        for (int j = 1; j <= m; j++)
        {
            cin >> s[i][j];// cout << s[i][j];
            if (s[i][j] == 'L')
            {
                //cout << "alo" << endl;
                st = {i, j};
            }       
        }
       // cout << endl;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m ;j++)
        if (s[i][j] != '#')
        {
            for (int e = 0; e < 4; e++)
            {
                int x = i + xy[e].fi, y = j + xy[e].se;
                if (x >= 1 && x <= n && y >= 1 && y <= m && s[x][y] != '#') sl[i][j]++;
            }
        }
    queue<pair<int,int> > inque;
    inque.push(st); 
    //cout << st.fi << " " <<st.se << endl;
    visit[st.fi][st.se] = true;
    while(!inque.empty())
    {
        int x = inque.front().fi, y = inque.front().se; inque.pop();
        for (int e = 0; e < 4; e++)
        {
            int nx = x + xy[e].fi, ny = y + xy[e].se;
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && visit[nx][ny] == false && s[nx][ny] != '#')
            {
                sl[nx][ny]--;
                if (sl[nx][ny] <= 1)
                {
                    visit[nx][ny] = true;
                    inque.push({nx, ny});
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) if (visit[i][j] && s[i][j] != 'L') cout << "+"; else cout << s[i][j];
        cout << "\n";
        sl[i].clear(); s[i].clear(); visit[i].clear();
    }
}
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    // 
    #endif
    //freopen("dienbien.inp","r",stdin); freopen("dienbien.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}