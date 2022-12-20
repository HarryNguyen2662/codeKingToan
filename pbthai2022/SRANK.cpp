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

class fenwicktree {
private:
    int len;
    vector<int> fen;
 
public:
    void reset(int sz) {
    	fen.assign(sz + 3, 0);
        len = sz;
    }
 
    void update(int id, int val)
    {
    	for (; id <= len; id += (id&(-id))) fen[id] += val;
    }

	int get(int id)
	{
		int res = 0;
		for (; id; id -= (id&(-id))) res += fen[id];
		return res;
	}

	void update1(int id, int val)
    {
    	for (; id; id -= (id&(-id))) fen[id] += val;
    }

	int get1(int id)
	{
		int res = 0;
		for (; id <= len; id += (id&(-id))) res += fen[id];
		return res;
	}
};

long long a[100005], aa[100005];
pair<int, long long> qe[100005];

void solve() 
{
	vector<int> diff;
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		aa[i] = a[i];
		diff.pb(a[i]);
	}

	for (int i = 1; i <= q; i++)
	{
		cin >> qe[i].fi >> qe[i].se;
		aa[qe[i].fi] += qe[i].se;
		diff.pb(aa[qe[i].fi]);
	}

	sort(ALL(diff)); diff.resize(unique(ALL(diff)) - diff.begin());

	fenwicktree ldk, dk;
	ldk.reset((int)diff.size()); dk.reset((int)diff.size());

	long long res = 0;

	for (int i = 1; i <= n; i++)
	{
		int id = lower_bound(ALL(diff), a[i]) - diff.begin() + 1;
		ldk.update(id, 1);
		dk.update1(id, 1);
	}

	for (int i = 1; i <= n; i++)
	{
		int id = lower_bound(ALL(diff), a[i]) - diff.begin() + 1;
		res += n - 1 - ldk.get(id - 1);
	}

	for (int i = 1; i <= q; i++)
	{
		int e = qe[i].fi; long long val = qe[i].se;
		
		int id = lower_bound(ALL(diff), a[e]) - diff.begin() + 1;
		
		ldk.update(id, -1); dk.update1(id, - 1);
		res -= (n - 1 - ldk.get(id - 1));
		res += dk.get1(id + 1);

		a[e] += val;
		
		id = lower_bound(ALL(diff), a[e]) - diff.begin() + 1;
	
		ldk.update(id, 1); dk.update1(id, 1);
		res += (n - 1 - ldk.get(id - 1));
		res -= dk.get1(id + 1);
		

		cout << res << "\n";
	}
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
