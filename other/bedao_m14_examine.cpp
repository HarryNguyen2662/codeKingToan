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
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll lu[50], luu[50];

void solve() 
{
	ll n; cin >> n;

	if (n == 1)
	{
		cout << "2\n"; return;
	}

	int cnt = 0;

	for (ll i = 2; 1ll*i*i <= n; i++)
	if (n%i == 0)
	{
		lu[cnt] = 1;
		while(n%i == 0)
		{
			lu[cnt] = 1ll*i*lu[cnt]%MOD; n /= i;
		}
		luu[cnt] = lu[cnt]*lu[cnt]%MOD;
		cnt++;
	}

	if (n > 1)
	{
		lu[cnt] = n%MOD; luu[cnt] = lu[cnt]*lu[cnt]%MOD;
		cnt++;
	}


	ll  res = 0;

	for (int i = 0; i < mask(cnt); i++)
	{
		ll a = 1, b = 1;
		for (int j = 0; j < cnt; j++) if (ck(i, j))
		{
			a = a*lu[j]%MOD; b = b*luu[j]%MOD;
		}
		else
		{
			a = a*luu[j]%MOD; b = b*lu[j]%MOD;
		}

		res = res + a + b; res %= MOD;
	}

	cout << res*500000004%MOD << "\n";
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
