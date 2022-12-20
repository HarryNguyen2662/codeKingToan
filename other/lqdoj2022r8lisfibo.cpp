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
    	id++;
    	for (; id <= len; id += (id&(-id))) fen[id] = max(fen[id], val);
    }

	ll getdown(int id)
	{
		id++;
		ll res = 0;
		for (; id; id -= (id&(-id))) res = max(res, fen[id]);
		return res;
	}

	void upddown(int id, ll val)
    {
    	id++;
    	for (; id; id -= (id&(-id))) fen[id] = max(fen[id], val);
    }

	ll getup(int id)
	{
		id++;
		ll res = 0;
		for (; id <= len; id += (id&(-id))) res = max(res, fen[id]);
		return res;
	}
};

const int lim = 2000000;

int f[10000005];
ll ff[10000005], ff1[10000005], dem[1005];
int dd[1005][1005];

void solve() 
{
	ll n; int M;
	fenwicktree dk;
	
	cin >> n >> M;

	if (M == 1)
	{
		if (n == 1)
		{
			cout << "1";
			return;
		}
		cout << max(2ll, n - 2); return;
	}

	f[1] = f[2] = 1; dd[1][1] = 1;

	int cnt = 2;

	while(true)
	{
		cnt++;
		f[cnt] = (f[cnt - 1] + f[cnt - 2])%M;

		if (dd[f[cnt - 1]][f[cnt]]) break;

		dd[f[cnt - 1]][f[cnt]] = cnt - 1;
	}


	int len = cnt - 1 - dd[f[cnt-1]][f[cnt]];

	cnt -= 2;

	int nn = min(1ll*(cnt + len*(len - 1) + len*len + (n - cnt)%len), n);


	if (nn == n || n < cnt || n <= lim)
	{
		dk.reset(M);
		nn = n;
		for (int i = cnt + 1; i <= nn; i++) f[i] = f[i - len];
		int maxlen = 0;
		for (int i = 1; i <= nn; i++)
		{
			int val = dk.getdown(f[i]) +  1;
			maxlen = max(maxlen, val);
			dk.updup(f[i], val);
		}
		cout << maxlen; return;
	}

	dk.reset(M);

	for (int i = cnt - len + 1; i <= cnt; i++) dem[f[i]]++;

	for (int i = 1; i <= cnt + len*(len - 1); i++)
	{
		if (i > cnt) f[i] = f[i - len];
		ff[f[i]] = dk.getdown(f[i]) + 1;
		dk.updup(f[i], ff[f[i]]);
	}

	dk.reset(M);

	for (int i = len*len + (n - cnt)%len + (cnt - len); i >= (cnt - len) + 1; i--)
	{
		if (i > len*len + (cnt - len)) f[i] = f[i - len];
		ff1[f[i]] = dk.getup(f[i]) + 1;
		dk.upddown(f[i], ff1[f[i]]);	
	}

	for (int i = 1; i < M; i++)
	{
		ff[i] = max(ff[i], ff[i - 1]);
	}

	for (int i = M - 2; i >= 0; i--)
	{
		ff1[i] = max(ff1[i], ff1[i + 1]);
	}

	n = (n - (n - cnt)%len - len*len*2 - (cnt - len))/len;

	ll res = 0;

	for (int i = 0; i < M; i++)
	{
		res = max(res, ff[i] + ff1[i] + n*dem[i]);
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
    //freopen("LISFIBO.inp","r",stdin); freopen("LISFIBO.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
