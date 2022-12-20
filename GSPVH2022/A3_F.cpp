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

const int lim = 600000;

int t[300005], tt[300005], d[300005], dd[300005], id[300005], fen[600005];
long long fen1[600005];

void update(int id, int val)
{
	for (; id; id -= (id&(-id))) fen[id] += val;
}

int get(int id)
{
	int res = 0;
	for (; id <= lim; id += (id&(-id))) res += fen[id];
	return res;
}

void update1(int id, int val)
{
	for (; id <= lim; id += (id&(-id))) fen1[id] += val;
}

long long get1(int id)
{
	long long res = 0;
	for (; id; id -= (id&(-id))) res += fen1[id];
	return res;
}

void solve() 
{
	long long res = 0;
	vector<int> diff;
	int n, q;
	diff.pb(-oo);
	
	cin >> n >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> d[i];
		diff.pb(d[i]);
	}
	
	sort(ALL(diff));
	
	for (int i = 1; i <= n; i++)
	{
		res += t[i];
		res -= 1ll*(n - i + 1)*diff[i];
	}
	
	for (int i = 1; i <= q; i++)
	{
		cin >> id[i] >> tt[i] >> dd[i];
		diff.pb(dd[i]);
	}
	
	sort(ALL(diff)); diff.resize(unique(ALL(diff)) - diff.begin());
	

	for (int i = 1; i <= n; i++) 
	{
		d[i] = lower_bound(ALL(diff), d[i]) - diff.begin();
		update(d[i], 1); update1(d[i], diff[d[i]]);
	}

	cout << res << " ";
	
	for (int i = 1; i <= q; i++) 
	{
		dd[i] = lower_bound(ALL(diff), dd[i]) - diff.begin();
		
		res -= t[id[i]]; res += tt[i]; 

		res += (1ll*get(d[id[i]] + 1)*diff[d[id[i]]] + get1(d[id[i]]));
		update(d[id[i]], -1); update1(d[id[i]], -diff[d[id[i]]]);

		res -= (1ll*(get(dd[i] + 1) + 1)*diff[dd[i]] + get1(dd[i]));
		update(dd[i], 1); update1(dd[i], diff[dd[i]]);

		d[id[i]] = dd[i]; t[id[i]] = tt[i];
		cout << res << " ";
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
    //freopen("raspored.inp","r",stdin); freopen("raspored.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
