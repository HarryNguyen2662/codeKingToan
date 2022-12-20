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

inline long long ReadInt() 
{
    char c;
    bool negative = false;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') negative = true;
    long long x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (negative) return -x; else return x;
}

void WriteInt(long long x) 
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
int lenblock = 316, a[100005];
vector<int> blocksorted[318];
int xuly(int x, int y, vector<int> &luu)
{
    int l = (x+lenblock)/lenblock, r = (y-lenblock)/lenblock ;
    int cnt = 0;
    int t1 = x/lenblock, t2 = y/lenblock;
    if (t1 == t2)
    {
        for (auto v : blocksorted[t1])
        if (v >= x && v <= y)
        luu[cnt++] = a[v];
    }
    else
    {
        
        for (int cs1 = 0, cs2 = 0; cs1 < (int)blocksorted[t1].size() || cs2 < (int)blocksorted[t2].size(); )
        if (cs1 < (int)blocksorted[t1].size() && cs2 < (int)blocksorted[t2].size())
        {
            if (blocksorted[t1][cs1] > l*lenblock-1 || blocksorted[t1][cs1] < x) cs1++;
            else if (blocksorted[t2][cs2] > y || blocksorted[t2][cs2] < (r+1)*lenblock) cs2++;
            else if (a[blocksorted[t1][cs1]] < a[blocksorted[t2][cs2]]) luu[cnt++] = a[blocksorted[t1][cs1]], cs1++;
            else luu[cnt++] = a[blocksorted[t2][cs2]], cs2++;
        }
        else if (cs1 < (int)blocksorted[t1].size())
        {
            if (blocksorted[t1][cs1] > l*lenblock-1 || blocksorted[t1][cs1] < x) cs1++;
            else luu[cnt++] = a[blocksorted[t1][cs1]], cs1++;
        }
        else
        {
            if (blocksorted[t2][cs2] > y || blocksorted[t2][cs2] < (r+1)*lenblock) cs2++;
            else luu[cnt++] = a[blocksorted[t2][cs2]], cs2++;
        }
    }
    return cnt;
}

long long cost[100005][318];
long long cal(int l, int r, int x, int y)
{
    return cost[r][y] - (x ? cost[r][x-1] : 0) - (l ? cost[l-1][y] : 0) + (l&&x ? cost[l-1][x-1] : 0);
}
int luu[200000], id[100005];
vector<int> qa, ldk;
void solve() 
{
    int n, q;
    cin >> n >> q;
    qa.resize(n  + 3); ldk.resize(n  + 3);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        id[i] = i;
        blocksorted[i/lenblock].pb(i);
    }
    sort(id, id + n, [](const int &x, const int &y)
        {
            return a[x] < a[y];
        });
    int numblock = (n-1)/lenblock;
    for (int i = 0; i <= numblock; i++) sort(ALL(blocksorted[i]), [](const int &x, const int &y)
        {
            return a[x] < a[y];
        });
    for (int j = 0; j <= numblock; j++)
    {
        int len = (int)blocksorted[j].size();
        int cnt = 0;
        int dem = 0;
        long long su = 0;
        for (int cs1 = 0, cs2 = 0; (cs1 < n || cs2 < len); )
        {
            if(cs1 < n && cs2 < len)
            {
                if (a[id[cs1]] < a[blocksorted[j][cs2]]) 
                {
                    luu[cnt++] = id[cs1];
                    cost[id[cs1]][j] += 1ll*dem*a[id[cs1]] - su; 
                    cs1++;
                }
                else
                {
                    luu[cnt++] = -a[blocksorted[j][cs2]] - 1; 
                    dem++;
                    su -= (luu[cnt-1] + 1);
                    cs2++;
                }
            } 
            else if (cs1 < n)
            {
                luu[cnt++] = id[cs1];
                cost[id[cs1]][j] += 1ll*dem*a[id[cs1]] - su;
                cs1++;
            }
            else
            {
                luu[cnt++] = -a[blocksorted[j][cs2]] - 1; 
                dem++;
                su -= (luu[cnt-1] + 1);
                cs2++;
            }

        }
        su = 0; dem = 0;
        for (int i = cnt - 1; i >= 0; i--) if (luu[i] < 0) dem++, su -= (luu[i] + 1);
        else
        {
            cost[luu[i]][j] += su - 1ll*dem*a[luu[i]];
        }
    }
    for (int i = 0; i < n; i++) for (int j = 0; j <= numblock; j++)
    {
        if (i) cost[i][j] += cost[i-1][j];
        if (j) cost[i][j] += cost[i][j-1];
        if (i&&j) cost[i][j] -= cost[i-1][j-1];
    }
    for (int query = 1; query <= q; query++)
    {
        long long res = 0;
        int x, y, z, t;
        cin >> x >> y >> z >> t;
        x--; y--; z--; t--;
        int l = (z + lenblock)/lenblock, r = (t - lenblock)/lenblock ;
        if (l <= r) res += cal(x, y, l, r);
        int ll = (x + lenblock)/lenblock, rr = (y - lenblock)/lenblock ;
        if (ll <= rr) 
        {
            if (z/lenblock != t/lenblock)
            {
                res += cal(z, lenblock*l-1, ll ,rr);
                res += cal(lenblock*(r + 1), t, ll, rr);
            }
            else res += cal(z, t, ll, rr);
        }
        int cnt = xuly(x, y, qa), cmt = xuly(z, t, ldk);
        long long su = 0;
        int len = 0;
        int dem = 0;
        for (int cs1 = 0, cs2 = 0; cs1 < cnt || cs2 < cmt; )
        if (cs1 < cnt && cs2 < cmt)
        {
            if (qa[cs1] < ldk[cs2])
            {
                res += 1ll*dem*qa[cs1] - su;
                luu[len++] = qa[cs1];
                cs1++;
            }
            else
            {
                dem++;
                luu[len++] = -ldk[cs2] -1;
                su += ldk[cs2];
                cs2++;
            }
        }
        else
        if (cs1 < cnt)
        {
            res += 1ll*dem*qa[cs1] - su;
            luu[len++] = qa[cs1];
            cs1++;
        }
        else
        {
            dem++;
            luu[len++] = -ldk[cs2]-1;
            su += ldk[cs2];
            cs2++;
        }
        dem = 0; su = 0;
        for (int i = len - 1; i >= 0; i--) if (luu[i] < 0 ) dem++, su -= (luu[i] + 1);
        else res += su - 1ll*dem*luu[i];
        cout << res << "\n"; 
    }
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
