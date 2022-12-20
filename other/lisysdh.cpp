#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mask(n) (1ll << (n))

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18;
const long long MOD = 1e9 + 7;


long long power(long long a, long long b)
{
    if (b == 0) return 1;
    long long aa = power(a, b/2);
    if (b%2) return aa*aa%MOD*a%MOD; else return aa*aa%MOD;
}

int a[1000005];
long long fact[2000005], infact[2000005];

long long c(int k, int nn)
{
    if (k == nn) return 1;
    if (k < 0 || k > nn) return 0;
    return fact[nn]*infact[k]%MOD*infact[nn - k]%MOD;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    int dem = 0;
    cin >> n;
    int sum = 2*(n - 1);
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        if (a[i] != -1)
        {
            sum -= a[i];
        }
        else
        {
            dem++;
        }
    }
    fact[0] = 1;
    for (int i = 1; i <= 2*n; i++) fact[i] = fact[i - 1]*1ll*i%MOD;
    infact[2*n] = power(fact[2*n], MOD - 2);
    for (int i = 2*n; i; i--) infact[i - 1] = infact[i]*1ll*i%MOD;

    cout << c(dem - 1, sum - 1);

}
