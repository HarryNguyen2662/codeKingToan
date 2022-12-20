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
struct DATA
{
	int ver, ver1, ed, tele, len;
	bool operator < (const DATA &other) const
	{
		return len > other.len;
	}
};
int n, m, p, l, k, dist[10005][12][12];
vector<pair<int,int>> a[10005];
void solve() 
{
	
	cin >> n >> m >> p >> l >> k;
	//cout << p << " " << l << " " << k << endl;
	for (int i = 1; i <= m; i++) 
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[u].pb({v, w}); a[v].pb({u, w});
	}
	for (int i = 1; i <= n; i++) for (int sc = 0; sc <= l; sc++) for (int sd = 0; sd <= k; sd++)
	dist[i][sc][sd] = oo+100;
	priority_queue<DATA> qe;
	dist[1][0][0] = 0;
	qe.push({1, 1, 0, 0, 0});
	while(!qe.empty())
	{
		DATA w = qe.top(); qe.pop();
		int u = w.ver, sc = w.ed, sd = w.tele, dai = w.len, uu = w.ver1;
		if (dai != dist[u][sc][sd]) continue;
		cout << u << " " << sc << " " << sd << " " << dai << endl;
		for (auto v : a[u])
		{
			if (dist[v.fi][min(sc+1, l)][sd] > dai + v.se)
			{
				 dist[v.fi][min(sc+1, l)][sd] = dai + v.se;
				 qe.push({v.fi, uu, min(sc+1, l), sd, dai + v.se});
			}
			if (sc + 1 <= l && sd + 1 <= k && dist[v.fi][0][sd+1] > dist[uu][0][sd] + p)
			{
				dist[v.fi][0][sd+1] = dist[uu][0][sd] + p;
				qe.push({v.fi, v.fi, 0, sd + 1, dist[uu][0][sd] + p});
			}
		}
	}
	int res = oo + 100;
	for (int i = 0; i <= l; i++) for (int j = 0; j <= k; j++) res = min(res, dist[n][i][j]);
	cout << res;
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
