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

const int lim = 1000000;

long long sg[4000005], lazy[4000005];
int u, v, ww;
vector<pair<int,int>> ldk[1000005];

void dolazy(int id)
{

	long long &cost = lazy[id];
	sg[id*2] += cost; lazy[id*2] += cost;
	sg[id*2+1] += cost; lazy[id*2 + 1] += cost;
	cost = 0;
}

void update(int id, int l, int r)
{
	if (l > v || r < u) return;
	if (u <= l && r <= v)
	{
		sg[id] += ww;
		lazy[id] += ww;
		return;
	}
	dolazy(id);
	int mid = (l + r)/2;
	update(id*2, l, mid); 
	update(id*2+1, mid + 1, r);
	sg[id] = max(sg[id*2], sg[id*2+1]);
}

void solve() 
{
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		int l, r, w;
		cin >> l >> r >> w;
		ldk[l].pb({r, w});
	}

	long long res = 0;
	for (int i = lim; i; i--)
	if ((int)ldk[i].size())
	{
		//sort(ALL(ldk[i]));
		for (auto vv : ldk[i])
		{
			u = vv.fi; v = lim; ww = vv.se;
			//cout << u << " " << v << endl;
			update(1, 1, lim);
		}

		res = max(res, sg[1]);
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
    //freopen("SSEQ.inp","r",stdin); freopen("SSEQ.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
