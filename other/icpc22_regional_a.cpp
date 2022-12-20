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

int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};

bool de[425];
ll id[25][25], vit[425], dp[mask(20) + 3], sl[25], dem[25], dk[25];
vector<int> edge[425], bit1[25];
int cnt = 0;

void dfs(int u)
{
	vit[u] = cnt;

	for (auto v : edge[u]) if (vit[v] == 0) dfs(v);
}

void solve() 
{
	int n, m;
	cin >> n >> m;
	string s;
	getline(cin, s);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			id[i][j] = (i - 1)*m + j;
		}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			for (int e = 0; e < 4; e++)
			{
				int ni = i + x[e], nj = j + y[e];
				if (ni >= 1 && ni <= n && nj >= 1 && nj <= m)
				{
					edge[id[i][j]].pb(id[ni][nj]);
				}
			}
		}

	auto erase = [&](int id1, int id2) -> void
	{
		if (id1 == 0 || id2 == 0) return;
		
		for (int i = 0; i < (int)edge[id1].size(); i++)
		if (edge[id1][i] == id2)
		{
			swap(edge[id1][i], edge[id1].back());
			edge[id1].pop_back();
			break;
		} 

		for (int i = 0; i < (int)edge[id2].size(); i++)
		if (edge[id2][i] == id1)
		{
			swap(edge[id2][i], edge[id2].back());
			edge[id2].pop_back();
			break;
		} 
	};

	for (int i = 0; i <= n; i++)
	{
		getline(cin, s);
			
		if (i == 0) continue;

		for (int j = 1; j <= m; j++)
		{
			if (s[2*j] == '|') erase(id[i][j], id[i][j + 1]);
			if (s[2*j - 1] == '_') erase(id[i][j], id[i + 1][j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> sl[i];
	}


	

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) 
	if (vit[id[i][j]] == 0) 
	{
		++cnt;
		dfs(id[i][j]);
	}

	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= m; j ++)
	// 	{
	// 		cout << vit[id[i][j]] << " ";
	// 	}
	// 	cout << "\n";
	// }

	for (int i = 0; i < cnt; i++) for (int j = 0; j < mask(cnt); j++) if (ck(j, i)) bit1[i].pb(j);

	for (int i = n; i; i--)
	{
		int status = 0;
		for (int j = 1; j <= m; j++) if (de[vit[id[i][j]]] == false)
		{
			status += mask(vit[id[i][j]] - 1);
			de[vit[id[i][j]]] = true;
		}
		dk[i] = status;
	}

	dp[0] = 1; 


	for (int i = n; i >= 1; i--) 
	{
		for (int j = cnt - 1; j >= 0; j--) for (auto e : bit1[j])
		{
			dp[e^mask(j)] += dp[e]; if (dp[e^mask(j)] >= MOD) dp[e^mask(j)] -= MOD;
		}

		int he = 0;
		
		for (int j = 1; j <= cnt; j++) 
		{
			de[j] = false;
			dem[j] = 0;
		}
		for (int j = 1; j <= m; j++) 
		{
			if (!de[vit[id[i][j]]])
			{
				he += mask(vit[id[i][j]] - 1);
				de[vit[id[i][j]]] = true;
			}
			dem[vit[id[i][j]]]++;
		}

		vector<pair<int,int>> ldk;


		for (int j = 0; j < mask(cnt); j++)
		if (dp[j])
		{
			if ((j|he) == he)
			{
				int sll = 0;
				for (int e = 0; e < cnt; e++) if (ck(j, e)) 
				{
					sll += dem[e + 1];
				}
				// cout << "hmm " << j << " " << he << endl;
				ldk.pb({j, sll});
			}
			else dp[j] = 0;
		}

		// if (i == 4) 
		// {
		// 	cout << "du " << ldk[0].fi << " " << ldk[1].se << endl;
		// }

		for (int j = dk[i]; j; j = (j - 1)&dk[i])
		{

			int sll = 0;
			for (int e = 0; e < cnt; e++) if (ck(j, e)) 
			{
				sll += dem[e + 1];
			}
			
			for (auto v : ldk)
			if (sl[i] == -1 || v.se + sll == sl[i])
			{
				// cout << "hi " <<  i << " " << j << " " << v.fi << endl;
				dp[j^v.fi] += dp[v.fi]; if (dp[j^v.fi] >= MOD) dp[j^v.fi] -= MOD;
			}
		}

		// cout << "De " << he << endl;

		for (auto v : ldk)
		if (sl[i] != -1 && v.se != sl[i])
		{
			// cout << i << " " << v.fi << endl;
			dp[v.fi] = 0;
		}

		// for (int j = 0; j < mask(cnt); j++)
		// if (dp[j])
		// {
		// 	int sll = 0;
		// 	for (int e = 0; e < cnt; e++) if (ck(j, e)) 
		// 	{
		// 		sll += dem[e + 1];
		// 	}
			
		// 	cout << i << " " << j << " " << sll << " " << dp[j] << endl;
		// }

	}

	// cout << dk[1] << endl;

	ll ans = 0;

	for (int i = 0; i < mask(cnt); i++)
	{
		ans += dp[i];
		if (ans >= MOD) ans -= MOD;
	}

	cout << ans;	
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
