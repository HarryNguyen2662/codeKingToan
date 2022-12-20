#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6;
const int oo = 1e9;
long long c[6];
bool tg(long long x, long long y, long long z)
{
    return (x+y>z&&x+z>y&&y+z>x);
}

    
bool check()
{
    long long c[6];
    
    for (int i = 0 ;i < 6; i++) cin >> c[i];
    sort(c, c+6);
    do
    {
    long long x =c[3]*c[4]*c[5];
    long long y = c[3]*c[3]+c[4]*c[4] -c[2]*c[2];
    long long z = c[4]*c[4]+c[5]*c[5]-c[0]*c[0];
    long long t = c[3]*c[3]+c[5]*c[5]-c[1]*c[1];
    long long tgV= y*z*t+4*x*x-c[3]*c[3]*z*z-c[4]*c[4]*t*t-c[5]*c[5]*y*y;
        if (tg(c[0],c[1],c[2])&&tg(c[0],c[4],c[5])&&tg(c[1],c[3],c[5])&&tg(c[2],c[3],c[4])&&tgV >0) return true;
    }
    while(next_permutation(c, c + 6));
    return false;
}
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("hellodking.txt","r",stdin);
    #else
    // online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        if (check()) cout <<"Yes"<<endl; else cout << "No"<<endl;
    }
}