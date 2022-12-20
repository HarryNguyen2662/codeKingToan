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

long long s[200005];

void solve() 
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		cin >> s[i];
	}

	if (k == 1)
	{
		cout << "YES\n"; return;
	}

	for (int i = 3; i <= k; i++) if (s[i] - s[i-1] < s[i-1] - s[i-2])
	{
		cout << "NO\n"; return;
	}

	long long cur = s[2] - s[1];

	long long id = n - k + 1;
	
	if (s[1] <= cur*id)
	{
		cout << "YES\n"; return;
	}

	cout << "NO\n";

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
