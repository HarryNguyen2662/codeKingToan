#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 17
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1 << (i))
#define ck(n, i) (((n) >> (i))&1) 
#define setp(x) setprecision(x)
#define NMOD 3
const double PI = acos(-1);
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789; 
const int lim = 125250;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 9223372036854775807;
long long c[100005];
void solve()
{   
    int n;
    long long l, r;
    //cout << oooo << endl;
    cin >> n >> l >> r;
    unsigned long long kc1, kc2;
    for (int i = 1; i <= n; i++) 
    {
        cin >> c[i];
        unsigned long long dist;
        if (l < c[i]) dist = c[i] - l; else dist = l - c[i];
        if (i == 1) kc1 = dist ; else kc1 = min(kc1, dist);
        if (r < c[i]) dist = c[i] - r; else dist = r - c[i];
        if (i == 1) kc2 = dist; else kc2 = min(kc2, dist);
    }
    sort(c + 1, c + 1 + n);
    unsigned long long kc3 = 0;
    long long id = -oooo;  
    for (int i = 1; i < n; i++)
    {
        long long center = c[i+1] - (long long)((unsigned long long)(c[i+1] - c[i])/2);
        if (center < l || center > r) continue;
        unsigned long long dist = c[i+1] - center;
        if (dist > kc3)
        {
            kc3 = dist; id = center;
        } else if (dist == kc3 && id < center)
        {
            id = center;
        }

    }
    if (kc1 > kc3)
    {
        kc3 = kc1; id = l;
    } else if (kc1 == kc3 && id < l) id = l;
    if (kc2 > kc3)
    {
        id = r;
    } else if (kc3 == kc2 && id < r) id = r;
    cout << id;
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
    solve();
}
