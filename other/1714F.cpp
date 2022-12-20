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


void solve() 
{
	int n, d12, d23, d13;
	cin >> n >> d12 >> d23 >> d13;

	if (d12 + d13 < d23 || (d12 + d13 - d23)%2)
	{
		cout << "NO\n";
		return;
	}

	vector<pair<int,int>> match;
	int lca = (d12 + d13 - d23)/2;

	if (lca > d12 || lca > d13)
	{
		cout << "NO\n"; return;
	}

	d13 -= lca;

	int pre = 1, cur, adu;
	int id = 4;

	if (lca == 0) adu = 1;


	for (int i = 1; i <= d12; i++)
	{
		if (i == d12) cur = 2;
		else
		{
			if (i == lca && d13 == 0) cur = 3;
			else
			{
				cur = id; 
				id++;
			}
		}
		if (cur > n)
		{
			cout << "NO\n"; return;
		}
		
		match.pb({pre, cur});

		if (i == lca) adu = cur;

		pre = cur;
	}

	pre = adu;

	for (int i = 1; i <= d13; i++)
	{
		if (i == d13) cur = 3; else
		{
			cur = id; id++;		
		}

		if (cur > n)
		{
			cout << "NO\n"; return;
		}

		match.pb({pre, cur});

		pre =cur;
	}

	 pre = 1;
	 for (; id <= n; id++)
	 {
	 	match.pb({pre, id});
	 	pre = id;
	 }

	cout << "YES\n"; for (auto v : match) cout << v.fi << " " << v.se << "\n";

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
