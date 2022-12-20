#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
int xx[4] = {0,0,-1,1};
int yy[4]= {-1,1,0,0};
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
    double x;
    cin >> x;
    double res= (4+2*sqrt(2))*x;
    cout<< fixed<< setprecision(10) << res;
}