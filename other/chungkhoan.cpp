#include<bits/stdc++.h>
using namespace std;
#define ALL(v) v.begin(), v.end()
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
inline int ReadInt()
{
    char c;
    bool negative = false;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') negative = true;
    long long x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (negative) return -x; else return x;
}
void WriteInt(long long x)
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
vector<pair<int,int>> typeA, typeB;
long long sumA[200005], sumB[200005];
void solve()
{
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char type;
        int val, val1;
        cin >> type >> val >> val1;
        //cout << type << " "<< val << " " << val1 << endl;
        if (type == 'A') typeA.pb({val, val1});
        else typeB.pb({val, val1});
    }
    typeA.pb({-oo-1, 0}); typeA.pb({oo-1, 0});
    typeB.pb({-oo+1, 0}); typeB.pb({oo+1, 0});
    sort(ALL(typeA)); sort(ALL(typeB));
    n = (int)typeA.size(); m = (int)typeB.size();
   // cout << n << " " << m << endl;
    for (int i = 1; i <= n; i++) sumA[i] = sumA[i-1] + typeA[i-1].se;
    for (int j = 1; j <= m; j++) sumB[j] = sumB[j-1] + typeB[j-1].se;
    int l = 1;
    long long res = -oo15;
    int luu = -oo-5;
    for (int i = 1; i <= n; i++)
    {
       // cout << typeA[i-1].fi << " " << typeA[i-1].se << endl;
        if ( (i != n && typeA[i-1].fi == typeA[i].fi) || typeA[i-1].fi == oo) continue;
        while(l < m && typeB[l-1].fi <= typeA[i-1].fi + 1) l++;
        long long val = 2*sumA[i] - sumA[n];
        if (typeB[l-1].fi <= typeA[i-1].fi) val -= sumB[m];
        else val = val - 2*sumB[l-1] + sumB[m];
        //cout << val << " " << l << " " << i << endl;
        if (val >  res)
        {
            res = val;
            luu = typeA[i-1].fi + 1;
        }
    }
    l = n;
    for (int i = m; i >= 1; i--)
    {
        if ((i != 1 && typeB[i-1].fi != typeB[i-2].fi)|| typeB[i-1].fi == -oo) continue;
        while(l > 1 && typeA[l - 1].fi >= typeB[i-1].fi - 1) l--;
        long long val = sumB[m] - 2*sumB[i-1];
        if (typeB[l-1].fi >= typeA[i-1].fi) val -= sumA[n];
        else val = val + 2*sumA[l] - sumA[n];
        if (val > res)
        {
            res = val;
            luu = typeB[i-1].fi - 1;
        } else if (res == val && luu > typeB[i-1].fi - 1) luu = typeB[i-1].fi - 1;
    }
    cout << luu << " " << res;
}
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
