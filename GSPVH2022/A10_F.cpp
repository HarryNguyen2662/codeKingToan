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

pair<long long, int> sg[400005];
long long lazy[400005];
int lg[100005], k[100005][log + 3], sum[400006];
bool laz[400005];
int luu[100005];

void build(int id, int l, int r)
{
	if (l > r) return;
	if (l == r)
	{
		sg[id].se = -l;
		return;
	}

	int mid = (l + r)/2;

	build(id*2, l, mid); build(id*2+1, mid + 1, r);

	sg[id] = max(sg[id*2], sg[id*2 + 1]);
}

void dolazy(int id)
{
	if (sg[id].fi == -1) 
	{
		for (int i = id*2; i <= id*2 +1; i++)
		{
			sg[i].fi = -1;
			lazy[i] = -1;
		}
		return;
	}


	for (int i = id*2; i <= id*2 +1; i++)
	if (sg[i].fi != -1)
	{
		sg[i].fi += lazy[id];
		lazy[i] += lazy[id];
	}

	lazy[id] = 0;
}

void upd(int id, int l, int r, int u, int v, int val)
{
	if (l > v || r < u) return;

	if (u <= l && r <= v)
	{
		if (val == -1)
		{
			sg[id].fi = -1;
			lazy[id] = -1;
			return;
		}
		sg[id].fi += val;
		lazy[id] += val;
		return;
	}

	dolazy(id);

	int mid = (l + r)/2;

	upd(id*2, l, mid, u, v, val); upd(id*2 + 1, mid + 1, r, u, v, val);

	sg[id] = max(sg[id*2], sg[id*2+1]);
}


void build1(int id, int l, int r)
{
	if (l > r) return;
	if (l == r)
	{
		sum[id] = 1;
		return;
	}

	int mid = (l + r)/2;

	build1(id*2, l, mid); build1(id*2+1, mid + 1, r);	

	sum[id] = sum[id*2] + sum[id*2+1];
}

int dolaz(int id)
{
	if (laz[id])
	{
		for (int i = id*2; i <= id*2+1; i++)
		{
			sum[i] = 0; laz[i] = true;
		}
	}
}

void update(int id, int l, int r, int u, int v)
{
	if (l > v || r < u) return;

	if (u <= l && r <= v)
	{
		sum[id] = 0; laz[id] = true;
		return;
	}

	int mid = (l + r)/2;

	dolaz(id); update(id*2, l, mid, u, v); update(id*2+1, mid + 1, r, u, v);

	sum[id] = sum[id*2] + sum[id*2 + 1];

}

int find(int id, int l, int r, int k)
{
	if (l == r)
	{
		return l;
	}

	dolaz(id); int mid = (l + r)/2;

	if (k <= sum[id*2]) return find(id*2, l, mid, k); else return find(id*2+1, mid + 1, r, k - sum[id*2]);
}


void solve() 
{
	int n, rr, c;
	cin >> n >> c >> rr;

	for (int i = 1; i < n; i++) 
	{
		luu[i] = i;
		cin >> k[i][0];
		lg[i] = lg[i-1];
		while(mask(lg[i]) <= i) lg[i]++; lg[i]--;
	}

	luu[n] = n;
	build(1, 1, n); build1(1, 1, n);

	int cnt = n;


	for (int i = 1; i <= log; i++) for (int j = 1; j <= n - 1 - mask(i) + 1; j ++)
	k[j][i] = max(k[j][i-1], k[j + mask(i - 1)][i-1]);

	auto getmax = [&](const int &u, const int &v)
	{
		int le = lg[v - u + 1];

		return max(k[u][le], k[v - mask(le) + 1][le]);
	};


	long long res = 0; int kq = 1;
	for (int i = 1; i <= c; i++)
	{
		int l, r;

		cin >> l >> r; 

		l = find(1, 1, n, l); r = luu[find(1, 1, n, r)];
		luu[l] = r; 

		update(1, 1, n, l + 1, r);

		int mx = getmax(l, r - 1); 


		if (mx < rr)
		{
			upd(1, 1, n, l, r, 1);
		}
		else
		{
			upd(1, 1, n, l, r, -1);
		}

		if (res < sg[1].fi)
		{
			res = sg[1].fi; kq = -sg[1].se;
		}
		else if (res == sg[1].fi) kq = min(kq, -sg[1].se);
	}


	cout << kq;
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("tournament.inp","r",stdin); freopen("tournament.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
