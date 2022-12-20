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
const int lim = 1e6 + 2;;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 922372036854775807;
struct DATA
{
    int ver1, w, ver2;
} luu[100005];
int n, k, x;
int undo(int u)
{
    for (int i = x; i; i--)
    {
        int l, r;
        if (luu[i].ver2 == n+1) 
        {
            r = n; l = n - luu[i].w + 1;
            //cout << luu[i].w << endl;
           // cout << l << " "  <<r << " " << u << endl;
            if (u >= l && u <= r)
            {
                u = luu[i].ver1 + u - l;
            }
            else if (u >= luu[i].ver1 && u < l) u += luu[i].w;
            continue;
        }
        if (luu[i].ver2 < luu[i].ver1) 
        {
            l = luu[i].ver2; r = l + luu[i].w -1;
            //cout << l << " " << r << " " << u << endl;
            if (u >= l && u <= r)
            {
                u = luu[i].ver1 + u - l;
            }
            else if (u > r && u <= luu[i].ver1 + luu[i].w -1) u -= luu[i].w;
        }
        else if (luu[i].ver2 > luu[i].ver1)
        {
            r = luu[i].ver2 - 1; l = r - luu[i].w + 1;
            //cout << l << " " << r << " " << u << endl;
            if (u >= l && u <= r)
            {
                u = luu[i].ver1 + u - l;
            }
            else if (u < l && u >= luu[i].ver1) u += luu[i].w;
        }
        //cout << u << endl;
    }
    return u;
}
void solve()
{
    cin >> n >> k >> x;
    for (int i = 1; i <= x; i++)
    {
        int u, v, kc;
        cin >> u >> kc >> v;
        if (v >= u) v += kc;
        luu[i] = {u , kc, v};
    }   
    //cout << undo(3);
    for (int i = 1; i <= k; i++)
    {

        cout << undo(i) << " ";
    }
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
