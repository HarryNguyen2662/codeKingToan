#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e6 + 3;
const int MAXN = 1e6;
const int oo = 1e9;
long long a[500050];
int x,y,d;
void ldk(int n, int m)
{
    if(m == 0)
    {
        d = n; x= 1; y = 0; return;
    }
    ldk(m,n%m);
    int t = x; x= y; y = t- n/m*y;
}
map<int,int> dem;
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("yeunhi.txt","r",stdin);
    #else
    // online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long p;
    long long dem1=0,dem2=0;
    cin >> n >> p;
    for (int i = 1;i <= n; i++)
    { 
        cin >> a[i];
        a[i] = ((a[i]-1)%p+p)%p;
        dem[a[i]]++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ldk(a[i],p);
        if(d!=1) continue;
        x = ((x%p)+p)%p;
       // cout <<i<<" "<< x << endl;
        long long  mm = dem[x];
        if(a[i]==x) ans += (mm-1); else ans +=mm;
    }
    cout << ans/2;
}