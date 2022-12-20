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

const long long nMOD = 500000004;

void solve() 
{
    long long n;
    cin >> n; 
        
    n++;
    long long res = n%MOD;

    if (n == 1)
    {
        cout << res << "\n"; return;
    }
    
    vector<long long> val; val.pb(0);
    int id = 0;
    for (int i = 1; 1ll*i*i <= n - 1; i++)
    {
        val.pb(i);
        id = i;
    }
    for (; id; id--) val.pb(n/id);

    val.resize(unique(ALL(val)) - val.begin());

    for (int i = 1; i < (int)val.size(); i++)
    {
  
        long long k = n/val[i]%MOD; long long sl = (val[i] - val[i-1])%MOD;
        long long sumi = (val[i] + val[i-1] + 1)%MOD*sl%MOD*nMOD%MOD, sumii = (sumi + sl)%MOD;
        long long kk = k*(k - 1)%MOD*nMOD%MOD; if (kk < 0) kk += MOD;
        res = res + k*sl%MOD*((n + 1)%MOD)%MOD - k*sumii%MOD  - kk*sumi;
        res %= MOD; res += MOD; res %= MOD;
    }


    cout << res << "\n";
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("NUMCITIES.inp","r",stdin); freopen("NUMCITIES.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;

    cin >> testcase;
    while(testcase--)
        solve();
}
