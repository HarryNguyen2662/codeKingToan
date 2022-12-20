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

int c[100005];

void solve() 
{	
	int n, id1, id;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> c[i];
		if(c[i]%2) id1 = i;
		if(c[i]%2 == 0) id = i;
	}
	vector<pair<int,int> > ghep;
	
	if (c[1]%2)
	{
		for (int i = 1; i < id1; i++) if (c[i]%2) 
		{
			c[i] = c[id1];
			ghep.pb({i, id1});
		}
		for (int i = 2; i <= n; i++) if (c[i]%2 == 0) ghep.pb({1, i}); 
	}
	else
	{
		for (int i = 1; i < id; i++) if (c[i]%2 == 0) 
		{
			c[i] = c[id];
			ghep.pb({i, id});
		}
		for (int i = 2; i <= n; i++) if (c[i]%2 == 1) ghep.pb({1, i});
	}

	cout << (int)ghep.size() << "\n";

	if ((int)ghep.size())
	for (auto v : ghep) cout << v.fi << " " << v.se <<"\n";

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
