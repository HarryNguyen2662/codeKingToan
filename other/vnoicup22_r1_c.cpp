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
const long long MOD = (long long)1e9 + 8277;
const long long MOD1 = (long long)1e9 + 5277;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const long long base = 912005;
string s[1000005];
int dp[1000005];
int cc[1000005];
long long pw[2000005], pw1[2000005];
pair<long long, long long> luu[1000005];
bool cmp(const int &a, const int &b)
{
	return (int)s[b].size() < (int)s[a].size();
}
void solve() 
{
	vector<pair<pair<long long, long long>, int>> ldk;
	pw[0] = 1; pw1[0] = 1;
	for (int i = 1; i <= 2000000; i++) pw[i] = pw[i-1]*base%MOD;
	for (int i = 1; i <= 2000000; i++) pw1[i] = pw1[i-1]*base%MOD1;
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		cc[i] = i;
		long long Hash = 0, Hash1 = 0;
		for (int j = 0; j < (int)s[i].size(); j++)
		{
			Hash = (Hash + 1ll*s[i][j]*pw[j + 1]%MOD)%MOD;
			Hash1 = (Hash1 + 1ll*s[i][j]*pw1[j + 1]%MOD1)%MOD1;
			
		}
		
		ldk.pb({{Hash, Hash1}, i});
		luu[i] = {Hash, Hash1};
		
			//cout << Hash << " " << Hash1 << endl;
	
	}
	sort(cc + 1, cc + 1 + n, cmp); 

	sort(ALL(ldk)); //ldk.resize(unique(ALL(ldk)) - ldk.begin());
	
	for (int ii = 1; ii <= n; ii++)
	{
		int i = cc[ii];
		dp[i] = oo;
		int res = oo;
		long long Hash = 0, Hash1 = 0;
		for (int j = 0; j < (int)s[i].size(); j++)
		{
			int dem = 0;
			Hash = (Hash + 1ll*s[i][j]*pw[j + 1]%MOD)%MOD;
			Hash1 = (Hash1 + 1ll*s[i][j]*pw1[j + 1]%MOD1)%MOD1;
			pair <long long, long long> curhash = {Hash, Hash1}, 
			cur1hash = {(luu[i].fi - Hash + MOD)%MOD, (luu[i].se - Hash1 + MOD1)%MOD1};
			

			if (j != 0 && s[i][j] == s[i][j-1]) continue;
			
			dem++;
			curhash = {(curhash.fi + 1ll*s[i][j]*pw[j + 1 + dem]%MOD)%MOD, (curhash.se + 1ll*s[i][j]*pw1[j + 1 + dem]%MOD1)%MOD1} ;
			cur1hash = {(cur1hash.fi*base)%MOD, (cur1hash.se*base)%MOD1};
			pair<long long, long long> cur = {(curhash.fi + cur1hash.fi)%MOD, (curhash.se + cur1hash.se)%MOD1};
			pair<pair<long long, long long>, int> newtt = {cur, 0};
			int id = lower_bound(ALL(ldk), newtt) - ldk.begin();

			if (id == (int)ldk.size() || ldk[id].fi != cur)
			{
				dp[i] = 1;
				break;
			}
			else dp[i] = min(dp[i], dp[ldk[id].se] + 1);
			
		}	
	}
	for (int i = 1; i <= n; i++) cout << dp[i] << "\n";
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
