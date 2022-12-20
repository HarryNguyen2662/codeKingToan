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
long long res = 0;
int l[100005], r[100005];
void trau(int id, long long lcm, long long mx, int lim)
{
	if (lim + 1 == id)
	{
		//cout << lcm << " " << mx << endl;
		if (lcm == mx)res++; res %= MOD1;
		return;
	}
	for (long long i = l[id]; i <= r[id]; i++)
	{
		long long nlcm = lcm;
		if (nlcm == 0) nlcm = i;
		else nlcm = nlcm*i/__gcd(lcm, i);
		if (nlcm > oo) continue;
		trau(id + 1, nlcm, max(mx, i), lim);
	}
}
void solve() 
{
	res = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
	}
	if (n <= 6) (1, 0, -1 , n);
	cout << res << "\n";
}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
