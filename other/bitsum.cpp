#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 18
#define mask(i) (1 << (i))
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6+5;
const int oo = 2e9;
long long dem(long long x, int y = 53, long long m = 9007199254740992)
{
    if(x == 0) return 0;
    while(m > x) 
    {
      y--;
      m=m/2;
    }
    //cout << m << endl;
    if (x == m*2 - 1) return (y+1)*m;
    x = x - m;
    return x+1 + y*(m/2) + dem(x,y-1,m/2);
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    #else
    //online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    long long l, r;
    cin >> t;
    while(t--)
    {
      cin >> l >> r;
      cout << dem(r) - dem(l-1)<<"\n";
    }
}