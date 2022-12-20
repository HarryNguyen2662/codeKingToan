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

bool a[100005];

void solve() 
{

	vector<long long> ldk, dk;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++)
	{
		int w;
		cin >> w;
		if (a[i] == 0) ldk.pb(w); else dk.pb(w);
	}
	sort(ALL(ldk)); sort(ALL(dk));

	if ((int)ldk.size() == 0)
	{
		long long res = 0;
		for (auto v : dk) res += v;

		cout << res << "\n"; return;
	}

	if ((int)dk.size() == 0)
	{
		long long res = 0;
		for (auto v : ldk) res += v;

		cout << res << "\n"; return;
	}

	long long res = 0;

	if ((int)ldk.size() == (int)dk.size())
	{
		for (int i = (int)ldk.size() - 1; i > 0; i--) res += 2*(ldk[i] + dk[i]);

		res += min(ldk[0], dk[0]) + 2*max(ldk[0], dk[0]);
	}

	if ((int)ldk.size() < (int)dk.size())
	{
		int w = -(int)ldk.size() + (int)dk.size();
		for (int i = (int)ldk.size() - 1; i >= 0; i--) 
		{
			res += 2*(ldk[i] + dk[i + w]);
		
		}
		for (int i = 0; i < w; i++) res += dk[i];
	}
	

	if ((int)dk.size() < (int)ldk.size())
	{
		int w = -(int)dk.size() + (int)ldk.size();
		for (int i = (int)dk.size() - 1; i >= 0; i--) res += 2*(dk[i] + ldk[i + w]);

		for (int i = 0; i < w; i++) res += ldk[i];
	}
	
	cout << res << "\n";
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
