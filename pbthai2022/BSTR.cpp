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

const ll base = 9012005;
const int lim = 500000;

string s[lim + 5];
ll pw[lim + 5], hs[lim + 5];
pair<char, string> qe[lim + 5];
unordered_map<ll, bool> ok;
unordered_map<ll, int> dem;

void prepare()
{
	pw[0] = 1;
	for (int i = 1; i <= lim; i++)
	{
		pw[i] = pw[i-1]*base;
	}
}

void solve() 
{
	prepare();

	vector<int> diff;
	int n, q;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}

	cin >> q;

	for (int i = 1; i <= q; i++)
	{
		cin >> qe[i].fi >> qe[i].se;
		if (qe[i].fi == 'q') diff.pb((int)qe[i].se.size());
	}

	sort(ALL(diff)); diff.resize(unique(ALL(diff)) - diff.begin());

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= (int)s[i].size(); j++)
		{
			hs[j] = hs[j - 1]*base + s[i][j-1];
			for (auto v : diff)
			{
				if (j - v < 0) break;
				ll cur = hs[j] - hs[j - v]*pw[v];
				if (ok[cur] == false)
				{
					ok[cur] = true;
					dem[cur]++;
				}
			}
		}
		for (int j = 1; j <= (int)s[i].size(); j++)
		{
			for (auto v : diff)
			{
				if (j - v < 0) break;
				ll cur = hs[j] - hs[j - v]*pw[v];
				ok[cur] = false;
			}
		}
	}

	for (int i = 1; i <= q; i++)
	if (qe[i].fi == 'i' || qe[i].fi == 'e')
	{
		int cu = (qe[i].fi == 'i' ? 1 : -1);
		for (int j = 1; j <= (int)qe[i].se.size(); j++)
		{
			hs[j] = hs[j - 1]*base + qe[i].se[j-1];
			for (auto v : diff)
			{
				if (j - v < 0) break;
				ll cur = hs[j] - hs[j - v]*pw[v];
				if (ok[cur] == false)
				{
					ok[cur] = true;
					dem[cur] += cu;
				}
			}
		}

		for (int j = 1; j <= (int)qe[i].se.size(); j++)
		{
			for (auto v : diff)
			{
				if (j - v < 0) break;
				ll cur = hs[j] - hs[j - v]*pw[v];
				ok[cur] = false;
			}
		}
	}
	else if (qe[i].fi == 'q')
	{
		ll cur = 0;
		for (int j = 1; j <= (int)qe[i].se.size(); j++)
		{
			cur = cur*base + qe[i].se[j - 1];
		}
		cout << dem[cur] << "\n";
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
