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
const long long nMOD = 500000004;
const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int lim = 100000;

ll mo[lim + 5];
vector<int> ver1, ver2, ver3;

void prepare()
{
	mo[1] = 1;
	for (int i = 1; i <= lim; i++)
	for (int j = 2*i; j <= lim; j += i)
	{
		mo[j] -= mo[i];
	}

	for (int i = 1; i <= lim; i++)
	{
		mo[i] = mo[i]*1ll*i*i%MOD + mo[i-1]; mo[i] %= MOD;
	}
}

ll cal(int n, int m)
{
	if (n <= 0 || m <= 0) return 0;

	if (n < m) swap(n, m);


	ver1.pb(0); ver2.pb(0);
	for (int i = 1; 1ll*i*i <= n; i++) ver1.pb(i);
	for (int i = sqrt(n); i; i--) ver1.pb(n/i); 
	for (int i = sqrt(m); i; i--) ver2.pb(m/i);
		
	ver3.resize((int)ver1.size() + (int)ver2.size());

	// cout << ver1.size() << " " << ver2.size() << endl;
	merge(ALL(ver1), ALL(ver2), ver3.begin());

	ver3.resize(unique(ALL(ver3)) - ver3.begin());

	ll ans = 0;

	for (int i = 1; i < (int)ver3.size(); i++)
	{
		ll u = n/ver3[i],  v = m/ver3[i];
		ll cur = (u + 1)*u%MOD*nMOD%MOD*(v + 1)%MOD*v%MOD*nMOD%MOD;
		ans += (mo[ver3[i]] - mo[ver3[i - 1]])*cur; ans %= MOD;
	}

	vector<int>().swap(ver1);
	vector<int>().swap(ver2);
	vector<int>().swap(ver3);
	ans += MOD; ans %= MOD; return ans;
}

void solve() 
{
	int a, b, c, d; ll k;
	cin >> a >> b >> c >> d >> k;

	// cout << a << " " << b << " " << c << " " << d << endl;
	if (a > b || c > d || k == 0) 
	{
		cout << "0\n";
		return;
	}
	b /= k; d /= k; a = (a + k - 1)/k; c = (c + k - 1)/k;

	if (a > b || c > d || k == 0) 
	{
		cout << "0\n";
		return;
	}
	cout <<((cal(b, d) - cal(a - 1, d) - cal(b, c - 1) + cal(a - 1, c - 1))%MOD + MOD)%MOD*k%MOD*k%MOD << "\n";
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
    prepare();
    cin >> testcase;
    while(testcase--)
        solve();
}
