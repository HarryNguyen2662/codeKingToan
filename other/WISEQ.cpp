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
 
    void update(int id, int val)
    {
    	for (; id <= len; id += (id&(-id))) fen[id] = max(fen[id], val);
    }

	int get(int id)
	{
		int res = 0;
		for (; id; id -= (id&(-id))) res = max(res, fen[id]);
		return res;
	}
};

int a[100005], dp[505][505];

void solve() 
{
	int n; ll s, sum = 0;
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	if (s >= sum)
	{
		int res = 0;
		fenwicktree ldk; ldk.reset(500005);
		for (int i = 1; i <= n; i++)
		{
			int re = ldk.get(a[i] - 1);

			res = max(res, re + 1);

			ldk.update(a[i], re + 1);
		}

		cout << res << "\n";
	}
	else
	{
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dp[i][j] = oo;

		for (int i = 1; i <= n; i++)
		{
			dp[i][1] = a[i];
			for (int j = 2; j <= i; j++)
			{
				for (int e = i - 1; e >= 1; e--)
				if (a[i] > a[e])
				{
						dp[i][j] = min(dp[i][j], dp[e][j-1] + a[i]);
				}
			}
		}


		for (int i = n; i; i--)
		{
			for (int j = 1; j <= n; j++)
			if (dp[j][i] <= s)
			{
				cout << i;
				return;
			}
		}
	}
}

int main() 
{   
   	freopen("WISEQ.inp","r",stdin); freopen("WISEQ.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
