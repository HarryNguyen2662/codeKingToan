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
	int ver1, ver2, va;
	bool operator < (const DATA &other) const
	{
		return va > other.va;
	}
};
int par[100005], cs[100005], pre[100005], lst[100005], giatri[100005], luu[100005], lg[100005], n;
int rmq[100005][log+5];
int findpar(int u)
{
	return par[u] < 0 ? u : par[u] = findpar(par[u]);
}
void merge(int u, int v, int  val)
{
	u = findpar(u); v = findpar(v);
	if (u == v) return;
	if (par[u] > par[v]) swap(u, v);
	pre[lst[u]] = v; 
	giatri[lst[u]] = val;
	lst[u] = lst[v];
	par[u] += par[v];
	par[v] = u;
}
int getmin(int l, int r)
{
	int k = lg[r - l + 1];
	return min(rmq[l][k], rmq[r - mask(k) + 1][k]);
}
void solve() 
{
	vector<DATA> edge;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		par[i] = -1; lst[i] = i;
		int u, v, val;
		cin >> u >> v >> val;
		edge.pb({u, v, val});
	}
	par[n] = -1; lst[n] = n;
	sort(ALL(edge));
	for (auto v : edge)
	merge(v.ver1, v.ver2, v.va);	
	int cnt = 0;
	for (int i = findpar(1); i != 0; i = pre[i])
	{
		rmq[++cnt][0] = giatri[i];
		//cout << cnt << " " << rmq[cnt][0] << endl;
		cs[i] = cnt;
		lg[cnt] = lg[cnt-1];
		while(mask(lg[cnt]) <= cnt) lg[cnt]++; lg[cnt]--;
	}
	for (int i = 1; i <= log; i++) for (int j = 1; j < cnt - mask(i) + 1; j++)
	rmq[j][i] = min(rmq[j][i-1], rmq[j + mask(i-1)][i-1]);
	int q;
	cin >> q;
	while(q--)
	{
		int k;
		cin >> k;
		if (k == 1)
		{
			cin >> k;
			cout << "0\n";
			continue;
		}
		for (int i = 1; i <= k; i++) 
		{
			cin >> luu[i]; luu[i] = cs[luu[i]];
		}
		sort(luu + 1, luu + 1 + k);
		int res = 0;
		for (int i = 1; i < k; i++) res = max(res, getmin(luu[i], luu[i+1]-1));
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
   	//freopen("TDIAM.inp","r",stdin); freopen("TDIAM.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
