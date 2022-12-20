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

int iq[1000005];
map<string,int> dd;
string cs[1000005];
vector<string> ldk;
int dem[1000005];
vector<int> a[1000005];

void solve() 
{
	int n, k, s, m;
	int cnt  = 0;
	int sl = 0;
	cin >> n >> k >> s >> m;
	for (int i = 1; i <= s; i++)
	{
		string w;
		cin >> w;
		if (dd[w] == 0) dd[w] = ++cnt;
		iq[++sl] = dd[w];
		dem[iq[sl]] = k;
		ldk.pb(w);
	}
	for (int i = 1; i <= m; i++)
	{
		string w, ww;
		cin >> w >> ww;
		int id = dd[w], id1 = dd[ww];
		if (id == 0)
		{
			id = ++cnt;
			dd[w] = cnt;
			cs[cnt] = w;
		}
		if (id1 == 0)
		{
			id1 = ++cnt;
			dd[ww] = cnt;
			cs[cnt] = ww;
		}
		a[id].pb(id1); a[id1].pb(id);
	}

	for (int i = 1; i <= n; i++) 
	{
		sort(ALL(a[i])); a[i].resize(unique(ALL(a[i])) - a[i].begin());
	}

	int sl1 = 1;
	
	while(sl1 <= sl)
	{
		int u = iq[sl1]; sl1++;
		for (auto v : a[u])
		{
			dem[v]++;
			if (dem[v] == k)
			{
				iq[++sl] = v;
				ldk.pb(cs[v]);
			}
		}
	}
	sort(ALL(ldk));
	cout <<(int)ldk.size() << "\n";
	for (auto v : ldk) cout << v << " ";

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
