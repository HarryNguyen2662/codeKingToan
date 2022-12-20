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
vector<pair<int, bool>> a[100005], b[100005];
int dd[100005];
bool bd[100005];
void solve() 
{
	int n, m, q;
	cin >> n >> m >> q;
	int sl = 0;
	for (int i = 1; i <= m; i++)
	{
		int u, v; bool c;
		cin >> u >> v >> c;
		a[u].pb({v, c});
		a[v].pb({u, c});
		if (c) dd[u]++, dd[v]++, sl++;
	}
	for (int i = 1; i <= n; i++) if ((int)a[i].size() <= 300)
	{
		b[i] = a[i];
	}
	else
	{
		for (auto v : a[i]) if ((int)a[v.fi].size() > 300) b[i].pb(v);
	}
	
	while(q--)
	{
		int u;
		cin >> u;
		
		if ((int)a[u].size() > 300)
		{
			bd[u] = 1 - bd[u];
			sl -= dd[u];
			dd[u] = (int)a[u].size() - dd[u];
			sl += dd[u];
			for (auto v : b[u]) if ((v.se^bd[u]^bd[v.fi]) == 1) dd[v.fi]++; else dd[v.fi]--;	
		}
		else
		{
			dd[u] = 0;
			for (auto v : b[u]) 
			{
				if ((v.se^bd[u]^bd[v.fi]) == 1) dd[u]++; 
			}
			bd[u] = 1 - bd[u]; 
			sl -= dd[u];
			dd[u] = (int)a[u].size() - dd[u];
			sl += dd[u];
			for (auto v : b[u]) if ((v.se^bd[u]^bd[v.fi]) == 1) dd[v.fi]++; else dd[v.fi]--;
		}
		cout << sl << " ";
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
