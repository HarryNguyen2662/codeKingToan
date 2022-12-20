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
vector<pair<int,int>> a[300005];
int dist[300005];
void solve() 
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb({v, i});
	}
	for (int i = 1; i <= n; i++) dist[i] = oo;
	dist[1] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0, 1});
	while(!pq.empty())
	{
		int u = pq.top().se;
		int len = pq.top().fi;
		pq.pop();
		for (auto v : a[u])
		if (dist[v.fi] > max(v.se, len))
		{
			dist[v.fi] = max(v.se, len);
			pq.push({dist[v.fi], v.fi});
		}
	}
	if (dist[n] == oo)
	{
		cout << -1;
		return;
	}
	cout << dist[n];
}

int main() 
{   
    freopen("TAIDIEN.inp","r",stdin); freopen("TAIDIEN.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
