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

int a[2000005];

void solve() 
{
	int n;
	cin >> n;
	int id = 0;
	vector<int> diff;

	fenwicktree fen, fen1; fen.reset(n); fen1.reset(n);

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		diff.pb(i);
		fen.update(i, 1); fen1.update1(i, 1);
	}

	auto cmp = [&](const int &x, const int &y)
	{
		return a[x] < a[y];
	};	

	sort(ALL(diff), cmp);

	vector<int> ldk, dk;

	long long res = 0;

	for (auto v : diff)
	{
		int cur = fen.get(v), cur1 = fen1.get1(v);
			
		res += min(cur, cur1) - 1;	

		if (cur <= cur1)
		{
			ldk.pb(v);
		}
		else
		{
			dk.pb(v);
		}
		fen.update(v, -1);
		fen1.update1(v, -1);
	}

	cout << res << "\n";
	for (auto v : ldk) cout << a[v] << " "; reverse(ALL(dk)); for (auto v : dk) cout << a[v] << " ";

}	

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("updown.inp","r",stdin); freopen("updown.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
