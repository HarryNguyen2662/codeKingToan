#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
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

const int maxn = 200005;

struct DATA
{
	int l, r, d;
	// DATA()
	// {
	// 	l = 0; r = 0; d = 0;
	// }

	bool operator < (const DATA &other) const
	{
		return d < other.d;
	}
};
DATA query[maxn];

class fenwicktree {
private:
    int len;
    vector<ll> fen;
 
public:
    void reset(int sz) {
    	fen.assign(sz + 3, 0);
        len = sz;
    }
 
    void update(int id, int val)
    {
    	for (; id <= len; id += (id&(-id))) fen[id] += val;
    }

	ll get(int id)
	{
		ll res = 0;
		for (; id; id -= (id&(-id))) res += fen[id];
		return res;
	}
};

int lg[maxn], a[maxn][log + 3], cs[maxn], b[maxn];

ll ans[maxn];

int gcd(int x, int y)
{
	if (y == 0) return x;

	return gcd(y, x%y);
}

int getgcd(int l, int r)
{
	int k = lg[r - l + 1];

	return gcd(a[l][k], a[r - mask(k) + 1][k]);
}

int ps(int st, int l, int r, int val)
{
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if (getgcd(st, mid) == val) l = mid + 1; else r = mid - 1; 
	}

	return l;
}

void solve() 
{
	int n, q;
	cin >> n >> q;
	vector<DATA> diff;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i][0];

		b[i] = oo;
		lg[i] = lg[i - 1];
		while(mask(lg[i]) <= i) lg[i]++; lg[i]--;
	}

	for (int i = 1; i <= log; i++) for (int j = 1; j <= n - mask(i) + 1; j++) 
		a[j][i] = gcd(a[j][i-1], a[j + mask(i - 1)][i - 1]);

		
	for (int i = 1; i <= n; i++)
	{
		int id = i;
		
		diff.pb({i, i, a[i][0]});
		int cur = a[i][0];

		while(id <= n)
		{
			id = ps(i, id, n, cur);
			if (id <= n) 
			{
				cur = getgcd(i, id);
				
				diff.pb({i ,id, cur});
			}
		}
	}

	sort(ALL(diff)); 

	// for (auto v : diff)
	// {
	// 	cout << v.l << " " << v.r << " " << v.d << endl;
	// }

	for (int i = 1; i <= q; i++)
	{
		cin >> query[i].l >> query[i].r >> query[i].d;
		cs[i] = i;
	}

	sort(cs + 1, cs + 1 + q, [](const int &x, const int &y)
		{
			return query[x].d < query[y].d;
		});

	int id = -1;

	fenwicktree ldk; ldk.reset(n);

	for (int i = 1; i <= q; i++)
	{
		int d = query[cs[i]].d, l = query[cs[i]].l, r = query[cs[i]].r;


		while(id + 1 < (int)diff.size() && diff[id + 1].d <= d)
		{
			id++;
			// cout << id << endl;
			
			if (b[diff[id].l] != oo)
			ldk.update(diff[id].l, -b[diff[id].l]);
			
			b[diff[id].l] = diff[id].r; 
			
			ldk.update(diff[id].l, b[diff[id].l]);	
		}

		int u = l, v = r;
		while( u <= v)
		{
			int uv = (u + v) >> 1;
			if (b[uv] <= r) u = uv + 1; else v = uv - 1;
		}

		ans[cs[i]] = 1ll*(v - l + 1)*(r + 1) - ldk.get(v) + ldk.get(l-1);
	}	

	for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
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
