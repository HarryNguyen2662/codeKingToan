#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6;
const int oo = 1e9;
map<int,int> dem;
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
    int n,x;
    long long res = 0,sum=0;
    vector<int> ldk;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (dem[x] ==0) ldk.pb(x);
        dem[x]++;
    }
    for (auto u : ldk)
    {
        long long v = dem[u];
        long long w = 1ll*v*(v-1), e = 1ll*(v-2)*(v-3);
        if (v>=4)
        {
            long long tt = w;
            if (tt%4==0) tt/=4; else e/=4;
            if (tt%3==0) tt/=3; else e/=3;
            if (tt%2==0) tt/=2; else e/=2;
            tt = tt%MOD; e = e %MOD;
            res = (res + tt*e%MOD)%MOD;
         }
        if(v>=2)
        {
            res = (res + (w/2)%MOD*sum%MOD)%MOD;
            sum = (sum+w/2)%MOD;
        }
    }
    cout<<res;
}