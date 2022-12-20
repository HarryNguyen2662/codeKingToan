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

class fenwicktree {
private:
    int len;
    vector<ll> fen;
 
public:
    void reset(int sz) {
    	fen.assign(sz + 3, 0);
        len = sz;
    }
 
    void updup(int id, ll val)
    {
    	for (; id <= len; id += (id&(-id))) 
    	{
    		fen[id] += val;
    		fen[id] %= MOD;
    	}
    }

	ll getdown(int id)
	{
		ll res = 0;
		for (; id; id -= (id&(-id))) 
		{
			res += fen[id];
			res %= MOD;
		}
		return res;
	}

	void upddown(int id, int val)
    {
    	for (; id; id -= (id&(-id))) fen[id] += val;
    }

	int getup(int id)
	{
		int res = 0;
		for (; id <= len; id += (id&(-id))) res += fen[id];
		return res;
	}
};

int a[500005], b[500005];
ll luu[500005];

void solve() 
{
	fenwicktree dk;
	vector<int> ldk;
	int n, m;
	cin >> n >> m;

	dk.reset(n);

	if (m > n)
	{
		cout << "-1";
	}


	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> b[i];
	}

	int cnt = 1;

	for (int i = 1; i <= n; i++)
	if (cnt <= m && a[i] == b[cnt])
	{
		ldk.pb(i);
		cnt++;
	}

	// for (auto v : ldk) cout << v << endl;

	if (cnt <= m)
	{
		cout << "-1";
		return;
	}

	ll ans = 0;

	cnt = m - 1;

	for (int i = n; i; i--)
	{
		if (cnt >= 0 && i == ldk[cnt])
		{
			ans++;
			if (cnt + 1 < m)
			{
				// cout << b[cnt + 2] << " " <<  dk.getdown(b[cnt + 2] - 1) << endl;
				ans += dk.getdown(b[cnt + 2] - 1);
				ans %= MOD;
			}
			cnt--;
		}

		// cout << "Du " << a[i] << " " << luu[a[i]] << " "  << pw[n - i] << endl;

		ll val = (dk.getdown(n) + 1)%MOD;
		dk.updup(a[i], -luu[a[i]]); luu[a[i]] = val; dk.updup(a[i], luu[a[i]]);
	}

	// cout << dk.getdown(b[1] - 1) << endl;

	ans += dk.getdown(b[1] - 1); ans %= MOD; ans += MOD; ans %= MOD;

	cout << ans;
}


int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("SETSEQ.inp","r",stdin); freopen("SETSEQ.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
