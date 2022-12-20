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

int n, a[2005], b[2005], de[2005], k;
bool vis[2005][2005];

void dfs(int l, int r)
{
	vis[l][r] = true;

	//cout << l << " " << r << endl;

	if (r - l + 1 == n)
		return;


	if (l > 1 && vis[l-1][r] == false)
	{
		if (r - l + 1 + k + 1 <= n && a[r - l + 1 + k + 1] == b[l - 1]) dfs(l - 1, r);
		else
		if (de[b[l - 1]])
		{
			de[b[l - 1]]--; 

			if (r - l + 2 + k <= n)
			de[a[r - l + 2 + k]]++;

			dfs(l - 1, r);

			de[b[l - 1]]++; 

			if (r - l + 2 + k <= n)
			de[a[r - l + 2 + k]]--;
		}
	}

	if (r < 2*n && vis[l][r + 1] == false)
	{
		if (r - l + 1 + k + 1 <= n && a[r - l + 1 + k + 1] == b[r + 1]) dfs(l, r + 1);
		else
		if (de[b[r + 1]])
		{
			de[b[r + 1]]--; 

			if (r - l + 2 + k <= n)
			de[a[r - l + 2 + k]]++;

			dfs(l, r + 1);

			de[b[r + 1]]++; 

			if (r - l + 2 + k <= n)
			de[a[r - l + 2 + k]]--;
		}
	}
}

bool check(int lim)
{
	k = lim;

	for (int i = 1; i <= 2*n; i++) for (int j = i; j <= 2*n; j++) vis[i][j] = false;

	for (int i = 1; i <= min(n, lim); i++)
	{
		de[a[i]]++;
	}

	for (int i = 1; i <= 2*n; i++) 
	if (vis[i][i] == false)
	{
		if (k + 1 <= n && a[k + 1] == b[i])
		{
			dfs(i, i);
		}
		else if (de[b[i]])
		{
			de[b[i]]--; 

			if (1 + k <= n)
			de[a[k + 1]]++;

			dfs(i, i);

			de[b[i]]++; 

			if (1 + k <= n)
			de[a[1 + k]]--;
		}
	}

	for (int i = 1; i <= min(n, lim); i++)
	{
		de[a[i]]--;
	}

	for (int i = 1; i <= n; i++) if (vis[i][i + n - 1])
	{
		 return true;
	}

	return false;
}

void solve() 
{
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int j = 1; j <= n; j++) cin >> b[j];
	for (int i = n + 1; i <= 2*n; i++) b[i] = b[i - n];

	int l = 0, r = n;

	while(l <= r)
	{
		int mid = (l + r)/2;


		if (check(mid)) r = mid - 1; else l = mid + 1;
	}
	cout << l;

	
//	cout << check(2);

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
