#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
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

int dist[2300][2300];
char s[2300][2300];
set<int> row[2300], col[2300];

// bool check(int x, int y, int u, int v)
// {
// 	if (x > u) swap(x, u); if (y > v) swap(y, v);
	
// 	return (s[u][v] - s[x-1][v] - s[u][y-1] + s[x-1][y- 1] == 0);
// }

void solve() 
{
	int n, m, k;
	
	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> s[i][j];
			// s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + (x == '#');
		}
	}

	for (int i = 1; i <= m; i++) row[1].insert(i);
	for (int i = 1; i <= n; i++)
	{
		col[1].insert(i);
		row[i] = row[1];
	}
	
	for (int i = 2; i <= m; i++)
	{
		col[i] = col[1];
	}
	
	pair<int,int> st, ed;
	
	cin >> st.fi >> st.se >> ed.fi >> ed.se;
	if (st == ed)
	{
		cout << "0\n";
		return;
	} 

	queue<pair<int,int>> que;
	que.push(st);
	row[st.fi].erase(st.se); 
	col[st.se].erase(st.fi);

	while(!que.empty())
	{
		int x = que.front().fi, y = que.front().se; que.pop();
		vector<pair<int,int>> ok;


		auto id = row[x].lower_bound(y);
		auto id1 = id;
		while(id != row[x].end())
		{
			if (*id > y + k) break;
			if (s[x][*id] == '.')
			{
				ok.pb({x, *id});
			}
			else break;
			id++;
		}
		while(id1 != row[x].begin())
		{
			id1--;
			if (*id1 < y - k) break;
			if (s[x][*id1] == '.')
			{
				ok.pb({x, *id1});
			}
			else break;
		}

		id = col[y].lower_bound(x);
		id1 = id;
		while(id != col[y].end())
		{
			if (*id > x + k) break;
			if (s[*id][y] == '.')
			{
				ok.pb({*id, y});
			}
			else break;
			id++;
		}
		while(id1 != col[y].begin())
		{
			id1--;
			if (*id1 < x - k) break;
			if (s[*id1][y] == '.')
			{
				ok.pb({*id1, y});
			}
			else break;
		}

		for (auto v : ok)
		{
			dist[v.fi][v.se] = dist[x][y] + 1;
			row[v.fi].erase(v.se);
			col[v.se].erase(v.fi);
			que.push(v);
		}
	}

	if (dist[ed.fi][ed.se] == 0) cout << "-1"; else cout << dist[ed.fi][ed.se];
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("flash.inp","r",stdin); freopen("flash.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
