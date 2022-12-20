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
int st[1000005];
vector<pair<bool, pair<int,int>>> ldk[1000005];
int cmt[1000005], cnt[1000005];
void update(int id, int l, int r, int u, int v, int val)
{
    if (r < u || l > v) return;
    if (u <= l && r <= v)
    {
        st[id] += val;
        return;
    }
    int mid = (l + r)/2;
    update(id*2, l, mid, u, v, val); update(id*2+1, mid + 1, r, u, v, val);
   // cout << l << " " << r << endl;
    cmt[id] = (st[id*2] > 0 ? cnt[mid] - cnt[l-1] : cmt[id*2]) + (st[id*2+1] > 0 ? cnt[r] - cnt[mid] : cmt[id*2+1]);
    //cout << cmt[id] << endl;
}
struct RECT
{
    int x1, y1, x2, y2;
    void input()
    {
        cin >> x1 >> y1 >> x2 >> y2;
    }
};
RECT a[100005];
void solve() 
{
    int n;
    //vector<pair<bool, pair<int,int>>> ldk;
    vector<int> diff, diff1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i].input();
       // a[i].x2++;
        if (a[i].x1 > a[i].x2 || a[i].y1 > a[i].y2) continue;
        diff.pb(a[i].y1); diff.pb(a[i].y2);
        diff1.pb(a[i].x1); diff1.pb(a[i].x2);
    }
    sort(ALL(diff)); sort(ALL(diff1)); 
    diff.resize(unique(ALL(diff)) - diff.begin());
    diff1.resize(unique(ALL(diff1)) - diff1.begin());
   // cout << n << endl;
    for (int i = 1 ; i <= n; i++)
    {
        if (a[i].x1 > a[i].x2 || a[i].y1 > a[i].y2) continue;
        int l = lower_bound(ALL(diff), a[i].y1) - diff.begin() + 1;
        int r = lower_bound(ALL(diff), a[i].y2) - diff.begin() + 1;
        a[i].x1 = lower_bound(ALL(diff1), a[i].x1) - diff1.begin();
        a[i].x2 = lower_bound(ALL(diff1), a[i].x2) - diff1.begin();
        ldk[a[i].x1].pb({0, {l, r}});
        ldk[a[i].x2].pb({1, {l, r}});
    }
   // cout << (int)ldk.size();
    n = (int)diff.size();
    for (int i = 1; i < n; i++)
    {
        cnt[i] = cnt[i-1] + diff[i] - diff[i-1];
    }
    n--;
    long long res = 0;
    for (auto v : ldk[0])
    if (!v.fi)
    {
        update(1, 1, n, v.se.fi, v.se.se-1, 1);
    }
    //cout << cnt[3] << " " << cnt[1] << endl;
    //cout << ldk[0][0].se.fi << " " << ldk[0][0].se.se << endl;
    //res += (st[1] > 0 ? cnt[n] : cmt[1]);
    //cout << (st[1] > 0 ? cnt[n] : cmt[1]) << endl;
    for (auto v : ldk[0])
    if (v.fi)
    {
        update(1, 1, n, v.se.fi, v.se.se-1, -1);
    }
    for (int i = 1; i < (int)diff1.size(); i++)
    {
        res += 1ll*(st[1] > 0 ? cnt[n] : cmt[1])*(diff1[i] - diff1[i-1]);
        //cout << (st[1] > 0 ? cnt[n] : cmt[1]) << endl;
        for (auto v : ldk[i])
        if (v.fi)
        {
            update(1, 1, n, v.se.fi, v.se.se-1, -1);
        }
        else
        {
            update(1, 1, n, v.se.fi, v.se.se-1, 1);
        }
       // cout << "sau\n";
        //cout << (st[1] > 0 ? cnt[n] : cmt[1]) << endl;
    }
    
    cout << res;
}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
