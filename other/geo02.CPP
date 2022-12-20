#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const long long MOD = 1e9 + 7;
int xx[4] = {0,0,-1,1};
int yy[4]= {-1,1,0,0};
const double PI =  3.14159265358979;   
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
    double x,y,fb,fd,fe,apa,res,r;
    cin >> x >> y;
    fb = sqrt(y*y - x*x);
    fd =  y -x;
    fe = fd*fd/fb;
    r = (fb-fe)/2;  
    //cout << r <<endl;
   // cout << apa << endl;
    res = fb*x/2-r*x-r*r*(PI-2*atan(x/r) )/2;
    cout<< fixed<< setprecision(10) << res;
}