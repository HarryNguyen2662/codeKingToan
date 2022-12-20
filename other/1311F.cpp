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

pair<long long, long long> fen[200005];
const int lim = 200005;
pair<int,int> a[200005];

void update(int id, int val)
{
	for (; id <= lim; id += (id & (-id))) 
	{
		fen[id].fi ++; fen[id].se += val;
	}
}

pair<long long, long long> get(int id)
{
	pair<long long, long long> res = {0, 0};
	for (; id; id -= (id & (-id))) 
	{
		res.fi += fen[id].fi; res.se += fen[id].se;
	} 

	return res;
}



void solve() 
{

	vector<int> diff1;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].fi;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].se;
		diff1.pb(a[i].se);
	}

	sort(ALL(diff1)); diff1.resize(unique(ALL(diff1)) - diff1.begin());

	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		//cout << a[i].se << endl;
		a[i].se = lower_bound(ALL(diff1), a[i].se) - diff1.begin() + 1;
	}
	long long res = 0;
	for (int i = 1; i <= n; i++)
	{
		
		pair<long long, long long> adu = get(a[i].se);

		res = res + 1ll*a[i].fi*adu.fi - adu.se;
		update(a[i].se, a[i].fi);

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
