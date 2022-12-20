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

ll a[500005];
vector<pair<int, int>> que[500005];
int l[500005], r[500005];

void solve() 
{
	stack<int> st;
	vector<ll> diff;

	int n; ll k;
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		
		while(!st.empty() &&  a[st.top()] > a[i]) st.pop();
		
		if (!st.empty()) l[i] = st.top() + 1; else l[i] = 1;
		
		st.push(i);
		
		diff.pb(a[i]);
	}

	sort(ALL(diff)); diff.resize(unique(ALL(diff)) - diff.begin());
	
	while(!st.empty()) st.pop();

	for (int i = n; i; i--)
	{
		while(!st.empty() &&  a[st.top()] >= a[i]) st.pop();
		
		if (!st.empty()) r[i] = st.top() - 1; else r[i] = n;
		
		st.push(i);
	}

	ll res = 0;

	fenwicktree ldk;
	ldk.reset((int)diff.size());

	for (int i = 1; i <= n; i++)
	{
		// cout << l[i] << " " << i << " " << r[i] << endl;
		if (i - l[i] > r[i] - i)
		{
			for (int j = i; j <= r[i]; j++)
			{
				int id = upper_bound(ALL(diff), k - a[j] - a[i]) - diff.begin();
				que[l[i] - 1].pb({id, -1});
				que[i].pb({id, 1});
			}
		}
		else
		{
			for (int j = l[i]; j <= i; j++)
			{
				int id = upper_bound(ALL(diff), k - a[j] - a[i]) - diff.begin();

				que[r[i]].pb({id, 1});
				que[i - 1].pb({id, -1});
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(ALL(diff), a[i]) - diff.begin() + 1;
		ldk.updup(a[i], 1);

		for (auto v : que[i])
		{
			res = res + v.se*ldk.getdown(v.fi);
		}
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
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
