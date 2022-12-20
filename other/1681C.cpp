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

int a[1000], b[1000];
void solve() 
{
	int n;
	vector<pair<int,int>> res;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) 
	{
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) if (a[i] > a[j])
		{
			res.pb({i, j}); swap(a[i], a[j]); swap(b[i], b[j]);
		}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) if (b[i] > b[j])
		{
			res.pb({i, j}); swap(a[i], a[j]); swap(b[i], b[j]);
		}
	if ((int)res.size() > 10000)
	{
		cout << "-1\n";
		return;
	}
	for (int i = 2; i <= n; i++) if (a[i] < a[i-1] || b[i] < b[i-1])
	{
		cout << "-1\n";
		return;
	}
	cout << (int)res.size() << "\n";
	for (auto v : res) cout << v.fi << " " << v.se << "\n";

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
    cin >> testcase;
    while(testcase--)
        solve();
}
