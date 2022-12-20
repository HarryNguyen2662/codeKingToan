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
const long long MOD1 = 1e9 + 7;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long f[1000005];

void solve() 
{   
    int n; long long k;
    cin >> n >> k;

    long long res = 0;

    if (1ll*n*(n-1)/2 < k)
    {
        cout << "-1\n";
    }

    for (int i = 1; i <= n; i++)
    if (1ll*(n - i)*(n - i - 1)/2 >= k)
    {
        res = (res + 1ll*i*f[i]%MOD1)%MOD1;
    }
    else
    {
        k -= 1ll*(n - i)*(n - i - 1)/2; 
        res = (res + 1ll*(k + i)*f[i]%MOD1)%MOD1;
        int id = i;
        for (int j = n - i; j >= 0; j--)
        if (j + i != k + i)
        {
            id++;
            res = (res + 1ll*(j + i)*f[id]%MOD1)%MOD1;
        }

        break;
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
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    
    f[1] = 1;
    for (int i = 2; i <= 1000000; i++) f[i] = f[i-1]*2%MOD1;

    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
