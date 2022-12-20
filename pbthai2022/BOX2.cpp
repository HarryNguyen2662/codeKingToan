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

pair<int,int> a[100005];
int cs[100005], trace[100005];

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].fi >> a[i].se;
		cs[i] = i;
	}

	sort(cs + 1, cs + 1 + n, [](const int &x, const int &y)
	{
		if (a[x].fi == a[y].fi) return a[x].se > a[y].se;
		return a[x].fi < a[y].fi;
	});
//	cout << cs[1] << endl;

	set<pair<int,int>> ldk;
//	cout << cs[2] << endl;
	for (int i = 1; i <= n; i++)
	{
		auto w = ldk.lower_bound(make_pair(a[cs[i]].se, 0));
		if (w != ldk.begin())
		{
			w--;
			//cout << i << endl;
			trace[cs[i]] = (*w).se;
			ldk.erase(*w);
		}
		ldk.insert(make_pair(a[cs[i]].se, cs[i]));
	}

	cout << (int)ldk.size() << "\n";
	for (auto i = ldk.begin();; i++)
	{
		if (i == ldk.end()) break;
		int id =  (*i).se;
		vector<int> res;
		while(id)
		{
			res.pb(id);
			id = trace[id];
		}
		cout << (int)res.size() << " "; for (auto v : res) cout << v << " ";
		cout << "\n";
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
