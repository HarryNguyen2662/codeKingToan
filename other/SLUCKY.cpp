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
    vector<int> fen;
 
public:
    void reset(int sz) {
    	fen.assign(sz + 3, 0);
        len = sz;
    }
 
    void updup(int id, int val)
    {
    	for (; id <= len; id += (id&(-id))) fen[id] += val;
    }

	int getdown(int id)
	{
		int res = 0;
		for (; id; id -= (id&(-id))) res += fen[id];
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
char s[100005];
vector<pair<int,int>> luu[100005];
void solve() 
{
	vector<int> ldk, dk, ok;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		ldk.pb(i);
	}

	ll ans = 0;
	int dem = 0, mx = 0;

	while(true)
	{
		if ((int)ldk.size() >= 2)
		{
			int w = (int)ldk.size();
			if (s[ldk[w - 2]] == '6' && s[ldk[w - 1]] == '8')
			{
				int r = ldk.back(); ldk.pop_back(); 
				int l = ldk.back(); ldk.pop_back();
				dem++;
				mx = max(dem , mx);
				luu[dem].pb({l, r});

				if ((int)dk.size())
				{
					ldk.pb(dk.back()); dk.pop_back();
					dem = max(dem, ok.back()); ok.pop_back();
				}
				else
				{
					dem = 0;
				}
			}
			else
			{	
				ok.pb(dem);
				dem = 0;
				dk.pb(ldk.back()); 
				ldk.pop_back();
			}	
		}
		else break;
	}
	dem = mx;


	fenwicktree ledaiking;
	ledaiking.reset(n);
	for (int i = 1; i <= n; i++) ledaiking.updup(i, 1);


	for (int i = 1; i <= dem; i++)
	{
		for (auto v : luu[i])
		{
			ans += ledaiking.getdown(v.fi);
		}
		for (auto v : luu[i])
		{
			ledaiking.updup(v.fi, -1); ledaiking.updup(v.se, -1);
		}
	}

	cout << ans;

}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    // //
    // 
    freopen("SLUCKY.inp","r",stdin); freopen("SLUCKY.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
