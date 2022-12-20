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
typedef long long ll;
struct matrix
{
	long long fibo[2][2];

	matrix operator * (const matrix &other) const
	{
		matrix res;
		for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			res.fibo[i][j] = 0;
			for (int k = 0; k < 2; k++)
			{
				res.fibo[i][j] += fibo[i][k]*other.fibo[k][j]%MOD;
				if (res.fibo[i][j] >= MOD) res.fibo[i][j] -= MOD;
			}
		}
		return res;
	}
};
int cal(long long n)
{
	if (n == 1) return 1;
	if (n == 2) return 0;
	matrix a, res;
	a.fibo[0][0] = 0; a.fibo[0][1] = a.fibo[1][0] = a.fibo[1][1] = 1; res = a;
	int st = 40;
	for (; st >= 0; st--) if (ck(n , st)) break;
	//cout << st << endl;
	for (int i = st - 1; i >= 0; i--)
	{
		res = res*res;
		if (ck(n,  i)) res = res*a;
	} 
	//cout << res.fibo[0][1] << endl;
	return res.fibo[0][1];
}
void solve() 
{
	vector<ll> query;
	string s;
	cin >> s;
	long long val = 0;
	bool kt = false;
	for (int i = 0; i < (int)s.size(); i++)
	{
		if (s[i] == ')')
		{
			query.pb(val); val = 0;
			kt = false;
		}
		if (kt)
		{
			val = val*10 + s[i] - '0';
			//cout << s[i] << endl;
		}
		if (s[i] == '(')
		{
			kt = true;
		}
		
	}
	//cout << query[0] << endl;
	for (auto v : query)
	{
		long long sum = 0;
		for (ll i = 1; 1ll*i*i <= v; i++)
		if (v % i == 0)
		{
			//cout << i << " " << v/i << endl;
			sum += cal(i); if (sum >= MOD) sum -= MOD;
			if (i*i != v) 
			{
				sum += cal(v/i); if (sum >= MOD) sum -= MOD;
			}
		}
		cout << sum << "\n";
	}	
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
