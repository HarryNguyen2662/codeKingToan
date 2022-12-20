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
int a[100005], b[100005];
int n, m;
bool check(int val)
{
    int l = 1, r = m - val + 1;
    int dem = 0;
    for (int i = 1; i <= n; i++)
    if (a[i] > b[l] && a[i] < b[r])
    {
        l++; r++;
        dem++;
        if (dem == val) return true;
    }
    return false;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= m; j++) cin >> b[j];
    sort(a + 1, a + 1 + n); sort(b + 1, b + 1 + m);
    int l = 1, r = min(m/2, n);
    while(l <= r)
    {
        int mid = (l + r)/2;
        if (check(mid)) l = mid + 1; else r = mid - 1;
    }
    cout << r;
}
int main()
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // // 
    // #endif
    //freopen("ball.inp","r",stdin); freopen("ball.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
