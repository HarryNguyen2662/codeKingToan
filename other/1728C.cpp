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


map<int,int> dem, dem1;
int du[100], duu[100], a[200005], b[200005];

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		if (a[i] >= 10)
		{
			dem[a[i]]++;
		}
		else
		{
			du[a[i]]++;
		}
	}
	for (int i = 1; i <= n; i++) 
	{
		cin >> b[i];
		if (b[i] >= 10)
		{
			dem1[b[i]]++;
		}
		else
		{
			duu[b[i]]++;
		}
	}

	int res = 0;

	for (int i = 1; i <= n; i++)
	{
		if (a[i] >= 10)
		{
			res += abs(dem[a[i]] - dem1[a[i]]);
			string st = to_string(a[i]);
			if (dem[a[i]] > dem1[a[i]])
			du[(int)st.size()] += dem[a[i]] - dem1[a[i]];
			else duu[(int)st.size()] += dem1[a[i]] - dem[a[i]];
			dem[a[i]] = dem1[a[i]] = 0;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (b[i] >= 10)
		{
			res += abs(dem[b[i]] - dem1[b[i]]);
			string st = to_string(b[i]);
			if (dem[b[i]] > dem1[b[i]])
			du[(int)st.size()] += dem[b[i]] - dem1[b[i]];
			else duu[(int)st.size()] += dem1[b[i]] - dem[b[i]];
			dem[b[i]] = dem1[b[i]] = 0;
		}
	}

	for (int i = 2; i <= 10; i++) 
	{
		res += abs(du[i] - duu[i]);
		du[i] = duu[i] = 0;
	}
	du[1] = duu[1] = 0;

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
