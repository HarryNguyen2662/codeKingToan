#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 18
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1ll << (i))
#define setp(x) setprecision(x)
#define NMOD 3
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353; 
const int MAXN = 2e5+2;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 9223372036854775807;
int a[100015];
vector<int> ldk;
int fen[100005];
long long fen1[100005], resum, sum[100005];
void update(int x, int val)
{
    for (; x <= 100000; x += (x&(-x)))
    {
        fen[x]++;
        fen1[x] += val;
    }
}
int get(int x)
{
    int dem = 0;
    for (; x; x -= (x&(-x)))
    {
        resum += fen1[x];
        dem += fen[x];
    }
    return dem;
}
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //online submission
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ldk.pb(a[i]);
    }
    sort(ldk.begin(), ldk.end());
    ldk.resize(unique(ldk.begin(), ldk.end()) - ldk.begin());
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(ldk.begin(), ldk.end(), a[i]) -ldk.begin() + 1;
    }
    update(a[1], ldk[a[1]-1]);
    long long w = ldk[a[1]-1];
    for (int i = 2; i < n; i++)
    {
        w += ldk[a[i]-1];
        resum = 0;
        int ww = get(a[i]-1);
        sum[i] = (w - resum - 1ll*(i-ww)*1ll*ldk[a[i]-1]%MOD) + 1ll*ww*1ll*ldk[a[i]-1]%MOD - resum;
        sum[i] %= MOD; sum[i] += MOD; sum[i] %= MOD;
        //cout << sum[i] << endl;
        update(a[i], ldk[a[i]-1]);
    }
    for (int i = 1; i <= n; i++) 
    {
        fen[i] = 0;
        fen1[i] = 0;
    }
    long long ans = 0;
    update(a[n], ldk[a[n]-1]);
    w = ldk[a[n]-1];
    for (int  i = n-1; i > 1; i--)
    {
        w += ldk[a[i]-1];
        //cout << w << endl;
        resum = 0;
        int ww = get(a[i]-1);
        //cout << ww << endl;
        //cout << resum << endl;
        long long k = (w - resum - 1ll*(n-i+1-ww)*1ll*ldk[a[i]-1]%MOD) + 1ll*ww*1ll*ldk[a[i]-1]%MOD - resum;
        k %= MOD; k += MOD; k %= MOD;
        //cout << k << endl;
        ans += k*sum[i]%MOD; ans %=MOD;
        update(a[i], ldk[a[i]-1]);
    }
    cout << ans;
}