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
const long long base = 11062004;

void solve() 
{
	int n;
	cin >> n;
	int res1 = 0;
	int res = n;
	vector<long long> ldk;
	int dem = 0;
	long long inbase = 1;
	bool kt = true;
	int len = 0;
	for (int i = 1; i <= n; i++)
	{
		len++;
		char x;
		cin >> x;
		if (x == '(') dem++; else dem--;
		if (dem < 0)
		{
			kt = false;
		}
		if (ldk.empty()) ldk.pb((x == '(' ? 1 : 2)); else
		ldk.pb((ldk.back()*base%MOD + (x == '(' ? 1 : 2))%MOD);
		if (len%2 == 0) inbase = inbase*base%MOD;
		int sz = (int)ldk.size();
		if (sz >= 2) cout << ldk[sz/2-1] << " " <<  (ldk.back() - ldk[(sz + 1)/2 - 1]*inbase%MOD + MOD)%MOD << endl;
		if ((kt&&dem == 0) || (sz >= 2 && ldk[sz/2-1] == (ldk.back() - ldk[(sz + 1)/2 - 1]*inbase%MOD + MOD)%MOD))
		{
			inbase = 1;
			ldk.clear();
			kt = true;
			res -= len;
			res1++;
			len = 0;
			dem = 0;
			continue;
		}
		
	}
	cout << res1 << " " << res << "\n";
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
