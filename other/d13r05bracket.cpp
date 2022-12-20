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
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789; 
const int lim = 125250;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 922372036854775807;
int a[100005];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
    }
    priority_queue<int, vector<int>, greater<int> > q, s;
    long long res = 0;
    q.push(oo+5); s.push(a[n]); s.push(oo + 5);
    for (int i = n - 1; i; i--)
    {
        int val = s.top();
        int va = q.top();
        //cout << a[i] << " " << val << " " << va << endl; 
        if (val < a[i])
        {
            if (va < val)
            {
                res += (a[i] - va);
                q.pop(); s.push(va);  
            }
            else
            {
                res +=(a[i] - val);
                s.pop();
            }
            q.push(a[i]);
        }
        else if (a[i] >= va)
        {
            q.pop(); s.push(va);
            res += (a[i] - va);
            q.push(a[i]);
        }
        else s.push(a[i]);
    }
    cout << res;
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
