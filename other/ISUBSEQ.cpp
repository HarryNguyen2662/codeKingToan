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
const int lim = 2000;

int a[2005], b[2005], lu[30][3000], mx[30][3000], mn[30][3000], fen[30][3000], fen1[30][3000], dd[3000], ne[3000], luu[3000];


void update(int ti, int id, int val)
{
	if (id == 0) return ;
	for (; id <= lim; id += (id&(-id))) 
		fen[ti][id] = max(fen[ti][id], val);
}

int get(int ti, int id)
{
	int res = 0;
	for (; id; id -= (id&(-id))) res = max(fen[ti][id], res);

	return res;
}

void update1(int ti, int id, int val)
{
	if (id == 0) return ;
	for (; id; id -= (id&(-id))) 
		fen1[ti][id] = max(fen1[ti][id], val);
}

int get1(int ti, int id)
{
	int res = 0;
	for (; id <= lim; id += (id&(-id))) res = max(fen1[ti][id], res);

	return res;
}

void solve() 
{
	int n, m;
	vector<int> diff;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) 
	{
		cin >> b[i]; diff.pb(b[i]);
	}

	sort(ALL(diff)); diff.resize(unique(ALL(diff)) - diff.begin());

	for (int i = 1; i <= m; i++)
	{
		b[i] = lower_bound(ALL(diff), b[i]) - diff.begin() + 1;
		ne[i] = dd[b[i]]; dd[b[i]] = i;
	}

	int res = 0;
	//n = 2; //m = 2;
		
	for (int i = 1; i <= n; i++)
	{
		for (int e = 0; e <= 20; e++) for (int j = 0; j <= lim; j++) fen[e][j] = fen1[e][j] = 0;

		for (int j = 1; j <= m; j++)
		{
			update(a[i] - 1, b[j - 1], mn[a[i] - 1][j - 1]); update1(a[i] + 1, b[j - 1], mx[a[i] + 1][j - 1]);
			luu[j] = max({get(a[i] - 1, b[j] - 1), get1(a[i] + 1, b[j] + 1), lu[a[i]][ne[j]]}) + 1;
			res = max(res,  luu[j]);	
		}

		for (int j = 1; j <= m; j++)
		{
			lu[a[i]][j] = max(lu[a[i]][j], luu[j]);
			for (int e = 1; e <= 20; e++)
			{
				mn[e][j] = max(mn[e-1][j], lu[e][j]);
			}

			for (int e = 20; e; e--)
			{
				mx[e][j] = max(mx[e+1][j], lu[e][j]);
			}
		}
	}

	//cout << res << endl;

	cout << n + m - 2*res;

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
