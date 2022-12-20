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

int h[100005], dem[100005];
ll sum[100005];

void solve() 
{
	int n, q;
	cin >> n >> q;
	vector<int> diff;
	
	for (int i = 1; i <= n; i++)
	{	
		cin >> h[i];
		diff.pb(h[i]);
	}

	sort(ALL(diff)); diff.resize(unique(ALL(diff)) - diff.begin());

	for (int i = 1; i <= n; i++)
	{
		h[i] = lower_bound(ALL(diff), h[i]) - diff.begin() + 1;
		sum[h[i]] += diff[h[i] - 1];
		dem[h[i]] ++;
	}

	n = (int)diff.size();

	for (int i = 1; i <= n; i++)
	{
		sum[i] += sum[i-1];
		dem[i] += dem[i-1];
	}


	while(q--)
	{
		int k;
		cin >> k;
		int id = lower_bound(ALL(diff), k) - diff.begin() + 1;

		ll ans = 1ll*dem[id - 1]*k - sum[id - 1] + sum[n] - sum[id - 1] - 1ll*(dem[n] - dem[id - 1])*k;
		
		cout << ans << "\n";
	}
}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    //
    freopen("SANNEN.inp","r",stdin); freopen("SANNEN.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
