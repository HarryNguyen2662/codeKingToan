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

int cnt[25][25], de[25][1200000], dp[1200000];
char s[1200000];

void solve() 
{
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		if (i > 1) 
		{
			cnt[s[i] - 'a'][s[i - 1] - 'a']++;
			cnt[s[i - 1] - 'a'][s[i] - 'a']++; 
		}
	}

	for (int i = 1; i < mask(k); i++)
	{
		int id = -1;
		for (int e = 0; e < k; e++) if (ck(i, e))
		{
			id = e; break;
		}

		for (int j = 0; j < k; j++) 
		{
			de[j][i] = de[j][i^mask(id)] + cnt[j][id];
		}
	}

	for (int i = 1; i < mask(k); i++)
	{
		dp[i] = oo;

		int pos = getbit(i);
		for (int j = 0; j < k; j++) if (ck(i, j))
		{
			dp[i] = min(dp[i], dp[i^mask(j)] + (de[j][i^mask(j)] - de[j][mask(k) - 1 - i])*pos);
		}
	}

	cout << dp[mask(k) - 1];
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
    freopen("KEYBOARD.inp","r",stdin); freopen("KEYBOARD.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
