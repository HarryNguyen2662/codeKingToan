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

int ss[55], s[55];
void solve() 
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char x;
			cin >> x;
			if (x == 'X') s[i] += mask(j-1);
		}
		ss[i] = s[i];
	}
	int res = oo;
	for (int tt = 0; tt < mask(m); tt++)
	{
		int dem = 0;
		for (int e = tt; e >= 1; e ^= e & -e)
		{
			dem++;
			int id = __builtin_ctz(e) + 1;
			ss[1] = ss[1]^mask(id-1);
			ss[2] = ss[2]^mask(id-1);
			//cout << id << " " << ss[1]  << endl;
			//cout << m << endl;
			if (id < m) ss[1] ^= mask(id);
			if (id > 1) ss[1] ^= mask(id-2);
  		}
  		for (int e = 2; e <= n; e++)
  		{
  			dem += getbit(ss[e-1]);
  			long long val = ss[e-1];
  			if (e < n) ss[e+1] ^= val;
  			val ^= (ss[e-1]*2); if (ck(ss[e-1], m - 1)) val ^= mask(m);
  			val ^= (ss[e-1]/2);
  			ss[e] ^= val;
  			ss[e-1] = s[e-1];
  			
  		}
  		if (ss[n] == 0)
  		{
  			//cout << tt << " " << dem << endl;
  			res = min(res, dem);
  		}
  		ss[n] = s[n];
	}
	if (res < oo)
	{
		cout <<"You have to tap " << res << " tiles.";
	}
	else
	{
		cout << "Damaged billboard.";
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
    //freopen("billboard.inp","r",stdin); freopen("billboard.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
