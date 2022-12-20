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
int n, m;	
bool ck[4194310], vit[4194310][2];	

void dfs(int u, int ti)
{

	vit[u][ti] = true;

	if (ti == 1)
	{
		int uu = mask(n) - 1 - u;
		if (ck[uu] && vit[uu][0] == false) dfs(uu, 0);

		for (int i = 0; i < n; i++)
		if (!ck(u, i) && vit[u|mask(i)][1] == false) dfs(u|mask(i), 1); 
	}
	else
	{
		if (vit[u][1] == false) dfs(u, 1);
	}

}

void solve() 
{
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int val;
		cin >> val; ck[val] = true;
	}

	int res = 0;
	for (int i = 0; i < mask(n); i++) if (ck[i] && vit[i][0] == false)
	{
		res++; dfs(i, 0);
	}

	cout << res;
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
