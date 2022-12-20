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

struct DATA
{
    int x, r, t;
} a[200005];

int fen[200005];
long long cnt[200005][55];

vector<int> id[200005], val[200005];

const int lim = 200003;

void update(int id)
{
    for (; id <= lim; id += (id&(-id))) fen[id]++;
}

int get(int id)
{
    int res = 0;
    for (; id; id -= (id&(-id))) res += fen[id];
    return res;
}

long long cal(int ti)
{
    long long res = 0;

    for (int i = 1; i <= (int)val[ti].size(); i++) fen[i] = 0;
   
    for (auto v : id[ti])
    {
        const DATA &cur = a[v]; 
        int le = lower_bound(ALL(val[ti]), cur.x - cur.r) - val[ti].begin() + 1;
        int ri = upper_bound(ALL(val[ti]), cur.x + cur.r) - val[ti].begin();
        if (le <= ri)
        {   
            res += get(ri) - get(le - 1);
        }   
        update(lower_bound(ALL(val[ti]), cur.x) - val[ti].begin() + 1);
    }

    return res;
}

long long cal1(int ti, int ti1, bool w)
{
    long long res = 0;

    int i = -1;

    for (int i = 1; i <= (int)val[ti].size(); i++) fen[i] = 0;

    for(auto v : id[ti1])
    {
        const DATA &cur = a[v];
        while(i + 1 < (int)id[ti].size() && a[id[ti][i + 1]].r >= cur.r + w) 
        {
            i++;
            update(lower_bound(ALL(val[ti]), a[id[ti][i]].x) - val[ti].begin() + 1);
        }

        int le = lower_bound(ALL(val[ti]), cur.x - cur.r) - val[ti].begin() + 1;
        int ri = upper_bound(ALL(val[ti]), cur.x + cur.r) - val[ti].begin();
        if (le <= ri)
        {   
            res += get(ri) - get(le - 1);
        }   
    }

    return res;
}

bool cmp(const int &vt, const int &vt1)
{
    return a[vt].r > a[vt1].r;
}

void solve() 
{
    vector<int> diff;
    int n, q;
	cin >> n >> n >> q;
	for (int i = 1; i <= n ;i++)
	{
	   cin >> a[i].x >> a[i].r >> a[i].t;
	   
       diff.pb(a[i].t);
    }
    
    sort(ALL(diff));
    diff.resize(unique(ALL(diff)) - diff.begin()); 

    for (int i = 1; i <= n; i++)
    {
        a[i].t = lower_bound(ALL(diff), a[i].t) - diff.begin();
        id[a[i].t].pb(i);
        val[a[i].t].pb(a[i].x);
    }

    for (int i = 0; i < (int)diff.size(); i++)
    {
        sort(ALL(id[i]), cmp); sort(ALL(val[i]));
    }

    for (int i = 0; i < (int)diff.size(); i++)
    {
        cnt[i][0] = cal(i);
        for (int j = i + 1; j < (int)diff.size(); j++)
        {
            if (diff[j] - diff[i] > 50) break;
            cnt[i][diff[j] - diff[i]] = cal1(i, j, 0) + cal1(j, i, 1);
        }

        for (int j = 1; j <= 50; j++) cnt[i][j] += cnt[i][j-1];
    }

    while(q--)
    {
        int u, v;
        cin >> u >> v;
        u = lower_bound(ALL(diff), u) - diff.begin() ;
        long long res = 0;

        for (; u < (int)diff.size() && diff[u] <= v; u++)
        {
            res += cnt[u][v - diff[u]];
        }

        cout << res << " ";
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
    //freopen("lovesharing.inp","r",stdin); freopen("lovesharing.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
