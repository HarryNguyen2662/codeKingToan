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

map<int,int> dd;
long long a[40005];
long long pre[40005], suf[40005], dp[40005];

void solve() 
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		dp[i] = oo15;
	}
	for (int i = n; i; i--)
	{
		if (dd[a[i]] == 0) suf[i] = n + 1;
		else
		{ 
			suf[i] = dd[a[i]];
			pre[suf[i]] = i;
		}

		dd[a[i]] = i;
	}
	set<int> s;
	s.insert(0);
	int lim = sqrt(n) + 1;
	for (int i = 1; i <= n; i++)
	{
		s.insert(i);
		if (pre[i]) s.erase(pre[i]);
		auto id = s.end(); id--; id--;
		for (int de = 1; de <= lim; de++)
		{
			dp[i] = min(dp[i], dp[*id] + de*de);
			if (id == s.begin()) break;
			id--;
		}
	}
	cout << dp[n];
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
