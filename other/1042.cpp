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
long long power(long long x, long long y)
{
	if (y == 0) return 1;
	long long xx = power(x, y/2);
	if (y%2) return xx*xx%MOD1*x%MOD1; else return xx*xx%MOD1;
}
vector<pair<int,int>> a[200005];
long long dist[200005], ans[200005];
int f, luu, cost[2000][2000];
bool use[5005];
void dij(int u)
{
	priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;	
	for (int i = 1; i <= f; i++) dist[i] = oo15;
	dist[u] = 0;
	pq.push({0, u});
	while(!pq.empty())
	{
		u = pq.top().se; long long dai = pq.top().fi; pq.pop();
		if (dist[u] != dai) continue;
		for (auto v : a[u])
		if (dist[v.fi] > dist[u] + v.se)
		{
			//cout << v.fi << endl;
			dist[v.fi] = dist[u] + v.se;
			pq.push({dist[v.fi], v.fi});
		}
	}
}
void dijn2(int u)
{
	for (int i = 1; i <= f; i++) dist[i] = oo15, use[i] = false;
	dist[u] = 0;
	
	for (int i = 1; i <= f; i++)
	{
		int v = -1;
		for (int j = 1; j <= f; j++)
		if (!use[j] && ( v == -1 || dist[v] > dist[j]) ) v = j;

		if (dist[v] == oo15) break;
		use[v] = true;
		for (auto vv : a[v]) if (dist[vv.fi] > dist[v] + vv.se)
		{
			dist[vv.fi] = dist[v] + vv.se;
		}
	}
	for (int i = 1; i <= f; i++) if (dist[i] == oo15) dist[i] = MOD1-1;
}
void sub1(int z)
{

	for (int i = 1; i <= f; i++)
		for (int j = i + 1; j <= f; j++) if (cost[i][j])
		{
			
			a[i].pb({j, cost[i][j]}); a[j].pb({i, cost[i][j]});
		}
	for (int i = 1; i <= z; i++)
	{
		dijn2(i);
		//cout << i << endl;
		for (int j = 1; j <= f; j++)
		{
			ans[j] = (ans[j] + dist[j]%MOD1 * power(i, i)%MOD1)%MOD1;
			//cout << dist[j]  << " " << power(i, i) << endl;
		}
	}
	for (int i = 1; i <= f; i++) cout << ans[i] << " ";
}
void sub2(int z)
{
	for (int i = 1; i <= z; i++)
	{
		dij(i);
		//cout << dist[5] << endl;
		for (int j = 1; j <= f; j++)
		{
			ans[j] = (ans[j] + min(dist[j], 1ll*luu)%MOD1 * power(i, i)%MOD1)%MOD1;
		}
	}
	for (int i = 1; i <= f; i++) cout << ans[i] << " ";
}
void solve() 
{	
	int o, s; int kk;
	cin >> f >> o >> s;
	for (int i = 1; i <= o; i++)
	{
		if (f <= 1000)
		{
			int k, w;
			cin >> k;
			cin >> w;
			vector<int> ldk;
			for (int j = 1; j <= k; j++)
			{
				int x;
				cin >> x; ldk.pb(x);
				//cout << x << " ";
			}
			for (int j = 1; j < (int)ldk.size(); j++)
				for(int e = 0; e < j ;  e++) 
				if (ldk[j] != ldk[e])
				{
					if (cost[ldk[j]][ldk[e]] == 0) cost[ldk[j]][ldk[e]]  = w;
					else cost[ldk[j]][ldk[e]] = min(w, cost[ldk[j]][ldk[e]]);
					cost[ldk[e]][ldk[j]] = cost[ldk[j]][ldk[e]];
				}
		}
		else
		{	
			cin >> kk;
			cin >> luu;
			int x;
			for (int j = 1; j <= kk; j++)
			{
				cin >> x;
			}
		}
	}
	for (int i = 1; i <= s; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		//cout << x <<  " " << y << endl; 
		a[x].pb({y, w}); a[y].pb({x, w});
	}
	int z;
	cin >> z;
	//cout << o << " " << kk << endl;
	if (f <= 1000) sub1(z);
	else if (o == 1 && kk == f) sub2(z);
	else
	{
		for (int i = 1; i <= f; i++) cout << 0 << " ";
	}
}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
