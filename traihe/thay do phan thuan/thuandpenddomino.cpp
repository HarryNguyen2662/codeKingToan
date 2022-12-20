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

int a[3000005], ans[3000005], sg[12000005];
long long d[3000005];

void update(int id, int l, int r, int vt)
{
	if (r < vt || l > vt)
	{
		return;
	}
	if (l == r)
	{
		sg[id] = ans[l];
		return;
	}
	int mid = (l + r)/2;
	update(id*2, l, mid, vt); update(id*2+1, mid + 1, r, vt);
	sg[id] = max(sg[id*2], sg[id*2+1]);
}

int getmax(int id, int l, int r, int u, int v)
{
	if (r < u || l > v) return 0;
	if (u <= l && r <= v)
	{
		return sg[id];
	}
	int mid = (l + r)/2;
	return max(getmax(id*2, l, mid, u, v), getmax(id*2+1, mid + 1, r, u, v));
}

void solve() 
{
	int n;
	cin >> n;
	if (n == 0) return;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < n; i++)
	{
		cin >> d[i];
		d[i] += d[i-1];
	}
	ans[n] = n;
	update(1, 1, n, n);
	//cout << ans[n] << endl;
	for (int i = n - 1; i; i--)
	{
		ans[i] = i;
		int l = i, r = n - 1;
		while(l <= r)
		{
			int mid = (l + r)/2;
			if (d[mid] - d[i-1] < a[i]) l = mid + 1; else r = mid - 1;
		}
		//cout << r << endl;
		if (r + 1 > i)
		ans[i] = getmax(1, 1, n, i + 1, r + 1);
		update(1, 1, n, i); 
		//if (r + 1 > i) ans[i] = max(ans[i], ans[i+1]);
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
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
