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
int pre[100005], suf[100005];
int de[500], dd[500];
void solve()
{
    string s;
    cin >> s;
    int n = (int)s.size();
    for (int i = 'a'; i <= 'z'; i++) dd[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = dd[s[i-1]];
        dd[s[i-1]] = i;
    }
    for (int i = 'a'; i <= 'z'; i++) de[i] = n+1;
    for (int i = n; i; i--)
    {
        suf[i] = de[s[i-1]];
        de[s[i-1]] = i;
    }
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = suf[i] - i, y = i - pre[i];
        res += 1ll*x*y;
    }
    cout << res << "\n";
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