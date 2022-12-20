#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 998244353;
const int MAXN = 1e6;
const int oo = 1e9;
long long a[1000050];
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("hellodking.txt","r",stdin);
    #else
    // online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long dd,sum,ans=0;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    dd = 1; sum = 0;
    for(int i = n; i; i--)
    {
        ans = (ans + (dd+sum)%MOD*a[i]%MOD)%MOD;
        sum = (sum*2%MOD + dd)%MOD; dd=dd*2%MOD;
    }
    cout << ans;
}