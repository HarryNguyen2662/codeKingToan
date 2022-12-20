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

const int lim = 100005;

long long fen[15][200005];
pair<int, int> a[100005];

void udpate(int ti, int id, long long val)
{
	for (; id <= lim; id+= (id&(-id))) fen[ti][id] += val;
}

long long getsum(int ti, int id)
{
	long long res = 0;
	for (; id; id -= (id&(-id))) res += fen[ti][id];
	return res;
}

vector<int> ldk[100005];

void solve() 
{
	int n, k;
	vector<int> diff;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].fi >> a[i].se; a[i].se++;
		ldk[a[i].fi].pb(a[i].se);
		diff.pb(a[i].fi);
	}

	sort(ALL(diff)); diff.resize(unique(ALL(diff)) - diff.begin());


	for (auto v : diff) sort(ALL(ldk[v]));

	udpate(0, 1, 1);

	for (int i = 0; i < (int)diff.size(); i++)
	for (int j = k; j >= 1; j--)
	{
		for (auto v : ldk[diff[i]])
		{
			long long w = getsum(j - 1, v - 1);
			udpate(j, v, w);
		}
	}

	cout << getsum(k, lim);
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
