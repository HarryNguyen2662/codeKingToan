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

long long dist[2005];
long long a[2005];
bool use[2005];
void solve() 
{
	int n; long long T;
	cin >> n >> T;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	
	for (int i = 0; i < a[1]; i++) dist[i] = oo18;
	dist[0] = 0;
	for (int i = 0; i < a[1]; i++)
	{
		int v = -1;
		for (int j = 0; j < a[1]; j++)
		if (!use[j] && (v == -1 || dist[v] > dist[j])) v = j;
		//cout << v << " " << dist[v] << endl;
		if (dist[v] == oo18) break;
		use[v] = true;

		for (int e = 1; e <= n; e++) 
		if (dist[(v + a[e])%a[1]] > dist[v] + a[e])
		{
			dist[(v + a[e])%a[1]] = dist[v] + a[e];
		}
	}
	long long res = 0;
	for (long long i = 0; i < a[1]; i++)
	{
		//cout << "check " << T/a[1] << endl;
		res += max(0ll, max(0ll, T/a[1] + (T%a[1] >= i)) - max(0ll, (dist[i] - 1)/a[1] + ((dist[i] - 1)%a[1] >= i)));
	}
	cout << res;
}	

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    // //
    freopen("YENOM.inp","r",stdin); freopen("YENOM.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
