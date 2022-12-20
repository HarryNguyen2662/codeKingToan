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

int de1[1005], de2[1005], de3[1005][1005];

void solve() 
{
	int n, d;
	cin >> d >> n;

	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		x %= d; if (x < 0) x += d;
		y %= d; if (y < 0) y += d;
		de1[x]++; de2[y]++; de3[x][y]++;
	}

	int ans = n;

	for (int i = 0; i < d; i++) for (int j = 0; j < d; j++)
	{
		ans = min(ans, de1[i] + de2[j] - de3[i][j]);
	}

	cout << ans;
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("social-distancing.inp","r",stdin); freopen("social-distancing.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
