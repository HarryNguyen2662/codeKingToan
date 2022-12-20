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
	int fii, see, thi;
};
vector<DATA> a[100005];
long long d[100005], dist[2][100005];
void solve() 
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> d[i];
	for (int i = 1; i <= m; i++)
	{
		int u, v, w, w1;
		cin >> u >> v >> w >> w1;
		a[u].pb({v, w, w1}); a[v].pb({u, w, w1});
	}
	priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long,int > > > pq;
	for (int i = 1; i <= n; i++) dist[0][i] = dist[1][i] = oo15;
	dist[0][1] = 0;
	pq.push({0, 1});
	while(!pq.empty())
	{
		int u = pq.top().se;
		long long dai = pq.top().fi;
		pq.pop();
		if (dai != dist[0][u]) continue;
		for (auto v : a[u])
		if (dist[0][v.fii] > dai + v.see)
		{
			dist[0][v.fii] = dai + v.see;
			pq.push({dist[0][v.fii], v.fii});
		}
	}
	//cout << dist[0][2] << endl;
	dist[1][n] = 0;
	pq.push({0, n});
	while(!pq.empty())
	{
		int u = pq.top().se;
		long long dai = pq.top().fi;
		pq.pop();
		if (dai != dist[1][u]) continue;
		for (auto v : a[u])
		if (dist[1][v.fii] > dai + v.see)
		{
			dist[1][v.fii] = dai + v.see;
			pq.push({dist[1][v.fii], v.fii});
		}
	}
	for (int i = 1; i <= n; i++) pq.push({d[i], i});
	//int dem = 0;
	while(!pq.empty())
	{
		//;dem++;
		//if (dem == 100) break;
		int u = pq.top().se;
		long long dai = pq.top().fi;
		//cout << u << " " << dai << endl;
		pq.pop();
		if (dai != d[u]) continue;
		for (auto v : a[u])
		if (d[v.fii] > v.see + v.thi + dai)
		{
			d[v.fii] = v.see + v.thi + dai;
			pq.push({d[v.fii], v.fii});
		}
	}
	long long res = oo15;
	for (int i = 1; i <= n; i++) res = min(res, dist[0][i] + d[i] + dist[1][i]);
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
