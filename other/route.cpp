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
vector<pair<int, pair<int,int>>> a[1005];
typedef pair<pair<long long, int>, int> DATA;
int n, luu[1005];
pair<long long,int> dist[1005];
void dij(int u)
{
	for (int i = 1; i <= 1000; i++) dist[i].fi = oo15, dist[i].se = oo;
	dist[u].fi = 0; dist[u].se = 0;
	priority_queue<DATA, vector<DATA>, greater<DATA>> pq;
	pq.push({{0, 0}, u});
	while(!pq.empty())
	{
		u = pq.top().se; long long len = pq.top().fi.fi; int sl = pq.top().fi.se;
		pq.pop();
		//cout << u << " " << len << " " << sl << endl;
		if (dist[u].fi != len || dist[u].se != sl) continue;
		//cout << a[u][0].fi << endl;
		for (auto v : a[u])
		if (dist[v.fi].fi > len + v.se.fi)
		{
			dist[v.fi].fi = len + v.se.fi;
			dist[v.fi].se = sl + v.se.se;
			pq.push({dist[v.fi], v.fi});
		} else if (dist[v.fi].fi == len + v.se.fi && dist[v.fi].se > sl + v.se.se)
		{
			dist[v.fi].se = sl + v.se.se;
			pq.push({dist[v.fi], v.fi});
		}
	}	
}
void solve() 
{
	int st, ed;
	cin >> st >> ed >> n;
	for (int i = 1; i <= n; i++)
	{
		int w, m;
		cin >> w >> m;
		for (int j = 1; j <= m; j++)
		{
			cin >> luu[j];
			//cout << luu[i] << endl;
		}
		for (int j = 1; j <= m; j++) for (int e = j + 1; e <= m; e++)
		a[luu[j]].pb({luu[e], {w, e - j}});
	}
	dij(st);
	if (dist[ed].fi == oo15)
	{
		cout << "-1 -1"; return;
	}
	cout << dist[ed].fi << " " << dist[ed].se;
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
