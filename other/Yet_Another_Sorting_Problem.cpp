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
int n;
long long fw[500005];
int a[500005], aa[500005];
void uptree(int id, int vl)
{
    for (; id <= n; id = (id | (id+1)))
        fw[id] +=vl;
}
int sum(int id)
{
    int res = 0;
    for (; id >= 0;  id = (id & (id+1)) - 1)
        res += fw[id];
    return res;
}
int ldk[500005];
long long cal()
{
    long long res =0 ;
    for (int i = 0; i <= n; i++) fw[i] = 0, ldk[i] = 0;
    for (int i = 0; i < n; i++)
        ldk[a[i]] = i;
    for (int i = 0; i < n; i++)
    {
        int x = ldk[aa[i]]; 
        res += x + sum(x) - i;
       uptree(0,1); uptree(x+1,-1);
    }
    return res;
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        aa[i] = a[i];
    }
    if (n == 1)
    {
        cout << "YES\n";
        return;
    }
    if (n == 2)
    {
        if (a[0] <= a[1])
        {
            cout << "YES\n";
        }
        else cout << "NO\n";
        return;
    }
    sort(aa, aa + n);
    for (int i = 1; i < n; i++) if (aa[i] == aa[i-1])
    {
        cout << "YES\n";
        return;
    }
    if (cal()%2 == 0) cout << "YES\n"; else cout << "NO\n";
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
    cin >> testcase;
    while(testcase--)
        solve();
}
