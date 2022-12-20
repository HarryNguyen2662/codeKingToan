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

int pe[100005][log+2], high[100005], in[100005], out[100005], cnt = 0, fen[200005], re[100005];
vector<int> ed[100005];

void dfs(int u, int pee)
{
	high[u] = high[pee] + 1;
	in[u] = ++cnt;

	for (auto v : ed[u]) if (v != pee) 
	{
		dfs(v, u);
	}	

	out[u] = ++cnt;
}

int findlce(int u, int v)
{
	if (high[u] < high[v]) swap(u, v);

	for (int i = log; i >=0; i--) if (high[pe[u][i]] >= high[v]) u = pe[u][i];

	if (u == v) return u;

	for (int i = log; i >= 0; i--) if (pe[u][i] != pe[v][i])
	{
		u = pe[u][i]; v = pe[v][i];
	}

	return pe[u][0];
}

void update(int id, int vel)
{
	for (; id <= cnt; id += (id&(-id))) 
	{
		fen[id] += vel;
		fen[id] %= MOD;
	}
}

long long get(int id)
{
	long long  res = 0;

	for (; id; id -= (id&(-id))) 
	{
		res += fen[id];
		res %= MOD;
	}

	return res;
}

void solve() 
{
	int n;
	int root;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x == 0) root = i; else 
		{
			pe[i][0] = x; 
			ed[x].pb(i);
		}
	}

	dfs(root, 0); //for (int i = 1; i <= log; i++) for (int j = 1; j <= n; j++) pe[j][i] = pe[pe[j][i-1]][i-1];



	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		int vel = (get(out[x]) - get(in[x] - 1) + 1 + MOD)%MOD;
		if (pe[x][0]) update(in[pe[x][0]], vel);q
		
		re[x] = vel;
	}

	for (int i = 1; i <= n; i++) cout << re[i] << " ";
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
