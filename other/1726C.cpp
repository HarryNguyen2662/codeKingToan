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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int par[200005], su[200005][log + 5], dd[1000005], lg[200005];
char s[200005];
bool ok[200005];
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

int getmin(int l, int r)
{
	int k = lg[r - l + 1];
	return min(su[l][k], su[r - mask(k) + 1][k]);
}
 
void solve() 
{
	int n;
	cin >> n;
	int lim = 2*n;
	for (int i = 1; i <= 2*n; i++) 
	{
		cin >> s[i];
		su[i][0] = su[i-1][0];
		if (s[i] == ')') su[i][0]--; else su[i][0]++;
		par[i] = -1;
		ok[i] = false;
		dd[su[i][0] + lim] = 0;
	}
	dd[lim] = 0;

	for (int i = 1; i <= log; i++) for (int j = 1; j <= 2*n - mask(i) + 1; j++)
	su[j][i] = min(su[j][i-1], su[j + mask(i - 1)][i-1]);
	

	for (int i = 1; i <= 2*n; i++)
	if (s[i] == ')' && dd[su[i][0] + lim] > 0)
	{
		int j = dd[su[i][0] + lim];
		if (getmin(j, i) >= su[i][0])
		{
			merge(i, j);
			if (ok[j-1])
			{
				merge(i, j -1);
			}
			ok[i] = true;
		}
	} else if (s[i] == '(')
	{
		dd[su[i-1][0] + lim] = i;
	}

	int res = 0;
	for (int i = 1; i <= 2*n; i++) if (par[i] < 0) res++;
	cout << res << "\n";
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
    for (int i = 1; i <= 200000; i++)
    {
    	while(mask(lg[i]) <= i) lg[i]++; lg[i]--;
    }
    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
