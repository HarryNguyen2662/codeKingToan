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

int lazy[400005], sg[400005], a[100005], dem[100005];
vector<int> ldk[100005];

void build(int id, int l, int r)
{
	sg[id] = 0; lazy[id] = 0;
	if (l == r)
	{
		return;
	}
	int mid = (l + r) >> 1;
	build(id*2, l, mid); build(id*2 + 1, mid + 1, r);
}

void dolazy(int id)
{
	for (int i = id*2; i <= id*2 + 1; i++)
	{
		sg[i] += lazy[id]; lazy[i] += lazy[id];
	}

	lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val)
{
	if (l > v || r < u) return;
	if (u <= l && r <= v)
	{
		sg[id] += val;
		lazy[id] += val;
		return;
	}

	int mid = (l + r) >> 1;
	dolazy(id);

	update(id * 2, l, mid, u, v, val); update(id*2 + 1, mid + 1, r, u, v, val);
	sg[id] = max(sg[id*2], sg[id*2 + 1]);
}


void solve() 
{
	int n, k;
	cin >> n >> k;
	k++;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	int res = 0;
	build(1, 1, n);
	
	for (int i = 1; i <= n; i++)
	{
		update(1, 1, n, 1, i, 1);
		ldk[a[i]].pb(i);
		
		if ((int)ldk[a[i]].size() >= k)
		{
			int id = (int)ldk[a[i]].size() - k;
			if (id == 0) update(1, 1, n, 1, ldk[a[i]][id], -k);
			else 
			{
				update(1, 1, n, ldk[a[i]][id-1] + 1, ldk[a[i]][id], -k);
				update(1, 1, n, 1, ldk[a[i]][id-1] + 1, -1);
			}
		}

		res = max(res, sg[1]);
	}

	for (int i = 1; i <= n; i++)
	{
		ldk[a[i]].clear();
	}

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
    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
