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

int cnt = 0, to[1005][27], link[1005], dp[1005][1005];
bool term[1005];
pair<int, int> back[1005];

void add(const string &s)
{
	int p = 0;

	for (int i = 0; i < (int)s.size(); i++)
	{
		int cur = s[i] - 'a';
		if (to[p][cur] == 0)
		{
			to[p][cur] = ++cnt;
			back[to[p][cur]] = {p, cur};
		}
		
		p = to[p][cur];
		
		if (term[p]) return;
	}

	term[p] = true;
}

void build()
{
	queue<int> qe;
	qe.push(0);

	while(!qe.empty())
	{
		int u = qe.front(); qe.pop();
		int v = link[u];
		if (term[v]) term[u] = true;
		for (int i = 0; i < 26; i++)
		if (to[u][i])
		{
			link[to[u][i]] = (u == 0 ? 0 : to[v][i]);
			qe.push(to[u][i]);
		}
		else to[u][i] = to[v][i];
	}
}

void solve() 
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		add(s);
		reverse(ALL(s));
		add(s);
	}

	build();

	back[0] = {-1, -1};

	ll ans = 1;
	dp[0][0] = 1;


	for (int i = 0; i < (k + 1)/2; i++)
	{
		ans = ans*26%MOD;
		for (int j = 0; j <= cnt; j++)
		{
			for (int e = 0; e < 26; e++)
			{
				int nj = to[j][e];
				if (!term[nj])
				{
					dp[i + 1][nj] += dp[i][j];
					if (dp[i + 1][nj] >= MOD) dp[i + 1][nj] -= MOD;
				}
			}
		}
	}

	n = (k + 1)/2;

	ans += MOD - dp[n][0]; if (ans >= MOD) ans -= MOD;

	for (int i = 1; i <= cnt; i++)
	{
		int p = i, p1 = i;
		bool ok = true;

		if (k%2)
		p = back[p].fi;

		while(true)
		{
			if (term[p1]) 
			{
				ok = false;
				break;
			}
			if (p == 0) break;
			int np = back[p].fi, cur = back[p].se;
			if (to[p1][cur] == 0) break;
			if (cur != back[to[p1][cur]].se) break;
			p = np; p1 = to[p1][cur];
		}

		if (ok) 
		{
			ans += MOD - dp[n][i]; if (ans >= MOD) ans -= MOD;
		}
	}

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
    //freopen("UGPALIND.inp","r",stdin); freopen("UGPALIND.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
