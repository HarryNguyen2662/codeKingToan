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

int ans[200005];

void solve() 
{
	int n, x;
	cin >> n >> x;

	if (x%2 == 0 && n%2)
	{
		cout << "-1\n"; return;
	}
	if (n%x)
	{
		cout << "-1\n"; return;
	}

	for (int i = 1; i <= n; i++) ans[i] = i;
	ans[n] = 1; ans[1] = x;
	
	int ok = 2;
	while(x < n)
	{
		while((n/x)%ok) ok++;
		ans[x] = x*ok; x = x*ok;
	}

	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << "\n";
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
