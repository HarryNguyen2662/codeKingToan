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

bool dd[1000005];

void solve() 
{
	long long n;
	cin >> n;
	long long res = n*(n+1)/2;

	if (res%2)
	{
		cout << "NO"; return;
	}

	cout << "YES\n";

    res /= 2;

    vector<int> ldk;

    for (int i = n; i; i--)
    {
        if (res && res <= n && !dd[res])
        {
            ldk.pb(res); dd[res] = true; break;
        }
        if (!dd[i] && res >= i)
        {
            res -= i; dd[i] = true; ldk.pb(i);
        }
    }

    cout << (int)ldk.size() << "\n"; for (auto v : ldk) cout << v << " "; cout << "\n";

    cout << n - (int)ldk.size() << "\n"; for (int i = 1; i <= n; i++) if (!dd[i]) cout << i << " ";
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
    //cin >> testcase;
    while(testcase--)
        solve();
}
