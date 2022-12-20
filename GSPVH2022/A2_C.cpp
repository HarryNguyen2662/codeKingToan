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

int a[524299], luu[524299];
long long p[524299];
int n; long long k;

bool check(int h)
{
	int dem = h;
	long long kk = k;
	vector<long long> ldk;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] >= h) dem--;
		else
		{
			long long add = h - a[i];
			if (oo18/p[i] >= add) ldk.pb(add*p[i]); else ldk.pb(oo18);
		}
		if (dem == 0) return true;
	}
	if ((int)ldk.size() < dem) return false;
	sort(ALL(ldk));
	for (auto v : ldk)
	{
		if (kk >= v)
		{
			kk -= v;
			dem--;
		} else return false;
		if (dem == 0) return true;
	}
}

void solve() 
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}

	int l = 1, r = n;

	while(l <= r)
	{
		int mid = (l + r)/2;
		if (check(mid)) l = mid + 1; else r = mid - 1;
	}
	 cout << r << "\n"; 
	int dem = r;
	vector<pair<long long, int>> ldk;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] >= r) dem--;
		else
		{
			long long add = r - a[i];
			luu[i] = add;
			if (oo18/p[i] >= add) ldk.pb({add*p[i], i}); else ldk.pb({oo18, i});
		}
		if (dem == 0) break;
	}
	//
	//cout << ldk.size() << endl;
	//cout << n << endl;
	sort(ALL(ldk));
	if ((int)ldk.size()) for (int i = (int)ldk.size() - 1 ; i >= dem; i--) luu[ldk[i].se] = 0;
	for (int i = 1; i <= n; i++) cout << luu[i] << " ";

}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("hindex.inp","r",stdin); freopen("hindex.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
