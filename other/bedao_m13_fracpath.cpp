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

int comp(ll x, ll y, ll u, ll v)
{
	//cout << x << " " << y <<  " " << u << " " << v << endl;
	if (y == 0 || v == 0)
	{
		if (y == v) return 0;
		else if (y < v) return 1;
		else return -1;
	}
	ll e = x/y, ee = u/v;
	if (e == ee)
	{

		int ss = comp(y, x%y, v, u%v);
		if (ss == 0) return 0;
		else if (ss == 1) return -1;
		else return 1; 
	}
	else if (e < ee) return -1;
	else return 1;
}

void solve() 
{
	ll a, b;
	cin >> a >> b;

	ll lc = 0, llc = 1, rc = 1, rrc = 0, cu = 0, cur = 0;

	//cout << comp(2, 3, a, b) << endl;

	while(true)
	{
		cu = lc + rc; cur = llc + rrc;
		//cout << cu << " " << cur << endl;
		int ss = comp(cu, cur, a, b);
		if (ss == 0)
		{
			cout << "\n";
			return;
		}
		else if (ss == 1)
		{
			cout << "L";
			rc = cu; rrc = cur;
		}
		else
		{
			cout << "R";
			lc = cu; llc = cur;
		}
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
    cin >> testcase;
    while(testcase--)
        solve();
}
