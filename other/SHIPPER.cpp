#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 17
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1ll << (i))
#define ck(n, i) (((n) >> (i))&1) 
#define setp(x) setprecision(x)
#define NMOD 3
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789; 
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 922372036854775807;
const long long nMOD = 500000004;
int x[200005];
long long cal(vector<pair<int, int>> &ldk, int k) 
{    
    sort(ldk.begin(), ldk.end(), greater<pair<int, int>> ());
    int n = ldk.size();
    int i = 0;
    long long ans = 0;
    while (i < n) 
    {
       // cout << ldk[i].fi << endl;
        if (ldk[i].se < k) 
        {
            int p = ldk[i].fi;
            int sum = 0;
            while (i < n && sum < k) 
            {
                int val = min(k - sum, ldk[i].se);
                 sum += val;
                ldk[i].se -= val;
                if (ldk[i].se == 0) i++;
            }
            ans += 2 * p;
        }
        else
        {
            ans += ldk[i].se/k*2LL*ldk[i].fi;
            ldk[i].se %= k;
            if (ldk[i].se == 0) i++;
        }     
    }
    return ans;
}
void solve()
{   
    int k, n;
    vector<pair<int,int> > pos, neg;
    int mxval = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> x[i] >> val;
        if (x[i] > 0)
        pos.pb({x[i], val}), mxval = max(mxval, x[i]);
        if (x[i] < 0)
        neg.pb({-x[i], val}), mxval = max(mxval, -x[i]);
    }
    cout << cal(pos, k) + cal(neg, k) << "\n";
}
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    // 
    #endif
    //freopen("dienbien.inp","r",stdin); freopen("dienbien.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}