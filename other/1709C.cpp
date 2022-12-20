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

int su[200005], mn[200005], mn1[200005];

void solve() 
{
	string s;
	cin >> s;
	int n = (int)s.size();
	s = "@" + s;
	int dem = 0;
	mn[0] = oo;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == '?')
		{
			dem++;
			su[i] = su[i-1];
		} else if (s[i] == '(')
		{
			su[i] = su[i - 1] + 1;
		}
		else
		{
			su[i] = su[i-1] - 1;
		}
		mn[i] = min(mn[i], su[i]);
	}

	mn1[n + 1] = oo;
	int mo = (-su[n] + dem)/2, dong = dem - mo;
	int d = 0;

	for (int i = n; i >= 1; i--)
	{
		mn1[i] = min(mn1[i + 1], su[i] + dem);
		if (s[i] == '?') dem--;
		//cout << mn1[i] << endl;
	}

	dem = 0;
	for (int i = 1; i <= n; i++)
	if (s[i] == '?')
	{
		dem++;
		//cout << min(su[i] + d, mn1[i+1] ) << endl;
		if (min(su[i] + d, mn1[i+1] + d - dem) <= 0)
		{
			d++;
			mo--;
		}
		else 
		{
			if (mo > 0 && dong > 0)
			{
				cout << "NO\n";
				return;
			}
		}
	}

	cout << "YES\n";

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
