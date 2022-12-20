#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
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
const long long MOD = 1e9 + 19972207;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dem[16777230];

void solve() 
{
	int n, k;
	cin >> n >> k;
	int lim = mask(k) - 1;
	
	for (int i = 1; i <= n; i++)
	{
		int status = 0;
		string s;
		cin >> s;
		for (int j = 0; j < (int)s.size(); j++) if (!ck(status, s[j] - 'a')) status += mask(s[j] - 'a');
		dem[status]++;
	}

	for (int i = 0; i < k; i++) for (int j = 0; j <= lim; j++)
	if (ck(j, i)) dem[j] += dem[j^mask(i)];

	ll base = 1;
	ll ans = 0;

	for (int i = 0; i <= lim; i++)
	{
		ans += 1ll*(n - dem[lim - i])*base%MOD; if (ans >= MOD) ans -= MOD;
		base = base*1ll*(n + 1)%MOD;
	}

	cout << ans;
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("urgent.inp","r",stdin); freopen("urgent.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
