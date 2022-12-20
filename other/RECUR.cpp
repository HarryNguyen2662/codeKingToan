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

const int lim = 1000000;

ll fe[lim + 5], fe1[lim + 5], fen[lim + 5], fen1[lim + 5];
ll res[lim + 5];
int l[lim + 5], r[lim + 5], a[lim + 5];
vector<pair<int,int>> ldk[lim + 5], dk[lim + 5];

void upd(int id, ll va)
{
	ll val = (id - 1)*va;
	for (; id <= lim; id += (id&(-id)))
	{
		fe[id] += va;  fen[id] += val;
	}
}

long long ge(int id)
{
	ll ans = 0, ans1 = 0;

	ll cs = id;

	for (; id; id -= (id&(-id)))
	{
		ans += fe[id];
		ans1 += fen[id];
	}

	return cs*ans - ans1;
}

void update(int u, int v)
{
	upd(u, 1); upd(v + 1, -1);
}

long long get(int u, int v)
{
	return ge(v) - ge(u - 1);
}

void upd1(int id, ll va)
{
	ll val = (id - 1)*va;
	for (; id <= lim; id += (id&(-id)))
	{
		fe1[id] += va;  fen1[id] += val;
	}
}

long long ge1(int id)
{
	ll ans = 0, ans1 = 0;

	ll cs = id;

	for (; id; id -= (id&(-id)))
	{
		ans += fe1[id];
		ans1 += fen1[id];
	}

	return cs*ans -ans1;
}

void update1(int u, int v)
{
	upd1(u, 1); upd1(v + 1, -1);
}

long long get1(int u, int v)
{
	return ge1(v) - ge1(u - 1);
}

void solve() 
{
	stack<int> st;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		while(!st.empty() &&  a[st.top()] < a[i]) st.pop();
		if (st.empty()) l[i] = 1; else l[i] = st.top() + 1;
		st.push(i);
	}

	while(!st.empty()) st.pop();

	for(int i = n; i; i--)
	{
		while(!st.empty() && a[st.top()] < a[i]) st.pop();
		if (st.empty()) r[i] = n; else r[i] = st.top() - 1;
		st.push(i);
	}

	vector<int> le(m + 1);

	for (int i = 1; i <= m; i++)
	{	
		cin >> le[i];
	}

	for (int i = 1; i <= m; i++)
	{
		int rr; cin >> rr;
		if (le[i] <= rr)
		{
			dk[rr].pb({le[i], i});
			ldk[le[i]].pb({rr, i});
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (auto v : ldk[i]) res[v.se] -= get(i, v.fi);
		for (auto v : dk[n - i + 1]) res[v.se] -= get1(v.fi, n - i + 1);
		update(l[i], r[i]); update1(l[n - i + 1], r[n - i + 1]);
	}
	//cout << get(1, 4) << endl;

	for (int i = 1; i <= n; i++)
	{
		for (auto v : ldk[i]) res[v.se] += get(i, v.fi);
	}

	for (int i = 1; i <= m; i++) cout << res[i] << " ";
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
