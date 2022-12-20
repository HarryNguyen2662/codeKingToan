#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define fi first
#define se second
#define pb push_back
#define log 18
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
int par[300005], last[300005], suf[300005], add[300005], luu[300005], dist[300005][log+4], inid[300005], lg[300005];
int findpar(int u)
{
	return par[u] < 0 ? u : par[u] = findpar(par[u]);
}
void merge(int u, int v, int val)
{
	u = findpar(u); v = findpar(v);
	if (par[u] > par[v]) swap(u, v);
	suf[last[u]] = v;
	add[last[u]] = val;
	last[u] = last[v];
	par[u] += par[v];
	par[v] = u;
}
int getdist(int l, int r)
{
	int k = lg[r - l + 1];
	return  max(dist[l][k], dist[r - mask(k) + 1][k]);
}
void solve() 
{
	int n;
	cin >> n;
	for (int i = 1 ; i <= n; i++)
	{
		par[i] = -1;
		last[i] = i;
		suf[i] = -1;
		lg[i] = lg[i-1];
		while(mask(lg[i]) <= i) lg[i]++; lg[i]--;
	}
	for (int i = 1; i < n; i ++)
	{
		int u, v;
		cin >> u >> v;
		merge(u, v, i);
	}
	n = 0;
	for (int i = findpar(1); i != -1; i = suf[i])
	{
		dist[++n][0] = add[i];
		inid[i] = n;
	}
	for (int i = 1; i <= log; i++) for (int j = 1; j < n - mask(i) + 1; j ++)
	dist[j][i] = max(dist[j][i-1], dist[j + mask(i-1)][i-1]);
	//cout << getdist(2, 2) << endl;
	int q;
	cin >> q;
	while(q--)
	{
		int k;
		long long resres = 1;
		cin >> k;
		for (int i = 1; i <= k; i++) 
		{
			cin >>  luu[i];
			luu[i] = inid[luu[i]];
		}
		if (k == 1)
		{
			cout << n << "\n";
			continue;
		}
		sort(luu + 1, luu + 1 + k);
	//	for (int i = 1; i <= k; i++) cout << luu[i] << " ";
	//	cout << endl;
		for (int i = 1; i <= k; i++)
		{
			int res = oo;
			if (i < k )res = min(res, getdist(luu[i], luu[i+1] - 1));
			if (i > 1) res = min(res, getdist(luu[i-1] , luu[i] - 1));
			resres = (resres*1ll*res)%MOD1;
			//cout << res << endl;
		}
		cout << resres << "\n";
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
