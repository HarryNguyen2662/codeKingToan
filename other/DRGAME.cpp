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

vector<int> adj[1005], ldk, ree[10005], luu;
int cango[1005][1005];
bool cut[1005][1005];;
int de[1005];
bool vit[1005];
int dem = 0;
void findpath(int u)
{
	int dmm = u;
	ldk.clear();
	stack<int> st;
	while(!st.empty() || de[u])
	{
		//cout << u << endl;
		if (de[u] == 0)
		{
			ldk.pb(u);
			u = st.top();
			st.pop();
				//cout << "ua132 " << u << endl;
		}
		else
		{
			//bool kt = true;
			for (auto v : adj[u])
			if (cango[u][v])
			{
			//	kt = false;
				st.push(u);
				de[u]--;
				de[v]--;
				cango[u][v]--; cango[v][u]--;
				u = v;
				//cout << "ua " << u << endl;
				break;
			}
			// if (kt)
			// {
			// 	for (auto v : adj[u])
			// 	if (cango[u][v])
			// 	{
			// 		st.push(u);
			// 		de[u]--;
			// 		de[v]--;
			// 		cango[u][v]--; cango[v][u]--;
			// 		u = v;
			// 		break;
			// 	}
			// }
		}
	}
	ldk.pb(dmm);
	
}
void dfs(int u)
{
	vit[u] = true;
	if (de[u]%2) luu.pb(u);
	for (auto v : adj[u]) if (vit[v] == false) dfs(v);
}


void solve() 
{
	int n, m;
	int kq = 0;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		de[u]++; de[v]++;
		cango[u][v] = cango[v][u] = 1;
		adj[u].pb(v); adj[v].pb(u);
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
	if (vit[i] == false)
	{
		luu.clear();
		dfs(i);
		res += ((int)luu.size() == 0 ? 1 :(int)luu.size()/2);
		if ((int)luu.size() == 0)
		{
			findpath(i);
			kq++;
			ree[kq] = ldk;
		}
		else if ((int)luu.size() == 2)
		{
			findpath(luu[0]);
			kq++;
 			//ldk.pb(luu[0]);
			ree[kq] = ldk;
 		}
 		else
 		{
 			//cout << luu[0] << luu[1] << endl;
 			for (int j = 2; j + 1 < (int)luu.size(); j+= 2)
 			{
 				//cout << luu[j] << " " << luu[j + 1] << endl;
 				de[luu[j]]++; de[luu[j+1]]++;
 				adj[luu[j]].pb(luu[j+1]); adj[luu[j+1]].pb(luu[j]);
 				cango[luu[j]][luu[j+1]]++; cango[luu[j+1]][luu[j]]++;
 				cut[luu[j]][luu[j+1]] = cut[luu[j+1]][luu[j]] = 1;
 			}
 			//cout << de[4] << endl;
 			//cout << de[1] << endl;
 			//for (auto v : adj[3]) cout << v << endl;
 			findpath(luu[0]);
 			kq++;
 			for (int j = 0; j < (int)ldk.size(); j++)
 			{
 				//cout << ldk[i] << endl;
 				if (j > 0 && cut[ldk[j]][ldk[j-1]])
 				{
 					cut[ldk[j]][ldk[j-1]] = cut[ldk[j-1]][ldk[j]] = 0;
 					kq++;
 				}
 				ree[kq].pb(ldk[j]);
 			}
 		}
	}
	cout << res << "\n";
	for (int i = 1; i <= kq; i++) if ((int)ree[i].size() > 1)
	{
		cout << (int)ree[i].size() << " ";
		for (auto v : ree[i]) cout << v << " ";
		cout << "\n";
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
