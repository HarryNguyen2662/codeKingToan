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
vector<pair<int,int>> a[100005];
vector<int> ldk[log+5][2];
int luu[100005], id[100005], idd[100005];
pair<int,int> dist[log+1][2][100005];
int n, m, k;
struct DATA
{
    pair<int,int> fii; int see;
    bool operator < (const DATA &other) const
    {
        return fii > other.fii;
    }
};
void dij(int t, bool tt)
{
    priority_queue<DATA> pq;
    for (auto v : ldk[t][tt])
    {
        dist[t][tt][v].fi = 0; dist[t][tt][v].se = id[v];
        //if (v == 3) cout << id[v] << endl;
        pq.push({dist[t][tt][v], v});
    }
    while(!pq.empty())
    {
        int u = pq.top().see;
        pair<int,int> len = pq.top().fii;
        pq.pop();
        if (len != dist[t][tt][u]) continue;
        //if (t == 0 && tt == 0) cout << u << " " << len << endl;
        for (auto v : a[u])
        if (dist[t][tt][v.fi] > make_pair(len.fi + v.se, len.se))
        {
            //if (t == 0 && tt == 0) cout << "ui " << v.fi << endl;
            dist[t][tt][v.fi] = {len.fi + v.se, len.se};
            pq.push({dist[t][tt][v.fi], v.fi});
        } //else 
    }
}
void solve() 
{
	   
    cin >> n >> m >> k;
	for (int i = 1; i <= k; i++)
    {
        cin >> luu[i];
        if (id[luu[i]] == 0)
        {
            id[luu[i]] = i;
            for (int j = 0; j < log; j++) if (ck(luu[i], j)) ldk[j][1].pb(luu[i]);
            else ldk[j][0].pb(luu[i]);
        } else if (idd[luu[i]] == 0) idd[luu[i]] = i;
        
    }
    //   cout << m << endl;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[u].pb({v, w});
		a[v].pb({u, w});
        assert(w <= 10000);
	}
    //cout << a[2].size() << endl;
    for (int i = 1; i <= n; i++) for (int j = 0; j <= log; j++) dist[j][0][i].fi = dist[j][1][i].fi = oo+1;
	for (int i = 0; i < log; i++) dij(i, 0), dij(i, 1);
    for (int i = 1; i <= k; i++)
    {
        pair<int,int> len = {oo+1, 0};
        for (int j = 0; j < log; j++) len = min(len, dist[j][1-ck(luu[i], j)][luu[i]]);
        if (id[luu[i]] < i)
        {
            if (len.fi == 0) cout << min(len.se, id[luu[i]]) << " ";
            else cout << id[luu[i]] << " ";
        }
        else if (idd[luu[i]] != 0)
        {
      //      cout << len.fi << endl;
            if (len.fi == 0) cout << min(len.se, idd[luu[i]]) << " ";
            else cout << idd[luu[i]] << " ";   
        }
        else cout << len.se << " ";
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
