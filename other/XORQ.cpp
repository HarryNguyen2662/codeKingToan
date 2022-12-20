#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
#define fi first
#define se second
#define pb push_back
#define log 20
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

int sg[400005][log + 4], lazy[400005][log + 4];

void dolazy(int id, int l, int mid, int r)
{
	for (int i = 0; i <= log; i++)
	if (lazy[id][i])
	{
		lazy[id*2][i] ^= 1;
		lazy[id*2+1][i] ^= 1;
		
		sg[id*2][i] = mid - l + 1 - sg[id*2][i];
		sg[id*2 + 1][i] = r - mid - sg[id*2 + 1][i];
		
		lazy[id][i] = 0;
	}
}

void update(int id, int l, int r, int u, int v, int val)
{
	if (l > v || r < u) return;

	if (u <= l && r <= v)
	{
		for (int i = 0; i <= log; i++) if (ck(val, i))
		{
			sg[id][i] = r - l + 1 - sg[id][i];
			lazy[id][i] = 1 - lazy[id][i]; 
		}
		return;
	}

	int mid = (l + r) >> 1;
	dolazy(id, l, mid, r);

	update(id*2, l, mid, u, v, val); update(id*2+1, mid + 1, r, u, v, val);

	for (int i = 0; i <= log; i++) sg[id][i] = sg[id*2][i] + sg[id*2+1][i];
}

ll getsum(int id, int l, int r, int u, int v)
{
	if (l > v || r < u) return 0;


	if (u <= l && r <= v)
	{
		ll ans = 0;

		for (int i = 0; i <= log; i++)
		{
			ans += 1ll*sg[id][i]*mask(i);
		}

		return ans;
	}

	int mid = (l + r) >> 1; dolazy(id, l, mid, r);

	return getsum(id*2, l, mid, u, v) + getsum(id*2+1, mid + 1, r, u, v);
}

void solve() 
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int val;
		cin >> val;
		update(1, 1, n, i, i, val);
	}

	int m;
	cin >> m;
	while(m--)
	{
		int type, l, r;
		cin >> type >> l >> r;

		if (type == 1)
		{
			cout << getsum(1, 1, n, l, r) << "\n";
		}
		else
		{
			int val;
			cin >> val;
			update(1, 1, n, l, r, val);

		}
	}
}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    // //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
