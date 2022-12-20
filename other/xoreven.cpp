#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
#define fi first
#define se second
#define pb push_back
#define log 19
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

int a[100005], b[100005];

void solve() 
{
	int n, q, su = 0;
	cin >> n >> q;
	
	set<int> ldk;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		
		b[i] = 0;
		
		for (int j = 0; j <= log; j++) if (ck(a[i], j))
		b[i] = 1 - b[i];
	 	
	 	su += b[i];
		
		if (b[i]) ldk.insert(i);
	}


	while(q--)
	{
		int vt, val;
		cin >> vt >> val;
		
		vt++;
		
		su -= b[vt]; 
		
		if (b[vt]) ldk.erase(vt);
		
		b[vt] = 0;
		
		for (int i = 0; i <= log; i++) if (ck(val, i))
		{
			 b[vt] = 1 - b[vt];
		}
		
		su += b[vt];
		
		if (b[vt]) ldk.insert(vt);

		if (su%2 == 0)
		{
			cout << n << " ";
		}
		else
		{
			int mx = *ldk.rbegin(), mn = *ldk.begin();
			cout << max(n - mn, mx - 1) << " ";
		}
	}

	cout << "\n";
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
