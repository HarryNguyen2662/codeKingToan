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
int par[200005], ed[200005], st[200005];
int findpar(int u)
{
	return par[u] < 0 ? u : par[u] = findpar(par[u]);
}
void merge(int u, int v)
{
	u = findpar(u); v = findpar(v);
	if (u == v) return;
	if (par[u] > par[v]) swap(u, v);
	par[u] += par[v];
	par[v] = u;
}
void solve() 
{
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) st[i] = ed[i] = i, par[i] = -1;
	while(q--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int u, v;
			cin >> u >> v;
			merge(st[u], st[v]);
		}
		else if (type == 2)
		{
			int l, r;
			cin >> l >> r;
			for (int i = ed[st[l]]+1; i <= r; i = ed[i] + 1)
			{
				merge(st[i-1], st[i]);
				ed[st[i-1]] = max(ed[st[i-1]], ed[r]);
				st[i] = min(st[i], st[l]);
			}
			
		}
		else
		{
			int u, v;
			cin >> u >> v;
			if (u > v) swap(u, v);
			if (ed[u] >= v || findpar(st[u]) == findpar(st[v])) cout << "YES\n"; else cout << "NO\n";
		}
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
