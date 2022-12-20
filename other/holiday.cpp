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
inline int ReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    int x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    return x;
}
void WriteInt(int x)
{
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
int n, a[100005];
long long cal(int st, int d, int h)
{
    if (d <= 0) return 0;
    int lim;
    if (h == 1) lim = n + 1; else lim = 0;
    long long res = a[st];
    long long cur = a[st];
    long long layra = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(a[st]);
    d--; 
    int ned = 1;
    for (int i = st + h; i != lim; i += h)
    {
        while(d < ned + 1 && !pq.empty())
        {
            int val = pq.top();
            layra += val;
            pq.pop();
            d++;
        }
        if (d >= ned + 1)
        {
            cur -= layra; layra = 0;
            cur += a[i]; pq.push(a[i]);
            res = max(res, cur);
            d -= (ned + 1);
            ned = 0;
        }
        ned ++;
    }
    return res;
}
void solve()
{
    int st, d;
    cin >> n >> st >> d;
    st++;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (st == 1)
    {
        cout << cal(st, d, 1);
        return;
    }
    long long res = cal(st, d, 1);
    for (int i = 1; i < st ; i++) res = max(res, cal(i, d - (st - i), 1));
    for (int i = st; i <= n; i++) res = max(res, cal(i, d - (i - st), -1));
    cout << res;
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
