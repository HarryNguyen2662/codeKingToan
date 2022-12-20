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

struct DATA
{
	int left, right, gt, cs;

	bool operator < (const DATA &other) const
	{
		return gt < other.gt;
	}
} b[200005];

int fen[100005], n, ans[200005];
pair<int,int> a[100005];

void update(int id, int val)
{
	for (; id <= n; id += (id&(-id))) fen[id] += val; 
}

int get(int id)
{
	int res = 0;
	for (; id; id -= (id&(-id))) res += fen[id];
	return res;
}

void solve() 
{	
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i].fi; a[i].se = i;
		update(i, 1);
	}
	

	sort(a + 1, a + 1 + n);

	for (int i = 1; i <= m; i++)
	{
		cin >> b[i].left >> b[i].right >> b[i].gt;
		b[i].cs = i;
	}

	sort(b + 1, b + 1 + m);

	int id = 1;

	for (int i = 1; i <= m; i++)
	{
		while(id <= n && b[i].gt >= a[id].fi)
		{
			update(a[id].se, -1); id++;
		}
		ans[b[i].cs] = get(b[i].right) - get(b[i].left - 1);
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << "\n";
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
